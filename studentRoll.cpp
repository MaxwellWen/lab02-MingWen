//MingWen 5961578
#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *temp = new Node;
  temp->s = new Student(s);
  temp->next = NULL;
  if(tail == NULL){
	  head = tail = temp;
}else{
	tail->next = temp;
	tail = temp;
}
}


std::string StudentRoll::toString() const {
	std::string x;
	x.append("[");
	for(Node* temp = head; temp != NULL; temp=temp->next){
		Student current(*(temp->s));
		x.append(current.toString());
		if(temp->next != NULL){
			x.append(",");
		}
	}
	x.append("]");
	return x;
}


StudentRoll::StudentRoll(const StudentRoll &orig) {
  this-> head = NULL;
  this-> tail = NULL;
  for(Node* temp = orig.head; temp; temp = temp->next){
	  this->insertAtTail(*(temp->s));
  }
}

StudentRoll::~StudentRoll() {
  Node *current = head;
  while(current != 0){
	  Node *next = current->next;
	  delete current->s;
	  delete current;
	  current = next;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  Node *r = right.head;
  while(r){
	  this->insertAtTail(*(r->s));
	  r = r->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





