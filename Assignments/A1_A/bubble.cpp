#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[]={3,2,71,-1,4,0,1},temp=0;
    int n = sizeof(arr)/sizeof(int);
    for (int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                // swap(arr[j],arr[j+1]);
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }

    }
     cout << endl
         << "The Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout<<endl;
    return 0;
}
