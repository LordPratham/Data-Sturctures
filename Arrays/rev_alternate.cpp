#include<iostream>
using namespace std;

void rev(int arr[],int n){
    int first =0;
    int second=1;
    while(second<=n){
        swap(arr[first],arr[second]);
        first+=2;
        second+=2;
    }
    
}
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"   ";
    }
}


int main(int argc, char const *argv[])
{
    int arr[6]={1,2,3,4,5,6};
    rev(arr,6);
    print(arr,6);
    return 0;
}
