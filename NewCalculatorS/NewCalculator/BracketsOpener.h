#ifndef BRACKETSOPENER_H
#define BRACKETSOPENER_H

#include "Simplefier.h"
#include "constants.h"

#include <string>

using namespace std;

class BracketsOpener
{
public:
    BracketsOpener();
    ~BracketsOpener();
    string recursia(string s, int start);

protected:

private:
    string remove_brackets(string s, int start, int finish, string number);
};

#endif // BRACKETSOPENER_H