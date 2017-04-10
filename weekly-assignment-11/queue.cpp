#include "queue.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Queue::Queue(): first_ptr_(nullptr), last_ptr_(nullptr) {}

void
Queue::add_to_end(const string& new_patient_name) {
    shared_ptr<Cell> new_address(new Cell);

    new_address->patient_name = new_patient_name;
    new_address->next_ptr = nullptr;

    if ( is_empty() ) {
        first_ptr_ = new_address;
        last_ptr_ = new_address;
        new_address->prev_ptr = nullptr;
    } else {
        last_ptr_->next_ptr = new_address;
        new_address->prev_ptr = last_ptr_.get();
        last_ptr_ = new_address;
    }
}

bool Queue::remove_from_front(string& removed_patient_name) {
    if ( is_empty() ) {
        return false;
    }

    shared_ptr<Cell> delete_ptr = first_ptr_;

    removed_patient_name = delete_ptr->patient_name;

    if ( first_ptr_ == last_ptr_ ) {
        first_ptr_ = nullptr;
        last_ptr_ = nullptr;
    } else {
        first_ptr_ = first_ptr_->next_ptr;
        first_ptr_->prev_ptr = nullptr;
    }

    return true;
}

bool
Queue::is_empty() const {
    if ( first_ptr_ == nullptr ) {
        return true;
    } else {
        return false;
    }
}

void
Queue::print() const {
    shared_ptr<Cell> print_ptr = first_ptr_;
    int running_number = 1;

    while ( print_ptr != nullptr ) {
        cout << running_number << ". "
             << print_ptr->patient_name << endl;
        ++running_number;
        print_ptr = print_ptr->next_ptr;
    }
}
bool Queue::remove(string patient_name) {
    if ( is_empty() ) {
        //        cout << "The queue is empty." << end;
    }
    else
    {
        shared_ptr<Cell> remove_ptr = first_ptr_;

        if(remove_ptr->patient_name == patient_name && first_ptr_ == last_ptr_) {
            remove_ptr = nullptr;
            first_ptr_ = nullptr;
            last_ptr_ = nullptr;
            cout << "Patient deleted: " << patient_name << endl;
            return true;
        } else if (remove_ptr->patient_name == patient_name && first_ptr_ != last_ptr_) {
            first_ptr_ = remove_ptr->next_ptr;
            first_ptr_->prev_ptr = nullptr;
            remove_ptr = first_ptr_;
            cout << "Patient deleted: " << patient_name << endl;
            return true;
        }

        while(remove_ptr != last_ptr_)
        {
            if (patient_name == remove_ptr->patient_name && remove_ptr != first_ptr_) {
                (remove_ptr->prev_ptr)->next_ptr = remove_ptr->next_ptr;
                (remove_ptr->next_ptr)->prev_ptr = remove_ptr->prev_ptr;
                remove_ptr = remove_ptr->next_ptr;
                cout << "Patient deleted: " << patient_name << endl;
                return true;
            } else if(patient_name != remove_ptr->patient_name) {
                remove_ptr = remove_ptr->next_ptr;
            }
        }

        if (remove_ptr->patient_name == patient_name ) {
            (remove_ptr->prev_ptr)->next_ptr = nullptr;
            last_ptr_ = nullptr;
            cout << "Patient deleted: " << patient_name << endl;
            return true;
        }

        cout << "This patient does not exist: " << patient_name << endl;
        return false;
    }
}
