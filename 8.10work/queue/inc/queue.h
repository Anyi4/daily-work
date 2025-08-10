#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdbool.h>


//定义结构体
#define Queue_max_size 20
typedef struct Queue{
    int data[Queue_max_size];  //存储用数组
    int front;                 // 队首指针
    int rear;                  // 队尾指针
    int count;                 // 队列中元素数量
}queue;

//初始化
void Queue_init(queue *q);

//判断队列是否已满
bool isQueueFull(queue *q);

//判断队列是否为空
bool isQueueEmpty(queue *q);

//入队操作
bool inQueue(queue *q,int value);

//出队操作
bool outQueue(queue *q,int *value);

//查看队头
int Queue_checkfront(queue *q);

//打印队列
void print_Queue(queue *q);

//选择功能
void Queue_choose(queue *q);


#endif