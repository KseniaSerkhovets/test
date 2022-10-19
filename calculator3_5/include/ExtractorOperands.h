#ifndef EXTRACTOROPERANDS_H
#define EXTRACTOROPERANDS_H
#include "constants.h"
#include <string>

struct
{
    int nomer;
    int start;
    int znak;
    int finish;
}Number;

struct
{
    int a;
    int b;
    int start;
    int finish;
}Operands;

class ExtractorOperands
{
    public:
        ExtractorOperands(string s1, int n1)
        {
            s = s1;
            n = n1;
        }
        ~ExtractorOperands();
        Operands operator_extraction();

    protected:

    private:
        string s;
        int n;
        Number a;
        Number b;
        void define_left_sign();
        void define_right_sign();
        void define_left_operand();
        void define_right_operand();


};

#endif // EXTRACTOROPERANDS_H
