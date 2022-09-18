#include <iostream>
using namespace std;

void deleteArr(int arr[], int &n, int index)
{
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}
int main(int argc, char const *argv[])
{
    int arr[100] = {1, 2, 3, 4, 5, 1, 2, 3, 7, 8, 3, 2};
    int ans = 0;
    int n = 100;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                deleteArr(arr, n, j);
            }
        }
    }
    cout << endl
         << "The Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    return 0;
}
