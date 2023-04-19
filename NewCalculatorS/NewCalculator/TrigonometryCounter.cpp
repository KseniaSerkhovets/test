#include "TrigonometryCounter.h"

TrigonometryCounter::TrigonometryCounter()
{
    //ctor
}

TrigonometryCounter::~TrigonometryCounter()
{
    //dtor
}

string TrigonometryCounter::TrigonometryCounting(string s, string k, int start, int finish)
{
    this->n.number = stoi(k);
    if (s[start - 1] == 'n')
    {
        this->n.answer = sin(this->n.number);
        s = s.replace(start - 3, finish - start + 4, to_string(round(this->n.answer)));
    }
    if (s[start - 1] == 's')
    {
        this->n.answer = sin(this->n.number);
        s = s.replace(start - 3, finish - start + 4, to_string(round(this->n.answer)));
    }
    if (s[start - 1] == 'g')
    {
        this->n.answer = sin(this->n.number);
        s = s.replace(start - 2, finish - start + 3, to_string(round(this->n.answer)));
    }
    return s;
}