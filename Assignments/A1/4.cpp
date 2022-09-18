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
    int row, col, temp;
    cin >> row;
    cin >> col;
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter val: ";
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl
         << endl;

    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << arr[i][j] << "  ";
                }
                cout <<endl;
            }
            cout<<endl;
        }
    }

    cout << endl;

    return 0;
}
