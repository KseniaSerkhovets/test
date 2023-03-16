#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>

#include "BracketsOpener.h"
#include "Validator.h"
#include "Cleaner.h"
#include "constants.h"

using namespace std;

class ConsoleHandler
{
public:
    ConsoleHandler();
    ~ConsoleHandler();
    void handle();


protected:

private:
};

#endif // CONSOLEHANDLER_H