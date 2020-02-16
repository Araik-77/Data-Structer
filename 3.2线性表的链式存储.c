#include<stdio.h>
#include<malloc.h>
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
	ElementType Data;
	List Next;
};
List L;
List MakeEmpty();
int Length(List);
List FindfKth(int K,List L);
List Find(ElementType X,List L);
List Insert(ElementType X,int i,List L);
List Delete(int i,List L);
void Print(List L);

List MakeEmpty(){
	List L=(List)malloc(sizeof(struct LNode));
	L=NULL;
	return L;
}

int Length(List L){
	List p=L;
	int len=0;
	while(p){
		p=p->Next;
		len++;
	}
	return len;
}
List FindKth(int K,List L){
	List p=L;
	int i=1;
	while(p&&i<K){
		p=p->Next;
		i++;
	}
	if(i==K)
		return p;
	else
		return NULL;
}
List Find(ElementType X,List L){
	List p=L;
	while(p&&p->Data!=X)
		p=p->Next;
	return p;
}
List Insert(ElementType X,int i,List L){
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct LNode));
		s->Data=X;
		s->Next=L;
		return s;
	}
	p=FindKth(i-1,L);
	if(!p){
		printf("������");
		return NULL; 
	}else{
		s=(List)malloc(sizeof(struct LNode));
		s->Data=X;
		s->Next=p->Next;
		p->Next=s;
		return L;
	}
}
List Delete(int i,List L){
	List p,s;
	if(i==1){
		s=L;
		if(L)
			L=L->Next;
		else
			return NULL;
		free(s);
		return L;
	}
	p=FindKth(i-1,L);
	if(!p||!(p->Next)){
		printf("������");
		return NULL; 
	}else{
		s=p->Next;
		p->Next=s->Next;
		free(s);
		return L;
	}
}
void Print(List L){
	List t;
	int flag=1;
	printf("��ǰ����Ϊ��");
	for(t=L;t;t=t->Next){
		printf("%d",t->Data);
		flag=0;
	} if(flag)
		printf("NULL");
	printf("\n");
}
int main(){
	L=MakeEmpty();
	Print(L);
	L=Insert(11,1,L);
	L=Insert(25,1,L);
	L=Insert(32,1,L);
	L=Insert(77,1,L);
	Print(L);
	printf("��ǰ�����ȣ�%d\n",Length(L));
	printf("��ǰ�����еڶ�������ֵ�ǣ�%d\n",FindKth(2,L)->Data);
	printf("��ѯ22�Ƿ��ڸ������У�");
	if(Find(22,L))
		printf("��\n");
	else
		printf("��\n");
	printf("��ѯ33�Ƿ��ڸ������У�");
	if(Find(33,L))
		printf("��\n");
	else
		printf("��\n");
	L=Delete(1,L);
	L=Delete(3,L);
	printf("------------ɾ����---------\n");
	Print(L);
	return 0; 
		 	 
}

