#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "constants.h"

#include <string>

using namespace std;

class Validator
{
    public:
        Validator(string s);
        ~Validator();
        bool validations();

    protected:

    private:
        bool validation1();
        bool validation2();
        string s;
};

#endif // VALIDATOR_H
