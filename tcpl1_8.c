//
// Created by jianjian on 2025/5/13.
//
#include <stdio.h>
int main(void)
{
    int c, nc1, nc2, nc3;
    nb = nt = nl = 0;

    while ((c= getchar()) != EOF)
    {
        if (c == '\n')
            ++n1;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++nb;
    }
    printf("%d %d %d\n", nc1, nc2, nc3);

}