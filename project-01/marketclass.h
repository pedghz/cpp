// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#ifndef MARKETCLASS_H
#define MARKETCLASS_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iomanip>

using namespace std;

using Product = map<string, double>;
using Stores = map<string, Product>;
using Chains = map<string, Stores>;

// Creating the class
class Market {
  public:
    Market();
    void add_product(const string& chain, const string& branch, const string& product, double price);
    void print_selection(const string& chain, const string& store);
    void print_cheapest(const string& desired_product);
    void print_stores(const string& chain);
    void print_chains();
    void print_all();

  private:
    Chains list_of_chains_;
};

bool readFile_PutToDatastructure(Market& markets);
bool read_commands(Market& markets);

#endif // MARKETCLASS_H
