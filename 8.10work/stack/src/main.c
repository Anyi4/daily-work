#include <stdio.h>
#include "../inc/stack.h"

int main() {
    stack s;
    char pop_val;
    
    // 初始化栈
    printf("=== 初始化栈 ===\n");
    if (Stack_init(&s, 10)) {  // 初始化一个容量为10的栈
        printf("栈初始化成功，容量: %d\n", s.size);
    } else {
        printf("栈初始化失败\n");
        return 1;
    }
    
    // 测试入栈操作
    printf("\n=== 测试入栈操作 ===\n");
    char test_chars[] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < 5; i++) {
        if (push(&s, test_chars[i])) {
            printf("入栈成功: %c，当前栈大小: %d\n", test_chars[i], Stack_getSize(&s));
        }
    }
    
    // 打印栈元素
    printf("\n=== 打印栈元素 ===\n");
    print_Stack(&s);
    
    // 查看栈顶元素
    printf("\n=== 查看栈顶元素 ===\n");
    char top_val = Stack_checkTop(&s);
    if (top_val != '\0') {
        printf("当前栈顶元素: %c\n", top_val);
    }
    
    // 测试出栈操作
    printf("\n=== 测试出栈操作 ===\n");
    for (int i = 0; i < 3; i++) {
        if (pop(&s, &pop_val)) {
            printf("出栈成功: %c，当前栈大小: %d\n", pop_val, Stack_getSize(&s));
        }
    }
    
    // 再次打印栈
    printf("\n=== 出栈后打印栈 ===\n");
    print_Stack(&s);
    
    // 测试栈满情况
    printf("\n=== 测试栈满情况 ===\n");
    char more_chars[] = {'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    for (int i = 0; i < 7; i++) {
        if (push(&s, more_chars[i])) {
            printf("入栈成功: %c，当前栈大小: %d\n", more_chars[i], Stack_getSize(&s));
        }
    }
    
    // 销毁栈
    Stack_destroy(&s);
    printf("\n栈已销毁\n");
    
    return 0;
}
