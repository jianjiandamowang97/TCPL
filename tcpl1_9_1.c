//
// Created by jianjian on 2025/5/14.
//
#include <stdio.h>
#define LASTC 'a'
int main(void)
{
    int c;
    int lastc = LASTC; // 标志：上一个字符是否是空格

    while ((c = getchar()) != EOF)
    {
        if (c != ' ') {
            putchar(c);
        }
        if (c == ' ')
        {
            if (lastc != ' ')
                putchar(' ');
        }
        lastc = c;
    }
    return 0;
}