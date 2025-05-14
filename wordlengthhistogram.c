//
// Created by jianjian on 2025/5/15.
//
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20  // 统计的最大单词长度
#define STATUS_IN 1         // 在单词内
#define STATUS_OUT 0        // 在单词外

int main(void)
{
    int c;
    int status = STATUS_OUT;        // 当前状态：是否在单词内
    int current_word_length = 0;    // 当前单词长度
    int word_length[MAX_WORD_LENGTH + 1] = {0};  // 存储不同长度单词的数量，索引0不使用
    int max_count = 0;              // 出现次数最多的单词长度的计数值

    // 读取输入并统计单词长度
    while ((c = getchar()) != EOF) {
        if (isspace(c)) {  // 空白字符（空格、制表符、换行符等）
            if (status == STATUS_IN) {
                // 一个单词结束
                if (current_word_length <= MAX_WORD_LENGTH)
                    ++word_length[current_word_length];
                current_word_length = 0;
                status = STATUS_OUT;
            }
        } else {
            status = STATUS_IN;
            ++current_word_length;
        }
    }

    // 处理最后一个单词（如果有的话）
    if (status == STATUS_IN && current_word_length <= MAX_WORD_LENGTH)
        ++word_length[current_word_length];

    // 找出最大计数值（用于垂直直方图）
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i)
        if (word_length[i] > max_count)
            max_count = word_length[i];

    // 打印水平直方图
    printf("\n水平直方图（单词长度）：\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (word_length[i] > 0) {  // 只打印有单词的长度
            printf("%2d | ", i);   // 打印长度
            for (int j = 0; j < word_length[i]; ++j)
                printf("*");
            printf(" (%d)\n", word_length[i]);  // 显示计数
        }
    }

    // 打印垂直直方图
    printf("\n垂直直方图（单词长度）：\n");

    // 打印 Y 轴（计数）
    for (int height = max_count; height > 0; --height) {
        printf("%3d |", height);  // Y轴标签
        for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
            if (word_length[i] > 0) {  // 只显示有单词的长度
                printf("  %c ", (word_length[i] >= height) ? '*' : ' ');
            }
        }
        printf("\n");
    }

    // 打印 X 轴（单词长度）
    printf("     ");
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (word_length[i] > 0) {  // 只显示有单词的长度
            printf("----");
        }
    }
    printf("\n     ");
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (word_length[i] > 0) {  // 只显示有单词的长度
            printf("%3d ", i);
        }
    }
    printf("\n");

    return 0;
}


//这个程序可以统计输入文本中不同长度单词的数量，并以水平和垂直两种方式绘制直方图。
//程序主要功能：
//统计单词长度：
//使用状态变量跟踪是否在单词内
//        累计当前单词的长度
//当遇到空白字符结束一个单词时，更新相应长度的计数
//        水平直方图：
//以横向的星号（）表示每个长度的单词数量
//        格式为：长度 | 星号表示（计数值）
//垂直直方图：
//Y轴表示单词计数
//        X轴表示单词长度
//从上到下绘制，每列的高度对应该长度单词的数量
//        使用说明：
//运行程序后输入任意文本
//        使用Ctrl+Z（Windows）或Ctrl+D（Unix）表示输入结束
//        程序会显示两种风格的直方图
//这个实现考虑了以下细节：
//只统计实际出现的单词长度（不显示计数为0的长度）
//最大统计长度为20（可通过MAX_WORD_LENGTH修改）
//使用isspace()函数识别所有空白字符
//        处理文本末尾可能存在的最后一个单词