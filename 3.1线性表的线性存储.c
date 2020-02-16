#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
}; 
List L;

List MakeEmpty();
int Find(ElementType X,List L);
void Insert(ElementType X,int i,List L);
void Delete(int i,List L);
ElementType FindKth(int K,List L);

//初始化
List MakeEmpty(){
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->Last=-1;
	return L;
}
//按值查找 
int Find(ElementType X,List L){
	int i=0;
	while(i<=L->Last&&L->Data[i]!=X)
		i++;
	if(L->Last<i)
		return -1;
		else 
		return i;
}

//插入,下面的为头插法 
void Insert(ElementType X,int i,List L){
	int j;
	if(L->Last==MAXSIZE-1){
		printf("表满");
		return;
	}
	if(i<0||L->Last+1<i){
		printf("位置不合法");
		return; 
	}
	for(j=L->Last;j>=i;j--)
		L->Data[j+1]=L->Data[j];
		L->Data[i]=X;
		L->Last++;
		return;
} 

void Delete(int i,List L){
	int j;
	if(i<0||L->Last<i){
		printf("L->Data[%d]不存在元素",i);
		return;
	}
	for(j=i;j<L->Last;j++)//删除第i个元素，实际上对应的下标是i-1 
		L->Data[j-1]=L->Data[j];
		L->Last--;
		return; 
}
ElementType FindKth(int K,List L){
	if(K<0||L->Last<K){
		printf("L->Data[%d]不存在元素",K);
		return;
	}
	return L->Data[K];
}
int Length(List L){
	return L->Last+1;
}
int main(){
	int i=0;
	L=MakeEmpty();
	Insert(11,0,L);
	printf("在线性表L->Data[0]插入11\n");
	Insert(25,0,L);
	printf("在线性表L->Data[0]插入25\n");
	Insert(33,0,L);
	printf("在线性表L->Data[0]插入33\n");
	Insert(77,0,L);
	printf("在线性表L->Data[0]插入77\n");
	printf("此时线性表为；");
	for(i=0;i<Length(L);i++)
		printf("%d",L->Data[i]);
	printf("\n");
	printf("查找值为12的下标为：%d\n",Find(12,L));
	printf("下标为3的线性表的值是：%d\n",FindKth(3,L));
	Delete(2,L);
	printf("删除下标为2的元素\n"); 
	Delete(2,L);
	printf("删除下标为2的元素\n");  
		printf("此时线性表为；");
	for(i=0;i<Length(L);i++)
		printf("%d",L->Data[i]);
	printf("\n");
	return 0;
}
