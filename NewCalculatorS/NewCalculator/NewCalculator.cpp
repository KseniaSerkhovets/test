#include <iostream>

#include "FileHandler.h"
#include "ConsoleHandler.h"


using namespace std;

int main()
{
    cout << "Enter 0 if you want to work with the console, and 1 if you want to work with files." << endl;
    int q;
    cin >> q;
    if (q == 0)
        ConsoleHandler().handle();
    else
        FileHandler().handle();
    return 0;
}