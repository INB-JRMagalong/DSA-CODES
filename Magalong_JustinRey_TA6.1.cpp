#include <iostream>
using namespace std;

int numAppear(int arr[], int size, int count);

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size;)
    {
        int current = arr[i];
        int frequency = numAppear(arr, size, current);

        cout << current << " appears " << frequency << " time(s)" << endl;

        i += frequency;
    }

    return 0;
}

int numAppear(int arr[], int size, int count)
{
    if (size == 0)
    {
        return 0;
    }
    else if (arr[size - 1] == count)
    {
        return 1 + numAppear(arr, size - 1, count);
    }
    else
    {
        return numAppear(arr, size - 1, count);
    }
}