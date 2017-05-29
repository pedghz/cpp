// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>

using namespace std;

class Queue {
public:
    Queue();

    // removes all the tasks in the queue.
    void remove_all();

    // adds one task to the end of queue.
    void add_to_end(const string& chore_priority, const string& chore_discription);

    // finds the next task that should be done and prints it and deletes it from the queue.
    void next();

    // checks if the queue is empty or not.
    bool is_empty() const;

    // prints all the tasks in the queue in order due to thier priority.
    void print(int chores_number) const;

    // erases a given task number from the queue and returns a bool value showing
    // the erase was successful or not so the related message can be printed on screen.
    bool erase(string task,int chores_number);

private:
    struct Chore {
        string chore_priority;
        string chore_discription;
        shared_ptr<Chore> next_ptr;
        Chore* prev_ptr;
    };

    shared_ptr<Chore> first_ptr_;
    Chore* last_ptr_;
};

// the function that reads one command and executes the corresponding function
// from the public interface of the Queue.
void read_execute_cmd(Queue& chores);

#endif // HEADER_H
