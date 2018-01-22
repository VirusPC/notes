#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	int Num;
	char name[20];
} ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkList;

LinkList * CreateList();						//����˳���
void DispList(LinkList * L);						//������Ա�
void ListInsert(LinkList * L,int a,char b[20]);	//�������ݲ�����
void ListDelete(LinkList * L,int a,char b[20]);	//ɾ������

int main(){
	int  xuehao,choice;
	char xingming[10];
	
	LinkList * link;
	
	link=CreateList();
	while(1)
	{
		printf("\n1.��������\n2.ɾ������\n3.��ӡȫ������\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			{
				printf("������ѧ����ѧ�ź�������\n");
				scanf("%d%s",&xuehao,xingming);
				ListInsert(link,xuehao,xingming);
				break;
			}
		case 2:
			{
				printf("������Ҫɾ��ѧ����ѧ�ź�����\n");
				scanf("%d%s",&xuehao,xingming);
				ListDelete(link,xuehao,xingming);
				break;
			}
		case 3:
			{
				DispList(link);
			}
		}
	}
}
LinkList * CreateList()						//����˳���
{
	LinkList * L;
	L=(LinkList * )malloc(sizeof(LinkList));		
	L->next=NULL;								
	return L;
}

void DispList(LinkList * L)						//������Ա�
{
	LinkList * p=L->next;
	printf("ѧ��\t����\n");
	while(p!=NULL)
	{
		printf("%d\t%s\n",p->data.Num,p->data.name);
		p=p->next;
	}
	printf("\n");
}

void ListInsert(LinkList * L,int a,char b[20])	//�������ݲ�����
{
	LinkList * p=L,* s;
	while(p->next!=NULL && p->next->data.Num<a)
	{
		p=p->next;
	}
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data.Num=a;
	strcpy(s->data.name,b);
	s->next=p->next;
	p->next=s;
}

void ListDelete(LinkList * L,int a,char b[20])	//ɾ������
{
	int i=0;
	LinkList * p=L,*q;
	while(p->next!=NULL && p->next->data.Num!=a && p->next->data.name!=b)
	{
		p=p->next;
	}
	if(p->next!=NULL)
	{	
		q=p->next;
		p->next=q->next;
		free(q);
	}	
	else
		printf("ɾ��ʧ��\n");															
}
