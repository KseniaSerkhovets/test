#include "Validator.h"

Validator::Validator(string s)
{
    this->s = s;
}

Validator::~Validator()
{
    //dtor
}

bool Validator::validation1()
{
    int a = 0;
    for(int i = 0; i < this->s.size(); i++)
    {
        if(this->s[i] == OPENING_BRACKET)
            a++;
        if(this->s[i] == CLOSING_BRACKET)
            a--;
        if(a < 0)
            break;
    }
    if(a == 0)
        return true;
    else
        return false;
}

bool Validator::validation2()
{
    int n = 0;
    while(n < this->s.size())
    {
        while((isdigit(this->s[n])) && (n < this->s.size()))
            n++;
        if((n + 1 < this->s.size()) &&
           ((this->s[n] == PLUS_SIGN) || (this->s[n] == MULTIPLY_SIGN) ||
            (this->s[n] == DIVIDE_SIGN) || (this->s[n] == MINUS_SIGN)) &&
           ((this->s[n + 1] == PLUS_SIGN) || (this->s[n + 1] == MULTIPLY_SIGN) ||
            (this->s[n + 1] == DIVIDE_SIGN)))
            return false;
        n++;
    }
    return true;
}

bool Validator::validations()
{
    if(this->validation1() && this->validation2())
        return true;
    return false;
}
