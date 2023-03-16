#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>

#include "BracketsOpener.h"
#include "Validator.h"
#include "Cleaner.h"
#include "constants.h"

using namespace std;


class FileHandler
{
public:
    FileHandler();
    ~FileHandler();
    void handle();

protected:

private:
    void get_adress();
    string inaddress, outaddress;
};

#endif // FILEHANDLER_H