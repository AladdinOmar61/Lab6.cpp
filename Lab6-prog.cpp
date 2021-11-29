#include <iostream>
#include <fstream>
using namespace std;

class TextLines
{
public:
    //array length cap
    int maxlen;
    //sentence array
    string *sentences;
    //constructor
    TextLines()
    {
        maxlen = 10;
        len = 0;
        sentences = new string[maxlen];
    }
    //print out sentences and dynamic arr to adjust
    void expandArray()
    {
        string *sentences = new string[maxlen];
        int newMax = maxlen;
        newMax *= 2;
        string *newSentences = new string[newMax];
        for (int i = 0; i < maxlen; i++)
        {
            newSentences[i] = sentences[i];
        }
        delete[] sentences;
        sentences = new string[newMax];
        for (int i = 0; i < maxlen; i++)
        {
            sentences[i] = newSentences[i];
        }
        delete[] newSentences;
    }
    void printSentences(string file)
    {
        ifstream inFile;
        // int len = 0;
        inFile.open(file);
        while (!inFile.eof())
        {
            inFile >> sentences[len];
            len++;
            if (len >= maxlen)
            {
                expandArray();
            }
        }
        inFile.close();
        inFile.open(file);
        while (!inFile.eof())
        {
            getline(inFile, sentences[len]);
            cout << sentences[len] << endl;
        }
        inFile.close();
    }
    //remove last element from arr
    void removeLast()
    {
        cout << "deleting: " << sentences[len - 1] << endl;
        sentences[len - 1] = " ";
    }
    //hi

private:
    //current array length
    int len;
};

int main()
{
    //initialize object
    TextLines s1;
    string sentences;
    //print sentences of s1 from lines.txt
    s1.printSentences("lines.txt");
    //removing last element from s1
    s1.removeLast();
    return 0;
}