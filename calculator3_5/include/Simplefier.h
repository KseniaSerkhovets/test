#ifndef SIMPLEFIER_H
#define SIMPLEFIER_H

#include "Executor.h"
#include "constants.h"

#include <string>

struct OperandCounter
{
    int MDopers;
    int PMopers;
};

using namespace std;

class Simplefier
{
    public:
        Simplefier(string s);
        ~Simplefier();
        string calculation(int start, int finish);


    protected:

    private:
        void counting_the_number_of_operators();
        OperandCounter oper;
        string s;
};

#endif // SIMPLEFIER_H
