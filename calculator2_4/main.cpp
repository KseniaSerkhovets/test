#include <iostream>
#include <string>

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
        if(s[i] == '(')
            a++;
        if(s[i] == ')')
            a--;
        if(a < 0)
            break;
    }
    if(a == 0)
        return true;
    else
        return false;
}

string operation(string s, int n)
{
    short znak = 1;
    if(s[n + 1] == '-')
    {
        znak = -1;
        s = s.replace(n + 1, 1, "");
    }
    int start = n - 1, finish = n + 1;
    while((start > 0) && (isdigit(s[start])))
    {
        if (isdigit(s[start - 1]))
            start--;
        else
            break;
    }
    string a_s = s.substr(start, n - start);
    int a = stoi(a_s);
    if((start > 0) && (s[start - 1] == '-'))
    {
        start--;
        a = -a;
    }
    while((finish < s.size() - 1) && (isdigit(s[finish])))
    {
        if (isdigit(s[finish + 1]))
            finish++;
        else
            break;
    }
    string b_s = s.substr(n + 1, finish - n );
    int b = znak * stoi(b_s);

    int answer;
    switch(s[n])
    {
        case '/':
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
        case '*':
            answer = a * b;
        break;
        case '+':
            answer = a + b;
            break;
        case '-':
            answer = a - b;
            break;
    }
    return s.replace(start, finish - start + 1, to_string(answer));
}


string calculation(string s, int start, int finish)
{
    string nom = s.substr(start, finish - start + 1);
    int oper1 = 0, oper2 = 0;
    for (int i = 1; i < nom.size(); i++)
    {
        if ((nom[i] == '*') || (nom[i] == '/'))
            oper1++;
        if ((nom[i] == '+') || ((nom[i] == '-') && (isdigit(nom[i - 1]))))
            oper2++;
    }

    int n;
    while (oper1 > 0)
    {
        n = 0;
        while ((nom[n] != '*') && (nom[n] != '/'))
            n++;
        nom = operation(nom, n);
        oper1--;
    }
    while (oper2 > 0)
    {
        n = 1;
        while ((nom[n] != '+') && (nom[n] != '-'))
            n++;
        nom = operation(nom, n);
        oper2--;
    }
    return nom;
}

string recursia(string s, int start)
{
    int finish = start;
    while((finish < s.size()) && (s[finish] != ')'))
    {
        if(s[finish] == '(')
            s = recursia(s, finish + 1);
        finish++;
    }
    finish--;
    string number = calculation(s, start, finish);
    if(s[start - 1] == '(')
    {
        s = s.replace(start - 1, finish - start + 3 , number);
    }
    else
    {
        s = s.replace(start , finish - start + 1 , number);
    }
    return s;

}

int main()
{
    string str;
    getline(cin, str);
    cout<<str<<endl;
    str = del(str);
    if(validation1(str))
        cout << recursia(str, 0);
    else
        cout << "Error";
    return 0;
}
