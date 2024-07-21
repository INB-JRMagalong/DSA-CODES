#include <iostream>
using namespace std;

void TowerOfHanoi(int numDisk, char rodSource, char rodTarget, char rodAuxiliary);

int main()
{
    int rodCount;
    cout << "Enter the number of rods: ";
    cin >> rodCount;

    while (rodCount != 2 && rodCount != 3)
    {
        cout << "Please input 2 or 3 rods only!" << endl;
        cout << "Enter the number of rods: ";
        cin >> rodCount;
    }

    TowerOfHanoi(rodCount, 'A', 'C', 'B');

    return 0;
}

void TowerOfHanoi(int numDisk, char rodSource, char rodTarget, char rodAuxiliary)
{
    if (numDisk > 0)
    {
        TowerOfHanoi(numDisk - 1, rodSource, rodAuxiliary, rodTarget);
        cout << "Move disk " << numDisk << " from " << rodSource << " to " << rodTarget << endl;
        TowerOfHanoi(numDisk - 1, rodAuxiliary, rodTarget, rodSource);
    }
}