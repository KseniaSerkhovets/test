
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
    regex not_allowed_symbols("[^0-9^\\)^\\(^\\+^\\-^\\/^\\*^(sin)^(cos)^(tg)]");
    if (regex_search(this->s, match, not_allowed_symbols))
    {
        cout << "Error: Symbol " << match.str() << " is not allowed!" << endl;
        return false;
    }
    return true;

}

/*bool Validator::LookingForNotAllowedLetters()
{
    smatch match;
    regex not_allowed_letters("");
    if (regex_search(this->s, match, not_allowed_letters))
    {
        cout << "Error: Symbol " << match.str() << " is not allowed." << endl;
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
