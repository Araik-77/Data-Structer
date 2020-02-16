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

//˳��ջ�ṹ
typedef struct{
	SElemType data[MAXSIZE];
	int top;
}SqStack; 

Status visit(SElemType c){
	printf("%d ",c);
	return OK;
}

//����һ����ջ 
Status InitStack(SqStack *S){
	S->top=-1;
	return OK;
} 

//��S��Ϊ��ջ
Status ClearStack(SqStack *S){
	S->top=-1;
	return OK;
} 

//�ж��Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S){
	if(S.top==-1)
		return TRUE;
	else 
		return FALSE;
} 

//����ջ�ĳ���
int StackLength(SqStack S){
	return S.top+1;
} 

//��ջ���գ���e����ջ��Ԫ�أ�������OK,���򷵻�ERROR
Status GetTop(SqStack S,SElemType *e){
	if(S.top==-1)
		return ERROR;
	else
		*e=S.data[S.top];
	return OK; 
} 

//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack *S,SElemType e){
	if(S->top==MAXSIZE-1)
	{
		return ERROR;
	}
	S->top++;
	S->data[S->top]=e;
	return OK;
} 

//ɾ��ջ��Ԫ��
Status Pop(SqStack *S,SElemType *e){
	if(S->top==-1)
		return ERROR;
	else{
		*e=S->data[S->top];
		S->top--;
	return OK; 	
	} 
} 

//��ջ�׵�ջ���Դ˶�ÿһ��Ԫ�ؽ�����ʾ
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
	if(InitStack(&s)==OK)//�ж�һ�¸����� 
		for(j=1;j<=10;j++)
			Push(&s,j);
	printf("ջ��Ԫ���Դ�Ϊ�� ");
	StackTraverse(s);
	Pop(&s,&e);//e�������ص�����ֵ
	printf("������ջ��Ԫ��Ϊe=%d\n",e);
	printf("ջ�Ƿ�գ�%d(1:�� 0:����)\n",StackEmpty(s));
	GetTop(s,&e);
	printf("ջ��Ԫ��Ϊe=%d ջ�ĳ���Ϊ%d\n",e,StackLength(s));
	ClearStack(&s);
	printf("ջ��պ�ջ�Ƿ�գ�%d(:�� 0:����)",StackEmpty(s));
}

