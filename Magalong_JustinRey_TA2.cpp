#include <iostream>

using namespace std;

void Menu();
void string_length();
void string_compare();
void string_concatenate();

int main() 
{
    int choice;
    char loopChoice;

    do {
        Menu();
        cin >> choice;
        system("cls");
        switch (choice) 
        {
            case 1:
                string_length();
                break;
            case 2:
                string_compare();
                break;
            case 3:
                string_concatenate();
                break;
            case 4:
                cout << " Exiting program..." << endl;
                exit(0);
                break;
            default:
                cout << " Invalid choice. Please try again." << endl;
                break;
        } 

        cout << " Try Again? (Y/N): ";
        cin >> loopChoice;
        system("cls");
    } while (loopChoice == 'Y' || loopChoice == 'y');

    return 0;
}

void Menu() 
{
    cout << " ==============================" << endl;
    cout << "    ARRAY ABSTRACT DATA TYPE   " << endl;
    cout << " ==============================" << endl;
    cout << " What do you want to do?" << endl;
    cout << " [1] Find the string length" << endl;
    cout << " [2] Compare two strings" << endl;
    cout << " [3] Concatenate two strings" << endl;
    cout << " [4] Exit" << endl;
    cout << " Enter your choice: ";
}

void string_length() 
{
    char str[100];
    cout << " ==================================" << endl;
    cout << "            STRING LENGTH          " << endl;
    cout << " ==================================" << endl;
    cout << " Enter a string: ";
    cin >> str;

    char* ptr = str;
    int length = 0;
    while (*ptr) 
    {
        length++;
        ptr++;
    }

    cout << " The length of the string is: " << length << endl;
}

void string_compare() 
{
    char str1[100], str2[100];
    cout << " ==================================" << endl;
    cout << "           STRING COMPARE          " << endl;
    cout << " ==================================" << endl;
    cout << " Enter the first string: ";
    cin >> str1;
    cout << " Enter the second string: ";
    cin >> str2;

    char* ptr1 = str1;
    char* ptr2 = str2;

    while (*ptr1 == *ptr2 && *ptr1 != '\0' && *ptr2 != '\0') 
    {
        ptr1++;
        ptr2++;
    }

    if (*ptr1 == '\0' && *ptr2 == '\0')
        cout << " The strings are equal." << endl;
    else if (*ptr1 < *ptr2)
        cout << " The first string is smaller." << endl;
    else
        cout << " The first string is bigger." << endl;
}


void string_concatenate() 
{
    char str1[100], str2[100];
    cout << " ==================================" << endl;
    cout << "        STRING CONCATENATION       " << endl;
    cout << " ==================================" << endl;
    cout << " Enter the first string: ";
    cin >> str1;
    cout << " Enter the second string: ";
    cin >> str2;

    char* ptr1 = str1;
    while (*ptr1) 
    {
        ptr1++;
    }
    char* ptr2 = str2;
    while (*ptr2) 
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';

    cout << " The concatenated string is: " << str1 << endl;
}
