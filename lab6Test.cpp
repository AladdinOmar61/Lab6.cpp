#include <iostream>
#include <fstream>
using namespace std;

class TextLines
{

private:
    int len; // stores the length of lines present in the array

public:
    string *lines; // stores the array of lines
    int size;      // stores the size of the array

    // Default constructor for setting default values
    TextLines()
    {

        size = 10;                // setting the default array size 10
        lines = new string[size]; // allocating memory

        len = 0; // no elements would be initially in the array so keep len 0
    }
    // Copy constructor
    TextLines(TextLines &line)
    {

        this->lines = line.lines;
        this->size = line.size;
        this->len = line.Length();
    }
    //// Fucntion for expanding the array when size is full
    void expandArray()
    {
        // create a new string array of double size

        int newSize = this->size * 2;

        string *newArr = new string[newSize];

        // copy elements of old arrayy to new
        for (int i = 0; i < len; i++)
        {
            newArr[i] = lines[i];
        }
        // delete alocated space for old
        delete[] lines;

        lines = new string[newSize];

        for (int i = 0; i < len; i++)
        {
            lines[i] = newArr[i];
        }
        delete[] newArr;
        

        // points line to new array
        // lines = newArr;

        // this->size = newSize;
    }
    //// constructor that takes an string paarmeter as filename
    TextLines(string filename)
    {

        ifstream fin;

        fin.open(filename);

        string line;

        if (!fin.fail())
        {

            while (!fin.eof())
            {

                if (len >= size)
                {
                    expandArray();
                }

                getline(fin, line);

                lines[len++] = line;
            }
        }

        else
        {
            cout << "Error! File couldn't be open." << endl;
        }
    }
    // constructor that takes integer parameter and create an array
    TextLines(int size)
    {

        lines = new string[size];

        this->size = size;
    }
    // destructor
    ~TextLines()
    {
        delete[] lines;
    }
    // rmeove and return the last line
    string removeLast()
    {

        string el = lines[len - 1];

        lines[len - 1] = "";

        return el;
    }
    // for pushing a line at the end
    void pushBack(string line)
    {

        if (len < size)
            lines[len++] = line;

        else
        {

            cout << "No vacant space! We are expanding the array for taking your entry.\n";
            expandArray();
        }
    }
    // for making the list empty
    void emptyTheList()
    {

        for (int i = 0; i < len; i++)
            lines[i] = "";

        len = 0;
    }
    // return the length of lines array
    int Length()
    {
        return len;
    }
};

// main driver fucntion
int main()
{

    TextLines t("lines.txt");

    cout << "Length of array is " << t.Length() << endl;

    t.pushBack("Hi, I am programmer");
    t.pushBack("C++ is high-level language");
    t.pushBack("This program based on OOPs");
    t.pushBack("It uses pointers");
    t.pushBack("It uses dynamic array");

    cout << "Length of array is after pushing 5 entries at last: " << t.Length() << endl;

    cout << "Removing the last line: " << t.removeLast() << endl;

    cout << "Emptying the list....." << endl;
    t.emptyTheList();
    cout << "Length of array is " << t.Length() << endl;
}