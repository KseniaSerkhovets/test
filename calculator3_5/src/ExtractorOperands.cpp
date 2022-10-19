#include "ExtractorOperands.h"

ExtractorOperands::ExtractorOperands(string s1, int n1)
{
    //this->n = n1;
    //this->s = s1;
}

ExtractorOperands::~ExtractorOperands()
{
    //dtor
}

void ExtractorOperands::define_right_sign()
{
    this->b.znak = 1;
    this->b.finish = this->n + 1;

    if(this->s[this->n + 1] == MINUS_SIGN)
    {
        this->b.znak = -1;
        this->s = this->s.replace(this->n + 1, 1, "");
    }
}
void ExtractorOperands::define_left_sign()
{
    this->a.znak = 1;
    if((this->a.start > 0) && (this->s[this->a.start - 1] == MINUS_SIGN))
    {
        this->a.start--;
        this->a.znak = -1;
    }
}
void ExtractorOperands::define_left_operand()
{
    this->a.start = this->n - 1;
    while((this->a.start > 0) && (isdigit(this->s[this->a.start])))
    {
        if (isdigit(this->s[this->a.start - 1]))
            this->a.start--;
        else
            break;
    }
    string a_s = this->s.substr(this->a.start, this->n - this->a.start);
    this->a.nomer = stoi(a_s);
}
void ExtractorOperands::define_right_operand()
{
    while((this->b.finish < this->s.size() - 1) && (isdigit(this->s[this->b.finish])))
    {
        if (isdigit(this->s[this->b.finish + 1]))
            this->b.finish++;
        else
            break;
    }
    string b_s = this->s.substr(this->n + 1, this->b.finish - this->n );
    this->b.nomer = stoi(b_s);
}

void ExtractorOperands::operator_extraction()
{
    this->define_left_operand();
    this->define_left_sign();
    this->define_right_sign();
    this->define_right_operand();
    return Operands(this->a.nomer * this-> a.znak, this->b.nomer * this->b.znak,
                    this->a.start, this->b.finish);
}


