#include "FileHandler.h"

FileHandler::FileHandler()
{
    //ctor
}

FileHandler::~FileHandler()
{
    //dtor
}

void FileHandler::get_adress()
{
    cout << "Enter file address." << endl;
    string address;
    cin >> address;
    this->inaddress = address + "\\input.txt";
    this->outaddress = address + "\\output.txt";
}

void FileHandler::handle()
{
    string str;
    this->get_adress();
    ifstream input(this->inaddress);
    ofstream output(this->outaddress);

    while (getline(input, str))
    {
        if (str.size() > 0)
        {
            output << str << "    = ";
            str = Cleaner().del(str);
            if (Validator(str).validations())
            {
                BracketsOpener bo = BracketsOpener();
                output << bo.recursia(str, 0) << endl;
            }
        }
        else
            output << endl;
    }
    cout << "The program has completed its work.";
    input.close();
    output.close();
}