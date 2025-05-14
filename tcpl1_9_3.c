//
// Created by jianjian on 2025/5/14.
//
#include <stdio.h>
#define NONBLANK 'a'
int main(void)
{
    int c;
    int lastc = NONBLANK; // 标志：上一个字符是否是空格测试

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
    return 0;
}