#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	int Num;
	char name[10];
} ElemType;

	typedef struct
	{
		ElemType data;
		int length;
	}SqList;

SqList * CreateList(int n);//��a�е�n��Ԫ�ؽ���˳���
void InitList(SqList * L);						//��ʼ�����Ա�
void DestroyList(SqList * L);					//�������Ա�
int ListLength(SqList * L);						//�����Ա�ĳ���
void DispList(SqList * L);						//������Ա�
void GetElem(SqList * L,int i);		//�����Ա���ĳ������Ԫ��ֵ(L,i,e)
void LocateElem(SqList * L,int a,char b[10]);	//��Ԫ��ֵ����LocateElem(L,e)
void ListInsert(SqList * L,int i,int a,char b[10]);	//��������Ԫ��ListInsert(L,i,e)
void ListDelete(SqList * L,int a,int b[10]);	//ɾ������Ԫ��

int main(){
	int MaxSize;
	int a;
	
	SqList * sql;
	printf("��������ౣ���ѧ������");
	scanf("%d",&MaxSize);
	
	
	sql=CreateList(MaxSize);
	return 0;
}

SqList *  CreateList(int n)//��a�е�n��Ԫ�ؽ���˳���
{
	SqList * L;
	L=(SqList * )malloc(sizeof(SqList));		//���������Ա�Ŀ�
	L->length=n;								//���ó���
	return L;
}

void InitList(SqList * L)						//��ʼ�����Ա���
{
	L=(SqList *)malloc(sizeof(SqList));			//���������Ա�Ŀռ�
	L->length=0;								//�ÿ����Ա���Ϊ0
}

void DestroyList(SqList * L)					//�������Ա�
{
	free(L);
}
	


int ListLength(SqList * L)						//�����Ա�ĳ���
{
	return (L->length);
}

void DispList(SqList * L)						//������Ա�
{
	int i;
	for(i=0;i<L->length;i++)					//ɨ��˳��������Ԫ��ֵ
		printf("%d\r%c\n",L[i].data.Num,L[i].data.name);
	printf("\n");
}

void GetElem(SqList * L,int i)		//�����Ա���ĳ������Ԫ��ֵ(L,i,e)
{
	if(i<1 || i>L->length)
		printf("������");
    else							
		printf("%d\r%d\n",L[i-1].data.Num,L[i-1].data.name);
}
void LocateElem(SqList * L,int a,char b[10])	//��Ԫ��ֵ����LocateElem(L,e)
{
	int i=0;
	while(i<L->length && L[i].data.Num!=a && strcmp(L[i].data.name,b)!=0)
		i++;									//����Ԫ��e
	if(i>=L->length)							
		printf("������");
	else
		printf("%d\r%c\n",L[i+1].data.name),L[i+1].data.Num;								//�ҵ��󷵻����߼����
}

void ListInsert(SqList * L,int i,int a,char b[10])	//��������Ԫ��ListInsert(L,i,e)
{
	int j;
	if(i<1 || i>L->length+1)
		printf("����ʧ��");							//��������ʱ����faulse
	i--;										//��˳����߼�����ת��Ϊ�������
	for(j=L->length;j>i;j--)					//��data[i]������Ԫ�غ���һ��λ��
	{
		L[j].data.Num=L[j-1].data.Num;
		strcpy(L[j].data.name,L[j-1].data.name);
	}
	L[i].data.Num=a;
	strcpy(L[i].data.name,b);
	L->length++;								//˳�������1								//�ɹ����뷵��true
}

void ListDelete(SqList * L,int a,int b[10])	//ɾ������Ԫ��
{
	int j,i=0;
	while(i<L->length && L[i].data.Num!=a && strcmp(L[i].data.name,b)!=0)
		i++;
	for(j=i;j<L->length-1;j++)					//��data[i]֮���Ԫ��ǰ��һ��λ��
	{
		L[j].data.Num=L[j+1].data.Num;
		strcmp(L[j].data.name,L[j+1].data.name);
	}
	L->length--;								//˳����ȼ�һ								
}
