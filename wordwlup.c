//
// Created by jianjian on 2025/5/15.
//





//#include <stdio.h>
//int main(void)
//
///*我的计算逻辑是当遇到空格时，判断上一个字符是否为非空格 非制表符  非换行 如果是 count++ 但是我好想忽略了单词后面是制表符或换行符
//是这样吗 还有哪些存在的问题 */
//{
//    int c;
//    int lastc = ' '; // 初始化为空白字符
//    int count = 0;
//
//    while ((c = getchar()) != EOF)
//    {
//        if ((c == ' ' || c == '\n' || c == '\t') && (lastc != ' ' && lastc != '\n' && lastc != '\t'))
//            ++count;
//        lastc = c;
//    }
//
//    // 如果最后一个字符是非空白字符，增加计数
//    if (lastc != ' ' && lastc != '\n' && lastc != '\t')
//        ++count;
//
//    printf("%d\n", count);
//    return 0;

#include <stdio.h>
#define STATUS_IN 1
#define STATUS_OUT 0
int main(void)
{
    int c;
    int status = STATUS_OUT;
    int count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
            status = STATUS_OUT;
        else if (status == STATUS_OUT)
        {
            status = STATUS_IN;
            ++count;
        }
    }
    printf("%d\n", count);
    return 0;
}



