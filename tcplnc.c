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
/*
 为什么这个程序 在clion上无法终止 我按ctrl + z没反应 ctrl + d也没反应

你的程序如下：
Apply to test0513.c
你遇到的问题
在 CLion 里运行时，输入内容后，按 Ctrl+Z 或 Ctrl+D 都无法终止循环，程序一直在等待输入。
原因分析
CLion 的终端类型
CLion 默认的“运行”窗口（Run/Debug Console）并不是一个真正的终端（terminal），它对标准输入的处理和普通命令行窗口（如 Windows 的 cmd、PowerShell，或 Linux 的 bash）不完全一样。
很多IDE的“运行窗口”不支持直接发送EOF（文件结束符），所以你按 Ctrl+Z 或 Ctrl+D 没有效果。
EOF 的输入方式
Windows：在命令行窗口，Ctrl+Z 然后回车 表示EOF。
Linux/Mac：在终端，Ctrl+D 表示EOF。
IDE 终端：有些IDE的“运行窗口”不支持EOF，或者需要特殊设置。
解决方法
方法一：用系统自带终端运行
打开命令行窗口（Windows下用cmd或PowerShell，Linux/Mac下用Terminal）。
进入你的程序目录，编译并运行你的程序：
Apply to test0513.c
输入内容，结束时：
Windows：按 Ctrl+Z，然后回车
Linux/Mac：按 Ctrl+D
方法二：用CLion的“Terminal”窗口
CLion有一个“Terminal”标签页（通常在底部），它是真正的终端。在这里运行你的程序，同样可以用上述方法输入EOF。
方法三：用文件重定向测试
你可以把输入内容写到一个文件里，然后用重定向运行：
Apply to test0513.c
这样程序会在读到文件末尾时自动遇到EOF并结束。
总结
不是你的代码有问题，而是CLion的“运行窗口”不支持直接输入EOF。
换到真正的终端（Terminal）运行，或者用文件重定向，都可以正常终止程序。
如还有疑问，欢迎继续提问！
 */
