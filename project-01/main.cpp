// Pedram Ghazi - Student number: 267640 - Email address: pedram.ghazi@student.tut.fi

#include "marketclass.h"

int main() {
    Market markets;

    bool fileRead = readFile_PutToDatastructure(markets);
    if (fileRead == false)
        return 0;

    bool quit = read_commands(markets);
    if (quit == false)
        return 0;
}
