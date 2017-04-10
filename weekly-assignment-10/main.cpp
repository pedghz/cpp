#include <iostream>

using namespace std;

class Stack {
     public:
       Stack();
       ~Stack();

       // empty will only return true, if there are no elements
       // in the stack i.e. the linked  list is empty.
       bool empty() const;

       // push_front will insert the new_value on top of the stack
       // i.e. in front of the linked list.
       void push_front(int new_value);


       // pop_front will remove the topmost value from the stack
       // i.e. the first element of the linked list.  The removed
       // value will be stored into removed_value and the return
       // value will be true if the removal of an element is successfull.
       // If not (i.e. the stack is empty), return value is false.
       bool pop_front(int& removed_value);

       // Print the elements stored in the stack on top to bottom
       // order.  This method is mainly for testing purposes.
       void print() const;

     private:
       struct Cell {
           int data;
           Cell* next_ptr;
       };

       Cell* first_ptr;
   };

Stack::Stack(): first_ptr{nullptr} {
}

Stack::~Stack() {
   while ( first_ptr != nullptr ) {
      Cell* remove_ptr = first_ptr;
      first_ptr = first_ptr->next_ptr;

      delete remove_ptr;
   }
}

bool Stack::empty() const {
    return first_ptr == nullptr;
}

void Stack::push_front(int new_value) {
    Cell *new_cell_ptr = new Cell;

    new_cell_ptr->data = new_value;
    if ( first_ptr != nullptr )
    {
        new_cell_ptr->next_ptr = first_ptr;
    } else
    {
        new_cell_ptr->next_ptr = nullptr;
    }
    first_ptr = new_cell_ptr;
}

bool Stack::pop_front(int& removed_value) {

   if ( empty() ) {
      return false;
   }

   Cell *remove_ptr = first_ptr;
   removed_value = remove_ptr->data;

   if ( first_ptr->next_ptr == nullptr && first_ptr != nullptr )
   {
      first_ptr = nullptr;
   } else
   {
      first_ptr = first_ptr->next_ptr;
   }

   delete remove_ptr;
   return true;
}

void Stack::print() const {
   Cell *print_ptr = first_ptr;

   while ( print_ptr != nullptr ) {
      cout << "**  " << print_ptr->data << "  **" << endl;
      print_ptr = print_ptr->next_ptr;
   }
}



int main()
{
    Stack numbers;

    numbers.push_front(1);
    numbers.push_front(2);
    numbers.push_front(3);
    numbers.push_front(4);
    numbers.push_front(5);
    numbers.push_front(6);
    numbers.push_front(7);
    numbers.push_front(8);

    numbers.print();
}
