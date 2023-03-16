#include "Simplefier.h"

Simplefier::Simplefier(string s)
{
    this->s = s;
}

Simplefier::~Simplefier()
{
    //dtor
}

void Simplefier::counting_the_number_of_operators()
{
    this->oper.MDopers = 0;
    this->oper.PMopers = 0;
    for (int i = 1; i < this->s.size(); i++)
    {
        if ((this->s[i] == MULTIPLY_SIGN) || (this->s[i] == DIVIDE_SIGN))
            this->oper.MDopers++;
        if ((this->s[i] == PLUS_SIGN) || ((this->s[i] == MINUS_SIGN) && (isdigit(this->s[i - 1]))))
            this->oper.PMopers++;
    }
}

string Simplefier::calculation(int start, int finish)
{
    this->s = this->s.substr(start, finish - start + 1);

    counting_the_number_of_operators();

    Executor e = Executor(this->s);
    e.doing_operations(this->oper.MDopers, MULTIPLY_SIGN, DIVIDE_SIGN);
    e.doing_operations(this->oper.PMopers, PLUS_SIGN, MINUS_SIGN);

    return e.get_expresion();
}