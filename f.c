#include<stdio.h>
#include<unistd.h>
int main()
{
    // for(int a=1;a<5;a++)
    //     fork();
        
    // printf("1\n");
    // return 0;
    int child = fork();
    printf("child %d\n",child);
}
