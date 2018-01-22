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

SqList * CreateList(int n);						//����˳���
void DispList(SqList * L);						//������Ա�
void ListInsert(SqList * L,int a,char b[20]);	//�������ݲ�����
void ListDelete(SqList * L,int a);	//ɾ������

int main(){
	int MaxSize, choice,xuehao;
	char xingming[10];
	
	SqList * sql;
	printf("��������ౣ���ѧ������\n");
	scanf("%d",&MaxSize);
	
	
	sql=CreateList(MaxSize);
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
				ListInsert(sql,xuehao,xingming);
				break;
			}
		case 2:
			{
				printf("������Ҫɾ��ѧ����ѧ��\n");
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
SqList * CreateList(int n)						//����˳���
{
	SqList * L;
	L=(SqList * )malloc(sizeof(SqList)*n);		
	L->length=n;
	L->count=0;								
	return L;
}

void DispList(SqList * L)						//������Ա�
{
	int i;
	printf("ѧ��\t����\n");
	for(i=0;i<L->count;i++)					
		printf("%d\t%s\n",L[i].data.Num,L[i].data.name);
	printf("\n");
}

void ListInsert(SqList * L,int a,char b[20])	//�������ݲ�����
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
		printf("����ʧ��\n");
}

void ListDelete(SqList * L,int a)	//ɾ������
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
		printf("ɾ��ʧ��\n");
	L->count--;																
}
