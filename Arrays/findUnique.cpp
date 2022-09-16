#include<iostream>
using namespace std;

int findUnique(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[9]={4,5,6,7,8,7,6,5,4};
    cout<<findUnique(arr,9);
    return 0;
}
