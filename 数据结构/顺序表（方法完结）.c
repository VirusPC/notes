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

SqList * CreateList(int n);//由a中的n个元素建立顺序表
void InitList(SqList * L);						//初始化线性表
void DestroyList(SqList * L);					//销毁线性表
int ListLength(SqList * L);						//求线性表的长度
void DispList(SqList * L);						//输出线性表
void GetElem(SqList * L,int i);		//求线性表中某个数据元素值(L,i,e)
void LocateElem(SqList * L,int a,char b[10]);	//按元素值查找LocateElem(L,e)
void ListInsert(SqList * L,int i,int a,char b[10]);	//插入数据元素ListInsert(L,i,e)
void ListDelete(SqList * L,int a,int b[10]);	//删除数据元素

int main(){
	int MaxSize;
	int a;
	
	SqList * sql;
	printf("请输入最多保存的学生数量");
	scanf("%d",&MaxSize);
	
	
	sql=CreateList(MaxSize);
	return 0;
}

SqList *  CreateList(int n)//由a中的n个元素建立顺序表
{
	SqList * L;
	L=(SqList * )malloc(sizeof(SqList));		//分配存放线性表的空
	L->length=n;								//设置长度
	return L;
}

void InitList(SqList * L)						//初始化线性表让
{
	L=(SqList *)malloc(sizeof(SqList));			//分配存放线性表的空间
	L->length=0;								//置空线性表长度为0
}

void DestroyList(SqList * L)					//销毁线性表
{
	free(L);
}
	


int ListLength(SqList * L)						//求线性表的长度
{
	return (L->length);
}

void DispList(SqList * L)						//输出线性表
{
	int i;
	for(i=0;i<L->length;i++)					//扫描顺序表输出各元素值
		printf("%d\r%c\n",L[i].data.Num,L[i].data.name);
	printf("\n");
}

void GetElem(SqList * L,int i)		//求线性表中某个数据元素值(L,i,e)
{
	if(i<1 || i>L->length)
		printf("不存在");
    else							
		printf("%d\r%d\n",L[i-1].data.Num,L[i-1].data.name);
}
void LocateElem(SqList * L,int a,char b[10])	//按元素值查找LocateElem(L,e)
{
	int i=0;
	while(i<L->length && L[i].data.Num!=a && strcmp(L[i].data.name,b)!=0)
		i++;									//查找元素e
	if(i>=L->length)							
		printf("不存在");
	else
		printf("%d\r%c\n",L[i+1].data.name),L[i+1].data.Num;								//找到后返回其逻辑序号
}

void ListInsert(SqList * L,int i,int a,char b[10])	//插入数据元素ListInsert(L,i,e)
{
	int j;
	if(i<1 || i>L->length+1)
		printf("插入失败");							//参数错误时返回faulse
	i--;										//将顺序表逻辑符号转化为物理符号
	for(j=L->length;j>i;j--)					//将data[i]及后面元素后移一个位置
	{
		L[j].data.Num=L[j-1].data.Num;
		strcpy(L[j].data.name,L[j-1].data.name);
	}
	L[i].data.Num=a;
	strcpy(L[i].data.name,b);
	L->length++;								//顺序表长度增1								//成功插入返回true
}

void ListDelete(SqList * L,int a,int b[10])	//删除数据元素
{
	int j,i=0;
	while(i<L->length && L[i].data.Num!=a && strcmp(L[i].data.name,b)!=0)
		i++;
	for(j=i;j<L->length-1;j++)					//将data[i]之后的元素前移一个位置
	{
		L[j].data.Num=L[j+1].data.Num;
		strcmp(L[j].data.name,L[j+1].data.name);
	}
	L->length--;								//顺序表长度减一								
}
