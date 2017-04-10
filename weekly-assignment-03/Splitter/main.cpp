#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// unsigned int is a type you can use to store and manipulate
// natural numbers (ℕ) in C++ programs.  In other words
// whole numbers that are ≥ 0.
const unsigned int SPLIT_ERROR = 0;

class Splitter {
     public:
          Splitter(const string& string_to_split = "");

          void set_string_to_split(const string& string_to_split);

          unsigned int split(char separator, bool ignore_empty = false);   // ????????????? what is ignore_empty??????????

          unsigned int number_of_fields() const;

          string fetch_field(unsigned int field_index) const;

      private:
        string string_to_split_;
        vector<string> splitted_string_;
        int called_;
        int size_;
};

Splitter::Splitter(const string& string_to_split):
    string_to_split_(string_to_split) {
    this->called_ = -1;
    this->size_ = -1;
}

unsigned int Splitter::split(char separator, bool ignore_empty) {
    string str = this->string_to_split_;
    this->called_ = 1;
    int following_separator = 0;
    for (int i=0; i < str.length(); i++) {
        if (str.length() > 1)
            if (str.find(separator) == 0) {
                str = str.substr(1,str.length() - 1);
                i=0;
                if (following_separator == 1 && ignore_empty == 0)
                    splitted_string_.push_back("");
                following_separator = 1;
            } else {
                if (str.find(separator) != string::npos)  {
                    splitted_string_.push_back(str.substr(0,str.find(separator)));
                    str = str.substr(str.find(separator),str.length()-1);
                    following_separator = 0;
                } else {
                    splitted_string_.push_back(str);
                    str = "";
                    following_separator = 0;
                }
                i=0;
            }
        }
    if(str.length() == 1 && str[0] != separator )
        splitted_string_.push_back(str);
    if(str.length() == 1 && str[0] == separator && following_separator == 1 && ignore_empty == 0)
        splitted_string_.push_back("");
    this->size_ = splitted_string_.size();
    return this->size_;
}

void Splitter::set_string_to_split(const string& string_to_split) {
    vector<string>().swap(splitted_string_);
    string_to_split_ = string_to_split;
}

unsigned int Splitter::number_of_fields() const{
    if (called_ == -1)
        return SPLIT_ERROR;
    else
        return this->size_;
}

string Splitter::fetch_field(unsigned int field_index) const {
    if (field_index >= (splitted_string_.size() ) || (this->called_ == -1) )
        throw out_of_range("too large index or split not called");
    else
        return splitted_string_.at(field_index);
}

int main()
{
     Splitter splitter_object("a::bc:def::hijlkm");

     int a = splitter_object.split(':');  // Observe: single quotes: parameter is of type char.


     cout << "fields: " << a << endl;  // 6   // I dont get what the boolean does! And I think I just split like the boolean variable is always True.

//     cout << splitter_object.fetch_field(0) << endl;  // a
//     cout << splitter_object.fetch_field(4) << endl;  // (empty)
//     cout << splitter_object.fetch_field(5) << endl;  // hijlkm

     for ( unsigned int i = 0; i < splitter_object.number_of_fields(); ++i ) {
         string current_field_contents = splitter_object.fetch_field(i);
         cout << i << ": [" << current_field_contents << "]" << endl;
     }

     splitter_object.set_string_to_split(" A B  C   D    E     ");
     unsigned int fields = splitter_object.split(' ', true);

     cout << "fields: " << fields << endl;  // 5

     for ( unsigned int i = 0; i < fields; ++i ) {
         string current_field_contents = splitter_object.fetch_field(i);
         cout << i << ": [" << current_field_contents << "]" << endl;
     }

     cout << splitter_object.fetch_field(10) << endl;  // out_of_range exception
    return 0;
}
