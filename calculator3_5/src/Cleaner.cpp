#include "Cleaner.h"

Cleaner::Cleaner()
{
    //ctor
}

Cleaner::~Cleaner()
{
    //dtor
}

string Cleaner::del(string s)
{
    int n = 0;
    while(n < s.size())
    {
        if (s[n] == ' ')
            s = s.replace(n, 1, "");
        else
            n++;
    }
    return s;
}
