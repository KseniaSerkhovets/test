#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "constants.h"

#include <string>
#include <iostream>
#include <regex>

using namespace std;

class Validator
{
public:
    Validator(string s);
    ~Validator();
    bool validations();

protected:

private:
    bool validation2();
    bool LookingForBracketsProblem();
    bool LookingForNotAllowedSynbols();
    string s;
};

#endif // VALIDATOR_H