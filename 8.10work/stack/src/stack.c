#include "../inc/stack.h"

// 初始化栈
bool Stack_init(stack *s, int max_size) {
    s->base = (char *)malloc(max_size * sizeof(char));
    if (s->base == NULL) {
        printf("内存分配失败，栈初始化失败\n");
        return false;
    }
    s->top = s->base;  // 栈顶初始等于栈底，表示空栈
    s->size = max_size;
    return true;
}

// 销毁栈
void Stack_destroy(stack *s) {
    if (s->base != NULL) {
        free(s->base);
        s->base = NULL;
        s->top = NULL;
        s->size = 0;
    }
}

// 判断栈是否已满
bool isStackFull(stack *s) {
    return ((s->top - s->base) == s->size);
}

// 判断栈是否为空
bool isStackEmpty(stack *s) {
    return (s->top == s->base);
}

// 入栈
bool push(stack *s, char value) {
    if (isStackFull(s)) {
        printf("栈已满，无法入栈\n");
        return false;
    }
    *(s->top) = value;  // 将元素放入栈顶
    s->top++;           // 栈顶指针上移(可以使用++)
    return true;
}

// 出栈
bool pop(stack *s, char *value) {
    if (isStackEmpty(s)) {
        printf("栈为空，无法出栈\n");
        return false;
    }
    s->top--;           // 栈顶指针下移
    *value = *(s->top); // 获取栈顶元素
    return true;
}

// 查看栈顶元素
char Stack_checkTop(stack *s) {
    if (isStackEmpty(s)) {
        printf("栈为空，无栈顶元素\n");
        return '\0';  // 用空字符表示错误
    }
    return *(s->top - 1);  // 注意栈顶指针指向的是下一个空位置
}

// 获取当前栈中元素个数
int Stack_getSize(stack *s) {
    return s->top - s->base;
}

// 打印栈中所有元素
void print_Stack(stack *s) {
    if (isStackEmpty(s)) {
        printf("栈为空\n");
        return;
    }
    
    printf("栈中元素（从栈底到栈顶）: ");
    char *p = s->base;
    while (p < s->top) {
        printf("%c ", *p);
        p++;
    }
    printf("\n");
}
