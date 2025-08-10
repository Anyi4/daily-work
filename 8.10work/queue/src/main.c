#include <stdio.h>
#include <stdlib.h>
#include "../inc/queue.h" 

//使用时可以进行选择
void Queue_choose(queue *q);

// 功能选择函数
void Queue_choose(queue *q) {
    int choice;
    int value;
    int *p_value = &value;

    // 显示菜单
    printf("\n循环队列操作菜单\n");
    printf("1. 入队\n");
    printf("2. 出队\n");
    printf("3. 查看队头\n");
    printf("4. 打印队列\n");
    printf("5. 查看队列是否为空\n");
    printf("6. 查看队列是否已满\n");
    printf("0. 退出程序\n");
    printf("请输入操作编号(0-6): ");
    
    // 读取输入
    if (scanf("%d", &choice) != 1) {
        // 处理非数字输入
        printf("输入错误！请输入数字(0-6)。\n");
        // 清除输入缓冲区
        while (getchar() != '\n');
        Queue_choose(q); // 递归调用，返回菜单
        return;
    }

    // 根据选择执行对应操作
    switch (choice) {
        //入队
        case 1:
            printf("请输入要入队的整数: ");
            if (scanf("%d", &value) == 1) {
                if (inQueue(q, value)) {
                    printf("%d 已成功入队\n", value);
                } else {
                    printf("入队失败，队列已满！\n");
                }
            } else {
                printf("输入错误！入队操作取消。\n");
                while (getchar() != '\n'); // 清除缓冲区
            }
            Queue_choose(q);
            break;
        
        //出队
        case 2:
            if (outQueue(q, p_value)) {
                printf("出队成功，出队元素为: %d\n", value);
            } else {
                printf("出队失败，队列为空！\n");
            }
            Queue_choose(q);
            break;
        
        //查看队头
        case 3:
            Queue_checkfront(q);
            Queue_choose(q);
            break;
        
        //打印队列
        case 4:
            printf("当前队列内容如下:\n");
            print_Queue(q);
            Queue_choose(q);
            break;
        
        //队列是否为空
        case 5:
            printf("队列%s空\n", isQueueEmpty(q) ? "为" : "未");
            Queue_choose(q);
            break;
        
        //队列是否已满
        case 6:
            printf("队列%s满\n", isQueueFull(q) ? "已" : "未");
            Queue_choose(q);
            break;
        
        //退出
        case 0:
            printf("程序已退出\n");
            exit(0); 
            break;
        
        default:
            printf("输入错误!请输入0-6之间的数字。\n");
            Queue_choose(q); 
            break;
    }
}

int main()
{
    queue q_test;  // 定义队列变量
    Queue_init(&q_test);  // 初始化队列
    Queue_choose(&q_test);  // 调用菜单函数
    
    return 0;
}
