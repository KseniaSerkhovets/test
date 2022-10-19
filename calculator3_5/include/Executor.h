#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include <iostream>
#include "constants.h"
#include "ExtractorOperands.h"

using namespace std;

class Executor
{
    public:
        Executor(string expretion);
        ~Executor();
        void doing_operations(int oper, Operator a, Operator b);
        string get_expresion();

    protected:

    private:
        void operation(int n);
        string expresion;
};

#endif // EXECUTOR_H
