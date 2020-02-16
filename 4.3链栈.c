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

//链栈的结构,也可参考线性表的链式存储，效果是一样的 
typedef struct StackNode{//定义结点 
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct {//定义一个栈 
	LinkStackPtr top;//定义了一个指向结点的指针
	int count; 
}LinkStack;

Status visit(SElemType c){
	printf("%d ", c);
	return OK;
} 

//构造一个空栈
Status InitStack(LinkStack *S){
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
		return ERROR;
		S->top = NULL;
		S->count = 0;
		return OK;
} 

//把S置为空栈
Status ClearStack(LinkStack *S){
	LinkStackPtr p, q;//定义两个指向结点的指针 
	p = S->top;
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK; 
} 

//判断是否为空
Status StackEmpty(LinkStack S){
	if(S.count == 0)
		return TRUE;
	else 
		return FALSE;
} 

//返回栈的长度
int StackLength(LinkStack S){
	return S.count; 
} 

//用e返回栈顶元素
Status GetTop(LinkStack S, SElemType *e){
	if(S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	return OK;
} 

//插入元素为e的栈顶元素
Status Push(LinkStack *S, SElemType e){
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));//先定义栈顶结点 
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
} 

//删除栈顶的元素，并用e返回
Status Pop(LinkStack *S, SElemType *e){
	LinkStackPtr p;//先找结点再删除 
	if(StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK; 
} 

//从顶开始访问
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
	printf("栈中元素依次为: ");
	StackTraverse(s);
	Pop(&s, &e);
	printf("弹出栈顶元素 e = %d\n",e);
	printf("栈空否: %d(1:空 0:否)\n",StackEmpty(s));
	GetTop(s,&e);
	printf("栈顶元素 e = %d 栈的长度为%d\n", e,StackLength(s));
	ClearStack(&s);
	printf("清空后，栈空否: %d(1:空 0:否)\n",StackEmpty(s));
	return 0;
}
