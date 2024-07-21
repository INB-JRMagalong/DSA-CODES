#include <iostream>
#include <list>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char, list<char>> s;
    string braces;
    int stringLength, replacements = 0, openBraceCount = 0, closeBraceCount = 0;

    cout << "Enter a string of braces: ";
    getline(cin, braces);

    stringLength = braces.length();

    for (int i = 0; i < stringLength; i++)
    {
        char ch = braces[i];
        s.push(ch);
    }

    while (!s.empty())
    {
        char brace = s.top();
        if (brace == '{')
        {
            openBraceCount++;
            s.pop();
        }
        else if (brace == '}')
        {
            closeBraceCount++;
            s.pop();
        }
    }

    if (openBraceCount == closeBraceCount)
    {
        replacements = 0;
    }
    else if (openBraceCount > closeBraceCount)
    {
        replacements = openBraceCount - closeBraceCount;
    }
    else
    {
        replacements = closeBraceCount - openBraceCount;
    }
    cout << "Minimum number of replacements required: " << replacements << endl;
}
