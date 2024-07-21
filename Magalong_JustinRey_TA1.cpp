#include <iostream>
#include <string>

using namespace std;

class Student 
{
private:
    string firstName;
    string lastName;
    string middleName;
    string course;
    int yearLevel;

public:
    void setFirstName(string fName) 
    {
        firstName = fName;
    }

    void setLastName(string lName) 
    {
        lastName = lName;
    }

    void setMiddleName(string mName) 
    {
        middleName = mName;
    }

    void setCourse(string sCourse) 
    {
        course = sCourse;
    }

    void setYearLevel(int year) 
    {
        yearLevel = year;
    }

    string getFirstName() 
    {
        return firstName;
    }

    string getLastName() 
    {
        return lastName;
    }

    string getMiddleName() 
    {
        return middleName;
    }

    string getCourse() 
    {
        return course;
    }

    int getYearLevel() 
    {
        return yearLevel;
    }
};

struct Records 
{
    Student st;
    Records* next;
};

void addStudent(Records*& head);
void searchStudent(Records* head);
void showAll(Records* head);
void removeAll(Records*& head);
void displayMenu();
int getMenuChoice();

int main() 
{
    Records* head = nullptr;

    int choice;
    do 
    {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) 
        {
            case 1:
                addStudent(head);
                system("cls");
                break;
            case 2:
                searchStudent(head);
                break;
            case 3:
                showAll(head);
                break;
            case 4:
                removeAll(head);
                cout << " All student records removed." << endl;
                break;
            case 5:
                cout << " Exiting..." << endl;
                break;
            default:
                cout << " Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() 
{
    cout << " ===================================" << endl;
    cout << "              MAIN MENU             " << endl;
    cout << " ===================================" << endl;
    cout << " [1] Add Student Record" << endl;
    cout << " [2] Search Student Record" << endl;
    cout << " [3] Show All Records" << endl;
    cout << " [4] Remove All Records" << endl;
    cout << " [5] Exit Program" << endl;
    cout << " Enter choice: ";
}

int getMenuChoice() 
{
    int choice;
    cin >> choice;
    return choice;
}

void addStudent(Records*& head) 
{
    Student newStudent;
    string fName, lName, mName, course;
    int year;

    cout << " ===================================" << endl;
    cout << " Enter First Name: ";
    cin >> fName;
    newStudent.setFirstName(fName);

    cout << " Enter Middle Name: ";
    cin >> mName;
    newStudent.setMiddleName(mName);

    cout << " Enter Last Name: ";
    cin >> lName;
    newStudent.setLastName(lName);

    cout << " Enter Course: ";
    cin >> course;
    newStudent.setCourse(course);

    cout << " Enter Year Level: ";
    cin >> year;
    newStudent.setYearLevel(year);

    Records* newNode = new Records;
    newNode->st = newStudent;
    newNode->next = head;
    head = newNode;
}

void searchStudent(Records* head) 
{
    string searchLastName;
    cout << " Enter Last Name to search: ";
    cin >> searchLastName;

    Records* temp = head;
    bool found = false;

    while (temp != nullptr) 
    {
        if (temp->st.getLastName() == searchLastName) 
        {
            found = true;
            cout << " ===================================" << endl;
            cout << " Student Record:" << endl;
            cout << " Name: " << temp->st.getFirstName() << " " << temp->st.getMiddleName() << " " << temp->st.getLastName() << endl;
            cout << " Course: " << temp->st.getCourse() << endl;
            cout << " Year Level: " << temp->st.getYearLevel() << endl;
            break;
        }
        temp = temp->next;
    }

    if (!found) 
    {
        cout << " Student record not found." << endl;
    }
}

void showAll(Records* head) 
{
    Records* temp = head;

    if (temp == nullptr) 
    {
        cout << " No records found." << endl;
        return;
    }
    cout << " ===================================" << endl;
    cout << " Student Records: " << endl;
    cout << endl;
    while (temp != nullptr) 
    {
        cout << " Name: " << temp->st.getFirstName() << " " << temp->st.getMiddleName() << " " << temp->st.getLastName() << endl;
        cout << " Course: " << temp->st.getCourse() << endl;
        cout << " Year Level: " << temp->st.getYearLevel() << endl;
        cout << endl;
        temp = temp->next;
    }
}

void removeAll(Records*& head) 
{
    Records* current = head;
    Records* next;

    while (current != nullptr) 
    {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}