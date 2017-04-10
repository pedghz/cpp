// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#include "marketclass.h"

bool readFile_PutToDatastructure(Market &markets) {

    double double_price;
    string chain, branch, product, price;

    //    File reading and handling the error if we could not make reading it
    ifstream file("products.txt");
    if ( not file ) {
        cout << "Error: Cannot read file" << endl ;
        return false;
    }
    while(getline(file, chain, ';'))
    {
        getline(file, branch, ';') ;
        getline(file, product, ';') ;
        getline(file, price, '\n') ;
        double_price = stod (price, nullptr) ;
        markets.add_product(chain, branch, product, double_price);
    }

    //    Closing the file
    file.close();

    return true;
}

