#include <iostream>
#include <fstream>
#include <string>

#include "Number_of_operators.h"
#include "ExtractorOperands.h"
#include "constants.h"

using namespace std;

string del(string s)
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

bool validation1(string s)
{
    int a = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == OPENING_BRACKET)
            a++;
        if(s[i] == CLOSING_BRACKET)
            a--;
        if(a < 0)
            break;
    }
    if(a == 0)
        return true;
    else
        return false;
}

validation2(string s)
{
    int n = 0;
    while(n < s.size())
    {
        while((isdigit(s[n])) && (n < s.size()))
            n++;
        if((n + 1 < s.size()) && ((s[n] == PLUS_SIGN) || (s[n] == MULTIPLY_SIGN) || (s[n] == DIVIDE_SIGN) || (s[n] == MINUS_SIGN)) && ((s[n + 1] == PLUS_SIGN) || (s[n + 1] == MULTIPLY_SIGN) || (s[n + 1] == DIVIDE_SIGN)))
            return false;
        n++;
    }
    return true;
}

bool validations(string s)
{
    if(validation1(s) && validation2(s))
        return true;
    return false;
}


string operation(string s, int n)
{
    ExtractorOperands extractor = ExtractorOperands(s, n);
    Operands operands = extractor.operator_extraction();
    int a = operands.a;
    int b = operands.b;

    int answer;
    switch(s[n])
    {
        case DIVIDE_SIGN:
            try
            {
                if (b == 0)
                    throw runtime_error("Division by zero");

                answer = a / b;
            }
            catch(runtime_error e)
            {
                cout << e.what();
            }
        break;
        case MULTIPLY_SIGN:
            answer = a * b;
        break;
        case PLUS_SIGN:
            answer = a + b;
            break;
        case MINUS_SIGN:
            answer = a - b;
            break;
    }
    return s.replace(operands.start, operands.finish - operands.start + 1, to_string(answer));
}

string doing_operations(string nom, int oper, Operator a, Operator b)
{
    int n;
    while (oper > 0)
    {
        n = 1;
        while ((nom[n] != a) && (nom[n] != b))
            n++;
        nom = operation(nom, n);
        oper--;
    }
    return nom;
}

Number_of_operators oper;

void counting_the_number_of_operators(string nom)
{
    oper.MDopers = 0;
    oper.PMopers = 0;
    for (int i = 1; i < nom.size(); i++)
    {
        if ((nom[i] == MULTIPLY_SIGN) || (nom[i] == DIVIDE_SIGN))
            oper.MDopers++;
        if ((nom[i] == PLUS_SIGN) || ((nom[i] == MINUS_SIGN) && (isdigit(nom[i - 1]))))
            oper.PMopers++;
    }
}

string calculation(string s, int start, int finish)
{
    string nom = s.substr(start, finish - start + 1);

    counting_the_number_of_operators(nom);

    nom = doing_operations(nom, oper.MDopers, MULTIPLY_SIGN, DIVIDE_SIGN);
    nom = doing_operations(nom, oper.PMopers, PLUS_SIGN, MINUS_SIGN);

    return nom;
}

string remove_brackets(string s, int start, int finish, string number)
{
    if(s[start - 1] == OPENING_BRACKET)
    {
        s = s.replace(start - 1, finish - start + 3 , number);
    }
    else
    {
        s = s.replace(start , finish - start + 1 , number);
    }
    return s;
}

string recursia(string s, int start)
{
    int finish = start;
    while((finish < s.size()) && (s[finish] != CLOSING_BRACKET))
    {
        if(s[finish] == OPENING_BRACKET)
            s = recursia(s, finish + 1);
        finish++;
    }
    finish--;
    string number = calculation(s, start, finish);
    s = remove_brackets(s, start, finish, number);
    return s;
}

void console_program()
{
    cout << "Enter a mathematical expression. To stop the program enter q.";
    string str;
    while(true)
    {
        getline(cin, str);
        if(str != "q")
        {
            if(str.size() == 0)
                cout << endl;
            else
            {
                cout << str << "    = ";
                str = del(str);
                if(validations(str))
                {
                    cout << recursia(str, 0) << endl;
                }
                else
                    cout << "Error";
            }

        }
        else
            break;
    }
}

void file_program()
{
    cout << "Enter file address." << endl;
    string address, str;
    cin >> address;
    string inaddress = address + "\\input.txt", outaddress = address + "\\output.txt";

    ifstream input(inaddress);
    ofstream output(outaddress);

    while (getline (input, str))
    {
        if(str.size() > 0)
        {
            output << str << "    = ";
            str = del(str);
            if(validations(str))
            {
                output << recursia(str, 0) << endl;
            }
            else
                output << "Error" << endl;
        }
        else
            output << endl;
    }
    cout << "The program has completed its work.";
    input.close();
    output.close();
}

int main()
{
    cout << "Enter 0 if you want to work with the console, and 1 if you want to work with files." << endl;
    int q;
    cin >> q;
    if (q == 0)
        console_program();
    else
        file_program();
    return 0;
}
