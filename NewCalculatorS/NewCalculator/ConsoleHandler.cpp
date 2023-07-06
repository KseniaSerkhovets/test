#include "ConsoleHandler.h"
ConsoleHandler::ConsoleHandler()
{
    //ctor
}

ConsoleHandler::~ConsoleHandler()
{
    //dtor
}

void ConsoleHandler::handle()
{
    cout << "Enter a mathematical expression. To stop the program enter q.";
    string str;
    while (true)
    {
        getline(cin, str);
        if (str != "q")
        {
            if (str.size() == 0)
                cout << endl;
            else
            {
                cout << str << "    = ";
                str = Cleaner().del(str);
                if (Validator(str).validations())
                {
                    BracketsOpener bo = BracketsOpener();
                    cout << bo.recursia(str, 0) << endl;
                }
            }

        }
        else
            break;
    }
}