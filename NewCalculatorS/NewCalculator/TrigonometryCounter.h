#ifndef TRIGONOMETRYCOUNTER_H
#define TRIGONOMETRYCOUNTER_H

#include <math.h>
#include <string>

using namespace std;

struct SearchData
{
    string str;
    double number;
    double answer;
    int ranswer;
};

class TrigonometryCounter
{
public:
    TrigonometryCounter();
    ~TrigonometryCounter();
    SearchData n;
    string TrigonometryCounting(string s, string k, int *start, int finish);
protected:

private:
   
};

#endif // TRIGONOMETRYCOUNTER_H