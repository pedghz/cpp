#include <iostream>
#include "queue.h"

using namespace std;


int main() {
    Queue patients;

    patients.add_to_end("Jack");
    patients.add_to_end("Jill");
    patients.add_to_end("Ann");
    patients.add_to_end("Bill");

    patients.print();
    patients.remove("Ann");
    patients.print();
}
