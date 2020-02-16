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

//顺序栈结构
typedef struct{
	SElemType data[MAXSIZE];
	int top;
}SqStack; 

Status visit(SElemType c){
	printf("%d ",c);
	return OK;
}

//构造一个空栈 
Status InitStack(SqStack *S){
	S->top=-1;
	return OK;
} 

//把S置为空栈
Status ClearStack(SqStack *S){
	S->top=-1;
	return OK;
} 

//判断是否为空栈
Status StackEmpty(SqStack S){
	if(S.top==-1)
		return TRUE;
	else 
		return FALSE;
} 

//返回栈的长度
int StackLength(SqStack S){
	return S.top+1;
} 

//若栈不空，用e返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(SqStack S,SElemType *e){
	if(S.top==-1)
		return ERROR;
	else
		*e=S.data[S.top];
	return OK; 
} 

//插入元素e为新的栈顶元素
Status Push(SqStack *S,SElemType e){
	if(S->top==MAXSIZE-1)
	{
		return ERROR;
	}
	S->top++;
	S->data[S->top]=e;
	return OK;
} 

//删除栈顶元素
Status Pop(SqStack *S,SElemType *e){
	if(S->top==-1)
		return ERROR;
	else{
		*e=S->data[S->top];
		S->top--;
	return OK; 	
	} 
} 

//从栈底到栈顶以此对每一个元素进行显示
Status StackTraverse(SqStack S){
	int i;
	i=0;
	while(i<=S.top){
		visit(S.data[i++]);
	}
	printf("\n");
	return OK; 
} 

int main(){
	int j;
	SqStack s;
	int e;
	if(InitStack(&s)==OK)//判断一下更把握 
		for(j=1;j<=10;j++)
			Push(&s,j);
	printf("栈中元素以此为： ");
	StackTraverse(s);
	Pop(&s,&e);//e用来返回弹出的值
	printf("弹出的栈顶元素为e=%d\n",e);
	printf("栈是否空：%d(1:空 0:不空)\n",StackEmpty(s));
	GetTop(s,&e);
	printf("栈顶元素为e=%d 栈的长度为%d\n",e,StackLength(s));
	ClearStack(&s);
	printf("栈清空后，栈是否空：%d(:空 0:不空)",StackEmpty(s));
}

