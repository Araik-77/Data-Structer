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
typedef int SElemType; 

//两栈共享空间
typedef struct{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status visit(SElemType c){
	printf("%d ",c);
	return OK; 
}
//构造一个空栈
Status InitStack(SqDoubleStack *S){
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK; 
} 

//把S置为空栈；和上面的构造一个空栈代码是一样的 
Status ClearStack(SqDoubleStack *S){
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
} 

//判断是否为空栈;两个要都为空 
Status StackEmpty(SqDoubleStack S){
	if(S.top1==-1&&S.top2==MAXSIZE)
		return TRUE;
	else
		return FALSE;
} 

//返回元素个数，即栈长
int StackLength(SqDoubleStack S){
	return (S.top1+1)+(MAXSIZE-S.top2);
} 

//插入元素，需要标记是往哪个里面push,只需要判断总的栈是否满 
Status Push(SqDoubleStack *S,SElemType e,int stackNumber){
	if(S->top1+1==S->top2)
		return ERROR;
	if(stackNumber==1)
		S->data[++S->top1]=e;
	else if(stackNumber==2)
		S->data[--S->top2]=e;
	return OK;
} 

//删除栈顶的元素，需要分别判断每个是否为空 
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber){
	if(stackNumber==1){
		if(S->top1==-1)
			return ERROR;
		*e=S->data[S->top1--];//相当于两个语句，一个是把栈顶元素返回，一个是指针指向前一个 
	} 
	else if(stackNumber==2){
		if(S->top2==MAXSIZE)
			return ERROR;
		*e=S->data[S->top2++];
	} 
	return OK;
} 

//从左往右输出每一个元素
Status StackTraverse(SqDoubleStack S){
	int i;
	i=0;
	while(i<=S.top1){
		visit(S.data[i++]);
	}
	i=S.top2;//中间空余部分不输出 
	while(i<MAXSIZE){//MAXSIZE实际上是最大的下标加1 
		visit(S.data[i++]);
	}
	printf("\n");
	return OK; 
} 

int main(){
	int j,e;
	SqDoubleStack s;
	if(InitStack(&s)==OK){
		for(j=1;j<=5;j++)
			Push(&s,j,1);
		for(j=MAXSIZE;j>=MAXSIZE-2;j--)
			Push(&s,j,2);
	}
	printf("栈中的元素依次为：");
	StackTraverse(s);
	printf("当前栈中元素有：%d\n",StackLength(s));
	
	Pop(&s,&e,2);
	printf("弹出的栈顶元素 e=%d\n",e);
	printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
	
	for(j=6;j<=MAXSIZE-2;j++)
		Push(&s,j,1);
		
	printf("栈中的元素依次为：");
	StackTraverse(s);
	
	printf("栈满否: %d(1:否 0:满)\n",Push(&s,100,1));
	
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));		
}
