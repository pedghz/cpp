// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#include "marketclass.h"

bool read_commands(Market &markets)
{
    string str;
    while(true) {
        cout << "product search> " ;
        getline(cin, str) ;
        istringstream str_stream(str);
        vector<std::string> v_strings{ istream_iterator<string> {str_stream}, istream_iterator<string> {} };
        if (v_strings.size() == 1 && v_strings[0] == "quit")
            return false;
        else if(v_strings.size() == 1 && v_strings[0] == "all") {
            markets.print_all();
        }
        else if(v_strings.size() == 1 && v_strings[0] == "chains") {
            markets.print_chains();
        }
        else if(v_strings.size() == 2 && v_strings[0] == "stores") {
            markets.print_stores(v_strings[1]);
        }
        else if(v_strings.size() == 2 && v_strings[0] == "cheapest") {
            markets.print_cheapest(v_strings[1]);
        }
        else if(v_strings.size() == 3 && v_strings[0] == "selection") {
            markets.print_selection(v_strings[1], v_strings[2]);
        } else {
            cout << "Error: Unknown command, try again!" << endl;
        }
    }
}
