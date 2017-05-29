// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#include "header.hh"
#include <memory>

Queue::Queue(): first_ptr_(nullptr), last_ptr_(nullptr) {}

void Queue::remove_all()
{
    first_ptr_ = nullptr;
    last_ptr_ = nullptr;
}

void Queue::add_to_end(const string& chore_priority, const string& chore_discription)
{
    shared_ptr<Chore> new_address(new Chore);
    new_address->chore_priority = chore_priority;
    new_address->chore_discription = chore_discription;
    new_address->next_ptr = nullptr;

    if ( is_empty() ) {
        first_ptr_ = new_address;
        last_ptr_ = new_address.get();
        new_address->prev_ptr = nullptr;
    }
    else {
        last_ptr_->next_ptr = new_address;
        new_address->prev_ptr = last_ptr_;
        last_ptr_ = new_address.get();
    }
    cout << "New chore added to priority level " << chore_priority << "." << endl;
}

void Queue::next()
{
    if ( is_empty() )
    {
        cout << "--- no chores left ---" << endl;
    }
    else
    {
        if ( first_ptr_->next_ptr == nullptr ) {
            cout << first_ptr_->chore_discription << endl;
            first_ptr_ = nullptr;
            last_ptr_ = nullptr;
        }
        else {
            string tmp_priority = "1";
            shared_ptr<Chore> tmp_ptr = first_ptr_;
            int counter_num = 0;
            int removing_num = 0;
            while(tmp_ptr != nullptr)
            {
                counter_num++;
                if(stoi(tmp_ptr->chore_priority) > stoi(tmp_priority))
                {
                    tmp_priority = tmp_ptr->chore_priority;
                    removing_num = counter_num;
                }
                tmp_ptr = tmp_ptr->next_ptr;
            }
            tmp_ptr = first_ptr_;
            counter_num = 1;
            while(true)
            {
                if (removing_num == counter_num)
                {
                    cout << tmp_ptr->chore_discription << endl;
                    if (tmp_ptr->next_ptr != nullptr)
                        tmp_ptr->next_ptr->prev_ptr = tmp_ptr->prev_ptr;
                    else
                        last_ptr_ = tmp_ptr->prev_ptr;
                    if (tmp_ptr->prev_ptr != nullptr)
                        tmp_ptr->prev_ptr->next_ptr = tmp_ptr->next_ptr;
                    else
                        first_ptr_ = tmp_ptr->next_ptr;
                    break;
                }
                else
                {
                    tmp_ptr = tmp_ptr->next_ptr;
                    counter_num++;
                }
            }
        }
    }
}

bool Queue::is_empty() const {
    if ( first_ptr_ == nullptr ) {
        return true;
    } else {
        return false;
    }
}

void Queue::print(int chores_number) const {
    if ( !is_empty() )
    {
        shared_ptr<Chore> print_ptr = first_ptr_;
        int running_number = chores_number;
        bool found = false;
        int task_number = 1;
        if (first_ptr_->next_ptr != nullptr)
        {
            // finding the tasks in their priority order and printing them.
            for(int i=0; i!=chores_number; i++)
            {
                while(print_ptr != nullptr)
                {
                    if (stoi(print_ptr->chore_priority) == running_number)
                    {
                        if (found == false)
                        {
                            cout << "Priority level " << running_number << ":" << endl;
                            cout << "  " << task_number << "." << " " << print_ptr->chore_discription << endl;
                            task_number++;
                            found = true;
                        }
                        else
                        {
                            cout << "  " << task_number << "." << " " << print_ptr->chore_discription << endl;
                            task_number++;
                        }
                    }
                    print_ptr = print_ptr->next_ptr;
                }
                found = false;
                print_ptr = first_ptr_;
                running_number--;
            }
        }
        else
        {
            cout << "Priority level " << first_ptr_->chore_priority << ":" << endl;
            cout << "  1. " << first_ptr_->chore_discription << endl;
        }
    }
}

bool Queue::erase(string task_num, int chores_number)
{
    int remove_task = stoi(task_num);
    if ( !is_empty() )
    {
        shared_ptr<Chore> tmp_ptr = first_ptr_;
        int running_number = chores_number;
        int task_number = 0;
        if (first_ptr_->next_ptr != nullptr)
        {
            // find the task with given task number
            for(int i=0; i!=chores_number; i++)
            {
                while(tmp_ptr != nullptr)
                {
                    if (stoi(tmp_ptr->chore_priority) == running_number)
                    {
                        task_number++;
                    }
                    // if the task number is found delete the correspoding task.
                    if (task_number == remove_task)
                    {
                        if (tmp_ptr->next_ptr != nullptr)
                            tmp_ptr->next_ptr->prev_ptr = tmp_ptr->prev_ptr;
                        else
                            last_ptr_ = tmp_ptr->prev_ptr;
                        if (tmp_ptr->prev_ptr != nullptr)
                            tmp_ptr->prev_ptr->next_ptr = tmp_ptr->next_ptr;
                        else
                            first_ptr_ = tmp_ptr->next_ptr;
                        return true;
                    }
                    tmp_ptr = tmp_ptr->next_ptr;
                }
                tmp_ptr = first_ptr_;
                running_number--;
            }
            return false;
        }
        else
        {
            if (remove_task == 1)
            {
                first_ptr_ = nullptr;
                last_ptr_ = nullptr;
                return true;
            }
            else
                return false;
        }
    }
    else
        return false;
}
