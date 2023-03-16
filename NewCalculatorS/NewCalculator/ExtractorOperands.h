#ifndef EXTRACTOROPERANDS_H
#define EXTRACTOROPERANDS_H
#include "constants.h"
#include <string>

using namespace std;

struct Number
{
    int nomer;
    int start;
    int znak;
    int finish;
};

struct Operands
{
    int a;
    int b;
    int start;
    int finish;
};

class ExtractorOperands
{

public:
    ExtractorOperands(string s, int n);
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