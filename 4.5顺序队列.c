#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int QElemType;

// 循环队列的顺序结构
typedef struct{
	QElemType data[MAXSIZE];
	int front;
	int rear; 
}SqQueue;

Status visit(QElemType c){
	printf("%d ", c);
	return OK;
}
//初始化一个空队列
Status InitQueue(SqQueue *Q){
	Q->front = 0;
	Q->rear = 0;
	return OK; 
} 

//将Q清空
Status ClearQueue(SqQueue *Q){
	Q->front = Q->rear = 0;
	return OK;
} 

//判断是否为空 
Status QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
} 

//返回Q元素的个数
int QueueLength(SqQueue Q){
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
} 

//用e返回队列的队头元素
Status GetHead(SqQueue Q, QElemType *e){
	if(Q.front == Q.rear)
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
} 

//插入新的元素e
Status EnQueue(SqQueue *Q, QElemType e){
	if((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1)%MAXSIZE;
		return OK;
} 

//删除队头元素，用e返回
Status DeQueue(SqQueue *Q, QElemType *e){
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
} 

//从队头到队尾依次输出
Status QueueTraverse(SqQueue Q){
	int i;
	i = Q.front;
	while((i + Q.front) != Q.rear){
		visit(Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
	return OK;
} 
int main(){
	Status j;
	int i = 0, l;
	QElemType d;
	SqQueue Q;
	InitQueue(&Q);
	//%u表示无符号的十进制整数 
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ",MAXSIZE-1);
	do{
		d = i + 100;
		if(d == -1)
			break;
		i++;
		EnQueue(&Q,d); 
	}while(i < MAXSIZE - 1);
	printf("队列长度为: %d\n",QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	printf("连续%d次由队头删除元素,队尾插入元素:\n",MAXSIZE);
	for(l = 1; l <= MAXSIZE; l++){
		DeQueue(&Q,&d);
		printf("删除的元素是%d，插入的元素是：%d\n",d,l+1000);
		d = l + 1000;
		EnQueue(&Q, d);
	}
	l = QueueLength(Q);
	printf("现在的队列元素为：\n");
	QueueTraverse(Q);
	printf("共向队尾插入了%d个元素\n",i+MAXSIZE);
	if(l - 2 > 0)
		printf("现在由队头删除了%d个元素\n",l - 2);
	while(QueueLength(Q)>2){
		DeQueue(&Q,&d);
		printf("删除的元素为%d\n",d);
	}
	j = GetHead(Q,&d);
	if(j)
		printf("现在队头元素为：%d\n",d);
		ClearQueue(&Q);
		printf("清空队列后，队列空否？%u(1:空 0：否)\n",QueueEmpty(Q));
		return 0;
}
