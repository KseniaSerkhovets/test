#include "TrigonometryCounter.h"
#include <iostream>

TrigonometryCounter::TrigonometryCounter()
{
    //ctor
}

TrigonometryCounter::~TrigonometryCounter()
{
    //dtor
}

string TrigonometryCounter::TrigonometryCounting(string s, string k, int *start, int finish)
{
    this->n.number = stoi(k);
    if (s[(*start) - 1] == 'n')
    {
        *start = *start - 3;
        this->n.answer = sin(this->n.number);
        this->n.ranswer = round(this->n.answer);
        s = s.replace(*start, finish - (*start) + 1, to_string(this->n.ranswer));
    }
    else
         if (s[(*start) - 1] == 's')
        {
             *start = (*start) - 3;
            this->n.answer = cos(this->n.number);
            this->n.ranswer = round(this->n.answer);
            s = s.replace(*start, finish - (*start) + 1, to_string(this->n.ranswer));
        }
        else
            if (s[(*start) - 1] == 'g')
            {
                *start = (*start) - 2;
                this->n.answer = tan(this->n.number);
                this->n.ranswer = round(this->n.answer);
                s = s.replace(*start, finish - (*start) + 1, to_string(this->n.ranswer));
            }
    return s;
}