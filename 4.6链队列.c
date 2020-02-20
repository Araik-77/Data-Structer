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

typedef struct QNode //���ڶ������Ľ�� 
{
   QElemType data;//������������� 
   struct QNode *next;//���� ����ָ���� 
}QNode,*QueuePtr;//����һ�����Զ���������ƣ�����һ��ָ�����ָ�� 

typedef struct		//��������Ľṹ�������������ָ��	
{
   QueuePtr front,rear; 
}LinkQueue;

Status visit(QElemType c)//���ڷ��ʽ��������� 
{
	printf("%d ",c);
	return OK;
}

/* ����һ���ն���Q */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	//�����СΪ���ṹ�Ķ�̬�ռ䣬��һ������Ϊָ����ָ�룬�ڶ�������Ϊ����С 
	if(!Q->front)
		exit(OVERFLOW);
	//xit(OVERFLOW)�ĺ�����ǣ��˳����򣬲�����OVERFLOW��ֵ���������̡�
	//���׼��ʹ�÷�ΧΪ�������������������ʱ���˳����򲢱�����������̡�
	Q->front->next=NULL;//ͷָ��Ϊջ�� 
	return OK;
}

/* ���ٶ���Q������ʲô��û���� ��ͷ��㶼�ͷŵ���*/
Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		 Q->rear=Q->front->next;
		 //�����Q->rear��һ����ʱָ��ʹ��ȡ��һ��ͷָ��ָ��Ľ��freeһ�� 
		 free(Q->front);
		 Q->front=Q->rear;
	}
	return OK;
}

/* ��Q��Ϊ�ն��У�ͷָ��βָ�뻹�ڣ���ָ��ͷ��� */
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p,q;
	Q->rear=Q->front;//�Ȱ�β���������ָ��ͷ��� 
	p=Q->front->next;//��Ҫɾ����ͷ������һ����p 
	Q->front->next=NULL;//��Ҫͷ���ָ����һ����ָ��ɾ���� 
	while(p)//һֱ�����һ����㶼�ͷŵ� 
	{
		 q=p;
		 p=p->next;
		 free(q);
	}
	return OK;
}

/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)//ָ����Ⱦ��ǿն��� ��Ҳ���Ƕ�ָ��ͷ��㣬ע��ͷ��㲻������ 
		return TRUE;
	else
		return FALSE;
}

/* ����еĳ��� */
int QueueLength(LinkQueue Q)
{ 
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
		 i++;//���ڼ��� 
		 p=p->next;//ָ����� 
	}
	return i;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)//���ж� 
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* �洢����ʧ�� */
		exit(OVERFLOW);
	s->data=e;//������Ҫ����Ľ��������� 
	s->next=NULL;//���������ָ����Ϊ�� 
	Q->rear->next=s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear=s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)//ʵ����ɾ���Ķ�ͷԪ����ͷ������һ�������� 
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	*e=p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next=p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	//���������൱��ָ������ȥ�� 
	if(Q->rear==p)		/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
		Q->rear=Q->front;
	free(p);
	return OK;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		 visit(p->data);
		 p=p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	int i;
	QElemType d;
	LinkQueue q;
	i=InitQueue(&q);
	if(i)
		printf("�ɹ��ع�����һ���ն���!\n");
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("��ͷԪ���ǣ�%d\n",d);
	DeQueue(&q,&d);
	printf("ɾ���˶�ͷԪ��%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("�µĶ�ͷԪ���ǣ�%d\n",d);
	ClearQueue(&q);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}


