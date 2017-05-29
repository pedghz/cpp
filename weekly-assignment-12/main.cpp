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
       bool pop_front();

       // Print the elements stored in the stack on top to bottom
       // order.  This method is mainly for testing purposes.
       void print() const;

     private:
       int size;
       int* d_array;
   };

Stack::Stack() {
    d_array= new int[1];
    size = 0;
}

Stack::~Stack() {
   delete[] d_array;
}

bool Stack::empty() const {
    return size == 0;
}

void Stack::push_front(int new_value) {
    d_array[size] = new_value;
    size++;
}

bool Stack::pop_front() {
    if (size == 0)
        return false;
    size--;
    return true;
}

void Stack::print() const {
    for(int i=size; i!=0 ; i--)
        cout << "**  " << d_array[i-1] << "  **" << endl;
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
    numbers.pop_front();

    numbers.print();
}
