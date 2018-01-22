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

LinkList * CreateList();						//建立顺序表
void DispList(LinkList * L);						//输出线性表
void ListInsert(LinkList * L,int a,char b[20]);	//插入数据并排序
void ListDelete(LinkList * L,int a,char b[20]);	//删除数据

int main(){
	int  xuehao,choice;
	char xingming[10];
	
	LinkList * link;
	
	link=CreateList();
	while(1)
	{
		printf("\n1.插入数据\n2.删除数据\n3.打印全部数据\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			{
				printf("请输入学生的学号和姓名：\n");
				scanf("%d%s",&xuehao,xingming);
				ListInsert(link,xuehao,xingming);
				break;
			}
		case 2:
			{
				printf("请输入要删除学生的学号和姓名\n");
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
LinkList * CreateList()						//建立顺序表
{
	LinkList * L;
	L=(LinkList * )malloc(sizeof(LinkList));		
	L->next=NULL;								
	return L;
}

void DispList(LinkList * L)						//输出线性表
{
	LinkList * p=L->next;
	printf("学号\t姓名\n");
	while(p!=NULL)
	{
		printf("%d\t%s\n",p->data.Num,p->data.name);
		p=p->next;
	}
	printf("\n");
}

void ListInsert(LinkList * L,int a,char b[20])	//插入数据并排序
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

void ListDelete(LinkList * L,int a,char b[20])	//删除数据
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
		printf("删除失败\n");															
}
