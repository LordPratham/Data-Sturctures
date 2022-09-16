#include <stdio.h>
#include <unistd.h>

int main()
{
    int child = fork();
    int c = 5;
    if (child == 0)
    {
        c += 5;
        printf("c is  %d\n", c);
    }

    else
    {
        child = fork();
        c += 10;
        printf("c is  %d\n", c);

        if (child)
        {
            c += 5;
            printf("c is  %d\n", c);
        }
    }
    return 0;
}