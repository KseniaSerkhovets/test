
#include "Validator.h"

Validator::Validator(string s)
{
    this->s = s;
}

Validator::~Validator()
{
    //dtor
}

bool Validator::LookingForBracketsProblem()
{
    int a = 0;
    for (int i = 0; i < this->s.size(); i++)
    {
        if (this->s[i] == OPENING_BRACKET)
            a++;
        if (this->s[i] == CLOSING_BRACKET)
            a--;
        if (a < 0)
            break;
    }
    if (a == 0)
        return true;
    else
    {
        cout << "Error: Problem with brackets!" << endl;
        return false;
    }
}

bool Validator::validation2()
{
    int n = 0;
    while (n < this->s.size())
    {
        while ((isdigit(this->s[n])) && (n < this->s.size()))
            n++;
        if ((n + 1 < this->s.size()) &&
            ((this->s[n] == PLUS_SIGN) || (this->s[n] == MULTIPLY_SIGN) ||
                (this->s[n] == DIVIDE_SIGN) || (this->s[n] == MINUS_SIGN)) &&
            ((this->s[n + 1] == PLUS_SIGN) || (this->s[n + 1] == MULTIPLY_SIGN) ||
                (this->s[n + 1] == DIVIDE_SIGN)))
        {
            cout << "Error";
            return false;
        }
        n++;
    }
    return true;
}

bool Validator::LookingForNotAllowedSynbols()
{
    smatch match;
    regex not_allowed_symbols("(^|[\\+\\*/-\\(\\d])(?!(sin|cos|tan)\\()[A-Za-z]+");

    if (regex_search(this->s, match, not_allowed_symbols))
    {
        cout << "Error: Symbol " << match.str() << " is not allowed!" << endl;
        return false;
    }
    return true;
}
/*
bool Validator::LookingForNotAllowedWords()
{
    smatch match;
    regex numb_4("(^|[\\+\\*\\/-\\(\\d])(?!(sin|cos|tan)\\()[A-Za-z]+");
    
    regex not_allowed_letters1("\w(?=(sin|cos|tg))");
    regex not_allowed_letters2("(?>(sin|cos|tg))\w");
    regex not_allowed_letters3("\w");

    if (regex_search(this->s, match, not_allowed_letters1))
    {
        cout << "Error: 1 " << match.str() << " ." << endl;
            return false;
    }
    if (regex_search(this->s, match, not_allowed_letters2))
    {
        cout << "Error: 2 " << match.str() << " ." << endl;
            return false;
    }
    if (regex_search(this->s, match, not_allowed_letters3))
    {
        if ((match.str().size() <= 1) && (match.str().size() >= 4))
        {
            cout << "Error: 3 " << match.str() << " ." << endl;
            return false;
        }
    }


    if (regex_search(this->s, match, numb_4))
    {
        cout << "Error: 2 " << match.str() << " ." << endl;
        return false;
    }

    return true;
}
*/

bool Validator::validations()
{
    if ((this->LookingForBracketsProblem()) && (this->validation2()) && (this->LookingForNotAllowedSynbols()))
        return true;
    return false;
}
