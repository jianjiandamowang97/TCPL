//
// Created by jianjian on 2025/5/14.
//
#include <stdio.h>

int main(void)
{
    int c;
    int lastc = ' '; // 初始化为空白字符
    int count = 0;

    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && (lastc != ' ' && lastc != '\n' && lastc != '\t'))
            ++count;
        lastc = c;
    }

    // 如果最后一个字符是非空白字符，增加计数
    if (lastc != ' ' && lastc != '\n' && lastc != '\t')
        ++count;

    printf("%d\n", count);
    return 0;
}