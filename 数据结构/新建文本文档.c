#include<stdio.h>
#include<malloc.h>
	
typedef struct Stu//定义单链表节点类型
{
	int id;	//存放学号
	char name;//存放姓名
	struct Stu * next;//指向后继节点
}Student;

void InitList(LinkList * &L);//初始化线性表
void DestroyList(LinkList * &L)//销毁线性表
bool ListEmpty(LinkList);//判断线性表是否为空表
//bool InsertList(Sqlist* );//在指定位置插入一个元素
//void Delete(Sqlist* ,int);//删除指定位置的元素
//void Display(Sqlist* );//打印顺序表中所有元素
//void Sort(Sqlist*);//以学号升序进行排序
//void StuIn(Sqlist*);//判断该学生是否在表中
//int ListLength(Sqlist*);

int main()
{
	return 0;
}

void InitList(LinkList * &L)
{
	l=(Linklist*)malloc(sizeof(LinkList));
	L->next=NULLl;//创建头结点，其next域置为NULL
}

void DestroyList(LinkList * &L)
{
	LinkList * pre=L, * p=L->next;//pre指向 * p的前驱节点
	while(p!=NULL){//扫描单链表L
		free(pre);//释放 * pre 节点
		pre=p;//pre、p同步后移一个点
		p=pre->next
	}
	free(pre)//循环结束时，p为NULL，pre指向尾节点，释放它
}

bool ListEmpty(LinkList){
	return(L->next==NULL);
}

int ListLength(Linklist * L)
{
	int n=0;
	LinkList * p = L;
	while(p->next!=NULL)
	{
		n++;
		p->next;
	}
	return(n);
}