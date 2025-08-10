#include "../inc/queue.h"


//初始化队列
void Queue_init(queue *q)
{
    q->front=q->rear=0;
    q->count=0;
}

//判断队列是否已满
bool isQueueFull(queue *q)
{
    //return (q->rear - q->front>=Queue_max_size);
    return(q->count == Queue_max_size);
}

//判断队列是否为空
bool isQueueEmpty(queue *q)
{
    return (q->count==0);
}

//入队操作
bool inQueue(queue *q,int value)
{
    if(isQueueFull(q))
        return 0;
    else
    {
        q->data[q->rear]=value;
        q->rear=(q->rear+1)%Queue_max_size;
        q->count=(q->count+1);
        return 1;
    }
}

//出队操作
bool outQueue(queue *q,int *value)
{
    if(isQueueEmpty(q))
        return 0;
    else
    {
        *value=q->data[q->front];
        printf("%d已出队\n",*value);
        q->front=(q->front+1)%Queue_max_size;
        q->count=(q->count-1);
        return 1;
    }
}

//查看队头
int Queue_checkfront(queue *q)
{
    if (isQueueEmpty(q)) 
    {
        printf("队列为空\n");
        return -1; // 表示错误
    }
    int front_val = q->data[q->front];
    printf("队头为：%d\n", front_val);
    return front_val;
    
}

//打印队列
void print_Queue(queue *q)
{
    if (isQueueEmpty(q)) {
        printf("队列为空\n");
        return;
    }
    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("队列第%d个数据为%d\n", i + 1, q->data[index]);
        index = (index + 1) % Queue_max_size;
    }
}





