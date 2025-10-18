
#include <stdio.h>

int main()
{
    int num = 10;
    int *p;
    p = &num;

    printf("Value of num: %d\n", *p);
    printf("Address of num: %p\n", (void*)&num);
    return 0;
}