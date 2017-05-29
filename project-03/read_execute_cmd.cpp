// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#include "header.hh"

void read_execute_cmd(Queue& chores)
{
    string line;
    regex reg_init("([-+]?)([[:digit:]]+)");
    string::size_type pos;
    int num = 0;
    while(true)
    {
        cout << "chores> " ;
        getline(cin, line) ;
        pos = line.find(' ');
        if (pos == string::npos)
        {
            if (line == "quit")
            {
                chores.remove_all();
                break;
            }
            else if (line == "print" && num != 0)
            {
                chores.print(num);
            }
            else if (line == "next" && num != 0)
            {
                chores.next();
            }
            else if (line == "init")
                cout << "Error: the number of priority levels is missing." << endl;
            else if (line == "add" && num != 0)
                cout << "Error: priority level and chore description are missing." << endl;
            else if (line == "erase" && num != 0)
                cout << "Error: the running number is missing." << endl;
            else if ((line == "print" || line == "next" || line == "add" || line == "erase") && num == 0)
                cout << "Error: the number of chores is not initialized yet." << endl;
            else
                cout << "Error: unknown command, please try again." << endl;
        } else
        {
            string command_part_one;
            string command_part_two;
            command_part_one = line.substr(0, pos);
            line = line.substr(pos + 1);
            if (command_part_one == "quit")
            {
                chores.remove_all();
                break;
            }
            else if(command_part_one == "init")
            {
                if (line.size() == 0)
                {
                    cout << "Error: the number of priority levels is missing." << endl;
                    continue;
                }
                if (regex_match (line,reg_init) && stoi(line) > 0)
                {
                    command_part_two = line;
                    chores.remove_all();
                    num = stoi(line);
                    cout << "New priority list with levels 1-"<< num <<" initialized." << endl;
                }
                else if (regex_match (line,reg_init) && stoi(line) <= 0)
                    cout << "Error: it is not possible to create a priority list with 0 or less levels." << endl;
                else
                {
                    cout << "Error: the number of priority levels must be an integer larger than 0." << endl;
                }
            }
            else if(command_part_one == "add" && num != 0)
            {
                if (line.size() == 0)
                {
                    cout << "Error: priority level and chore description are missing." << endl;
                    continue;
                }
                pos = line.find(' ');
                if (pos == string::npos)
                {
                    if (line.size() == 0)
                    {
                        cout << "Error: chore description is missing." << endl;
                        continue;
                    }
                    if (regex_match (line,reg_init) && stoi(line) > 0 && stoi(line) <= num)
                    {
                        cout << "Error: chore description is missing." << endl;
                        continue;
                    } else
                    {
                        cout << "Error: priority level must be an integer between 1-" << num << "." << endl;
                    }
                }
                else
                {
                    command_part_two = line.substr(0, pos);
                    line = line.substr(pos + 1);
                    if (regex_match (command_part_two,reg_init) && stod(command_part_two) > 0 && stod(command_part_two) <= num)
                    {
                        if (line.size() == 0)
                        {
                            cout << "Error: chore description is missing." << endl;
                            continue;
                        } else
                        {
                            chores.add_to_end(command_part_two, line);
                        }
                    } else
                    {
                        cout << "Error: priority level must be an integer between 1-" << num << "." << endl;
                    }
                }
            }
            else if(command_part_one == "erase" && num != 0)
            {
                if (line.size() == 0)
                {
                    cout << "Error: the running number is missing." << endl;
                    continue;
                }
                if (regex_match (line,reg_init) && stoi(line) > 0)
                {
                    if (!chores.erase(line, num))
                        cout << "Error: there is no such chore." << endl;
                }
                else if (regex_match (line,reg_init) && stoi(line) <= 0)
                    cout << "Error: the running number must be larger than 0." << endl;
                else
                    cout << "Error: the running number must be an integer larger than 0." << endl;
            }
            else if(command_part_one == "print" && num != 0)
                cout << "Error: extra text after print command." << endl;
            else if(command_part_one == "next" && num != 0)
                cout << "Error: extra text after next command." << endl;
            else if ((command_part_one == "print" || command_part_one == "next" || command_part_one == "add" || command_part_one == "erase") && num == 0)
                cout << "Error: the number of chores is not initialized yet." << endl;
            else
                cout << "Error: unknown command, please try again." << endl;
        }
    }
}

