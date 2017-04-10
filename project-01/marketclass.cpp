// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#include "marketclass.h"

// The cunstructor just makes an empty map
Market::Market():list_of_chains_({}) {
}

// Lists all the data in the dataset according to their hierarchy
void Market::print_all() {
    for ( auto chain : list_of_chains_ ) {
        for ( auto store : chain.second ) {
            cout << chain.first << endl;
            cout << "  " << store.first << endl;
            std::cout << std::fixed;
                for( auto product : store.second) {
                    cout << "   " << product.first << "  " << std::setprecision(2) << product.second << endl;
                }
        }
    }
}

// Prints the names of all the chaon-stores
void Market::print_chains() {
    for ( auto chain : list_of_chains_ ) {
        cout << chain.first << endl;
    }
}

// Prints the name of branches of a chain-store that user has entered.
void Market::print_stores(const string& chain) {
    if ( list_of_chains_.find(chain) == list_of_chains_.end() ) {
        cout << "Error: There is not any stores for the entered chain, try again with another chain-store!" << endl;
    } else
        for ( auto store :  list_of_chains_.at(chain) )
            cout << store.first << endl;
}

// Finding the cheapest product
void Market::print_cheapest(const string& desired_product) {
    //    At first we find the cheapest product price.
    int found = 0 ;
    double tmp_cheapest = 0;
    for ( auto chain : list_of_chains_ ) {
        for ( auto store : chain.second ) {
            for( auto product : store.second) {
                if (product.first == desired_product && found == 0) {
                    tmp_cheapest = product.second;
                    found = 1;
                }
                if (tmp_cheapest > product.second && product.first == desired_product && found == 1) {
                    tmp_cheapest = product.second;
                }
            }
        }
    }
    //    Then here we find the stores that have the product with that price.
    if (found == 1) {
        std::cout << std::fixed;
        cout << std::setprecision(2) << tmp_cheapest << endl;
        for ( auto chain : list_of_chains_ ) {
            for ( auto store : chain.second ) {
                for( auto product : store.second) {
                    if (product.first == desired_product && product.second == tmp_cheapest) {
                        cout << chain.first << " " << store.first << endl;
                    }
                }
            }
        }
    }
    else
        cout << "This product is not available anywhere." << endl;
}

// Prints all of the products of the chain store name and one of its branches that user has entered.
void Market::print_selection(const string& chain, const string& store) {
    if ( list_of_chains_.find(chain) == list_of_chains_.end() ) {
        cout << "Error: There is not any chain-stores named as the input, try again with another chain-store!" << endl;
    } else {
        if ( list_of_chains_.at(chain).find(store) == list_of_chains_.at(chain).end() ) {
            cout << "Error: There is not such a store in the entered chain, try again with other inputs!" << endl;
        } else {
            std::cout << std::fixed;
            for( auto product : list_of_chains_.at(chain).at(store)) {
                cout << product.first << " " << std::setprecision(2) << product.second << endl;
            }
        }
    }
}

// We call this function for each line in the input file to add that line to our dataset.
void Market::add_product(const string& chain, const string& branch, const string& product, double price) {
    if ( list_of_chains_.find(chain) == list_of_chains_.end() ) {
        list_of_chains_.insert( { chain, {} } );
    }
    if ( list_of_chains_.at(chain).find(branch) == list_of_chains_.at(chain).end() ) {
        list_of_chains_.at(chain).insert( { branch, {} } );

        if ( list_of_chains_.at(chain).at(branch).find(product) == list_of_chains_.at(chain).at(branch).end() ) {
            list_of_chains_.at(chain).at(branch).insert( { product, price } );
        } else {
            list_of_chains_.at(chain).at(branch).at(product) = price ;
        }
    } else {
        if ( list_of_chains_.at(chain).at(branch).find(product) == list_of_chains_.at(chain).at(branch).end() ) {
            list_of_chains_.at(chain).at(branch).insert( { product, price } );
        } else {
            list_of_chains_.at(chain).at(branch).at(product) = price ;
        }
    }
}
