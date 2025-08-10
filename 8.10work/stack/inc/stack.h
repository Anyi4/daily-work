#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 栈结构体定义
typedef struct Stack {
    char *base;  // 栈底指针
    char *top;   // 栈顶指针
    int size;    // 栈的容量
} stack;

// 初始化栈
bool Stack_init(stack *s, int max_size);

// 判断栈是否已满
bool isStackFull(stack *s);

// 判断栈是否为空
bool isStackEmpty(stack *s);

// 入栈操作
bool push(stack *s, char value);

// 出栈操作
bool pop(stack *s, char *value);

// 查看栈顶元素
char Stack_checkTop(stack *s);

// 获取当前栈中元素个数
int Stack_getSize(stack *s);

// 打印栈中所有元素
void print_Stack(stack *s);

// 销毁栈
void Stack_destroy(stack *s);

#endif
