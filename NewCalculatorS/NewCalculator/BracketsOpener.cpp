#include "BracketsOpener.h"

BracketsOpener::BracketsOpener()
{
    //ctor
}

BracketsOpener::~BracketsOpener()
{
    //dtor
}

string BracketsOpener::remove_brackets(string s, int start, int finish, string number)
{
    if ((start > 0) && (s[start - 1] == OPENING_BRACKET))
        return s.replace(start - 1, finish - start + 3, number);
    return s.replace(start, finish - start + 1, number);
}

string BracketsOpener::recursia(string s, int start)
{
    int finish = start;
    while ((finish < s.size()) && (s[finish] != CLOSING_BRACKET))
    {
        if (s[finish] == OPENING_BRACKET)
            s = recursia(s, finish + 1);
        finish++;
    }
    finish--;

    Simplefier k = Simplefier(s);
    string number = k.calculation(start, finish);
    s = remove_brackets(s, start, finish, number);
    return s;
}