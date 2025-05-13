//
// Created by jianjian on 2025/5/13.
//
#include <stdio.h>
int main(void)
{
    long nc = 0;
    while (getchar() != EOF)
    {
        nc++;
    }
    printf("%ld\n", nc);
    return 0;
}