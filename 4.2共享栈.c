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

//��ջ����ռ�
typedef struct{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status visit(SElemType c){
	printf("%d ",c);
	return OK; 
}
//����һ����ջ
Status InitStack(SqDoubleStack *S){
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK; 
} 

//��S��Ϊ��ջ��������Ĺ���һ����ջ������һ���� 
Status ClearStack(SqDoubleStack *S){
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
} 

//�ж��Ƿ�Ϊ��ջ;����Ҫ��Ϊ�� 
Status StackEmpty(SqDoubleStack S){
	if(S.top1==-1&&S.top2==MAXSIZE)
		return TRUE;
	else
		return FALSE;
} 

//����Ԫ�ظ�������ջ��
int StackLength(SqDoubleStack S){
	return (S.top1+1)+(MAXSIZE-S.top2);
} 

//����Ԫ�أ���Ҫ��������ĸ�����push,ֻ��Ҫ�ж��ܵ�ջ�Ƿ��� 
Status Push(SqDoubleStack *S,SElemType e,int stackNumber){
	if(S->top1+1==S->top2)
		return ERROR;
	if(stackNumber==1)
		S->data[++S->top1]=e;
	else if(stackNumber==2)
		S->data[--S->top2]=e;
	return OK;
} 

//ɾ��ջ����Ԫ�أ���Ҫ�ֱ��ж�ÿ���Ƿ�Ϊ�� 
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber){
	if(stackNumber==1){
		if(S->top1==-1)
			return ERROR;
		*e=S->data[S->top1--];//�൱��������䣬һ���ǰ�ջ��Ԫ�ط��أ�һ����ָ��ָ��ǰһ�� 
	} 
	else if(stackNumber==2){
		if(S->top2==MAXSIZE)
			return ERROR;
		*e=S->data[S->top2++];
	} 
	return OK;
} 

//�����������ÿһ��Ԫ��
Status StackTraverse(SqDoubleStack S){
	int i;
	i=0;
	while(i<=S.top1){
		visit(S.data[i++]);
	}
	i=S.top2;//�м���ಿ�ֲ���� 
	while(i<MAXSIZE){//MAXSIZEʵ�����������±��1 
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
	printf("ջ�е�Ԫ������Ϊ��");
	StackTraverse(s);
	printf("��ǰջ��Ԫ���У�%d\n",StackLength(s));
	
	Pop(&s,&e,2);
	printf("������ջ��Ԫ�� e=%d\n",e);
	printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
	
	for(j=6;j<=MAXSIZE-2;j++)
		Push(&s,j,1);
		
	printf("ջ�е�Ԫ������Ϊ��");
	StackTraverse(s);
	
	printf("ջ����: %d(1:�� 0:��)\n",Push(&s,100,1));
	
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));		
}
