#include <iostream>
using namespace std;

int menu()
{
    int ch;
    cout << "Array Functions" << endl;
    cout << "Menu" << endl;
    cout << "1. Display" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Search" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Choice: ";
    cin >> ch;
    return ch;
}
void display(int arr[], int n)
{
    cout << endl
         << "The Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout<<endl;
}
void insertArr(int arr[], int &n, int pos, int val)
{
    for (int i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = val;
    n++;
}

void deleteArr(int arr[], int &n, int pos)
{
    for (int i = pos - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void search(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            cout << endl
                 << val << " found at position: " << i + 1 << endl;
            break;
        }
    }
}

int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7};
    int n = (sizeof(arr) / sizeof(int));
    int ch, pos, val;
    bool play = true;
    while (play)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            display(arr, n);
            break;
        case 2:
            cout << "Enter Position : ";
            cin >> pos;
            cout << "Enter Value: ";
            cin >> val;
            insertArr(arr, n, pos, val);
            break;

        case 3:
            cout << "Enter Position : ";
            cin >> pos;
            deleteArr(arr, n, pos);
            break;
        case 4:
            cout << "Enter Value: ";
            cin >> val;
            search(arr, n, val);
            break;
        case 5:
            play = !play;
            break;

        default:
            cout<<"Enter Correct Choice!!!";
        }
    }

    return 0;
}
