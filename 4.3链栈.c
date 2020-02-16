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

//��ջ�Ľṹ,Ҳ�ɲο����Ա����ʽ�洢��Ч����һ���� 
typedef struct StackNode{//������ 
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct {//����һ��ջ 
	LinkStackPtr top;//������һ��ָ�����ָ��
	int count; 
}LinkStack;

Status visit(SElemType c){
	printf("%d ", c);
	return OK;
} 

//����һ����ջ
Status InitStack(LinkStack *S){
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
		return ERROR;
		S->top = NULL;
		S->count = 0;
		return OK;
} 

//��S��Ϊ��ջ
Status ClearStack(LinkStack *S){
	LinkStackPtr p, q;//��������ָ�����ָ�� 
	p = S->top;
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK; 
} 

//�ж��Ƿ�Ϊ��
Status StackEmpty(LinkStack S){
	if(S.count == 0)
		return TRUE;
	else 
		return FALSE;
} 

//����ջ�ĳ���
int StackLength(LinkStack S){
	return S.count; 
} 

//��e����ջ��Ԫ��
Status GetTop(LinkStack S, SElemType *e){
	if(S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	return OK;
} 

//����Ԫ��Ϊe��ջ��Ԫ��
Status Push(LinkStack *S, SElemType e){
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));//�ȶ���ջ����� 
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
} 

//ɾ��ջ����Ԫ�أ�����e����
Status Pop(LinkStack *S, SElemType *e){
	LinkStackPtr p;//���ҽ����ɾ�� 
	if(StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK; 
} 

//�Ӷ���ʼ����
Status StackTraverse(LinkStack S){
	LinkStackPtr p;
	p=S.top;
	while(p){
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
} 

int main(){
	int j;
	LinkStack s;
	int e;
	if(InitStack(&s) == OK)
		for(j = 1; j <= 10; j++)
			Push(&s, j);
	printf("ջ��Ԫ������Ϊ: ");
	StackTraverse(s);
	Pop(&s, &e);
	printf("����ջ��Ԫ�� e = %d\n",e);
	printf("ջ�շ�: %d(1:�� 0:��)\n",StackEmpty(s));
	GetTop(s,&e);
	printf("ջ��Ԫ�� e = %d ջ�ĳ���Ϊ%d\n", e,StackLength(s));
	ClearStack(&s);
	printf("��պ�ջ�շ�: %d(1:�� 0:��)\n",StackEmpty(s));
	return 0;
}
