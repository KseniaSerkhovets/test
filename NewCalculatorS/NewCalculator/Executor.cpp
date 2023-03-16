#include "Executor.h"

Executor::Executor(string expresion)
{
    this->expresion = expresion;
}

Executor::~Executor()
{
    //dtor
}

void Executor::operation(int n)
{
    ExtractorOperands extractor = ExtractorOperands(this->expresion, n);
    Operands operands = extractor.operator_extraction();
    int a = operands.a;
    int b = operands.b;

    int answer;
    switch (this->expresion[n])
    {
    case DIVIDE_SIGN:
        try
        {
            if (b == 0)
                throw runtime_error("Division by zero");

            answer = a / b;
        }
        catch (runtime_error e)
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
    this->expresion = this->expresion.replace(operands.start, operands.finish - operands.start + 1, to_string(answer));
}

void Executor::doing_operations(int oper, Operator a, Operator b)
{
    int n;
    while (oper > 0)
    {
        n = 1;
        while ((this->expresion[n] != a) && (this->expresion[n] != b))
            n++;

        this->operation(n);
        oper--;
    }
}

string Executor::get_expresion()
{
    return this->expresion;
}