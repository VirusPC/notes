#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	int Num;
	char name[20];
} ElemType;

typedef struct
{
	ElemType data;
	int length;
	int count;
}SqList;

SqList * CreateList(int n);						//建立顺序表
void DispList(SqList * L);						//输出线性表
void ListInsert(SqList * L,int a,char b[20]);	//插入数据并排序
void ListDelete(SqList * L,int a);	//删除数据

int main(){
	int MaxSize, choice,xuehao;
	char xingming[10];
	
	SqList * sql;
	printf("请输入最多保存的学生数量\n");
	scanf("%d",&MaxSize);
	
	
	sql=CreateList(MaxSize);
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
				ListInsert(sql,xuehao,xingming);
				break;
			}
		case 2:
			{
				printf("请输入要删除学生的学号\n");
				scanf("%d",&xuehao);
				ListDelete(sql,xuehao);
				break;
			}
		case 3:
			{
				DispList(sql);
			}
		}
	}
}
SqList * CreateList(int n)						//建立顺序表
{
	SqList * L;
	L=(SqList * )malloc(sizeof(SqList)*n);		
	L->length=n;
	L->count=0;								
	return L;
}

void DispList(SqList * L)						//输出线性表
{
	int i;
	printf("学号\t姓名\n");
	for(i=0;i<L->count;i++)					
		printf("%d\t%s\n",L[i].data.Num,L[i].data.name);
	printf("\n");
}

void ListInsert(SqList * L,int a,char b[20])	//插入数据并排序
{
	int i,j;
	for(i=0;i<L->count && a>L[i].data.Num;i++);		
	if(i<L->length)
	{
		for(j=L->count;j>i;j--)	
		{
			L[j].data=L[j-1].data;
		}
		L[i].data.Num=a;
		strcpy(L[i].data.name,b);
		L->count++;
	}
	else
		printf("插入失败\n");
}

void ListDelete(SqList * L,int a)	//删除数据
{
	int j,i=0;
	while(i<L->count && L[i].data.Num!=a)
		i++;
	if(i<L->count)
	{	
		for(j=i;j<L->count-1;j++)	
		{
			L[j].data=L[j+1].data;
		}
	}	
	else
		printf("删除失败\n");
	L->count--;																
}
