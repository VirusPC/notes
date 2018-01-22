#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXL 50

typedef int KeyType;//KeyType为关键字的数据类型

typedef struct
{
	KeyType id;
	char name[20];
	int length;
}NodeType;

typedef struct
{
	KeyType key;//KeyType为关键字的类型
	int link;//指向对应块的起始下标
	int length;//索引表长度
}IdxType;

NodeType * CreateList(int n);								  //建立顺序表
IdxType * CreateIDX(NodeType * R);							  //建立索引表
void ListInsert(NodeType * R,int id,char name[20]);			  //插入数据并排序
int Seqsearch(NodeType * R, int n, KeyType k);				  //顺序查找
int BinSearch(NodeType * R, int n, KeyType k);				  //折半查找
int IdxSearch(IdxType * I,int m,NodeType * R,int n,KeyType k);//分块查找
void DispList(NodeType * R);							  	  //输出线性表

int main(){
	int id,choice,stu,n,i;
	char name[20];
	NodeType * R;
	IdxType * I;
	R=CreateList(MAXL);
	printf("请输入要输入学生的数量:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("请输入学生%d的学号和姓名：\n",i);
		id=i;
		scanf("%s",name);
		ListInsert(R,id,name);
		getchar();
	}
	I=CreateIDX(R);
	while(1)
	{
		printf("\n1.顺序查找\n2.折半查找\n3.分块查找\n4.全部打印\n");
		printf("请选择:\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
		case 1:
			{
				printf("请输入学号\n");
				scanf("%d",&id);
				stu=Seqsearch(R,R->length,id);
				if(stu==0)
					printf("不存在");
				else
					printf("学号：%d\t姓名：%s\n",R[stu-1].id,R[stu-1].name);
				break;
			}
		case 2:
			{
				printf("请输入学号\n");
				scanf("%d",&id);
				stu=BinSearch(R,R->length,id);
				if(stu==0)
					printf("不存在");
				else
					printf("学号：%d\t姓名：%s\n",R[stu-1].id,R[stu-1].name);
				break;
			}
		case 3:
			{
				printf("请输入学号\n");
				scanf("%d",&id);
				stu=IdxSearch(I,I->length,R,R->length,id);
				if(stu==0)
					printf("不存在\n");
				else
					printf("学号：%d\t姓名：%s\n",R[stu-1].id,R[stu-1].name);
				break;
				break;
			}
		case 4:
			{
				DispList(R);
				break;
			}
		default:
			{
				printf("输入错误请重新输入");
			}
		}
	}
	return 0;
}

IdxType * CreateIDX(NodeType * R)//建立索引表
{
	IdxType * I;
	int m,i;
	if(R->length>=5)
		m=R->length/5;//每五个一块,最后一块>=5个
	else
		m=1;//长度小于5时分一块
	I=(IdxType * )malloc(m*sizeof(IdxType));
	I->length=m;
	for(i=0;i<m;i++)
	{
		if((i+1)*5==R->length || (i+1)<m)
		{
			I[i].link=i*5;//起始下标
			I[i].key=R[(i+1)*5-1].id;//最大关键字
		}
		else
		{
			I[i].link=i*5;
			I[i].key=R[R->length-1].id;
		}
	}
	return I;
	
}

int Seqsearch(NodeType * R, int n, KeyType k)//顺序查找
{
	int i=0;
	while(i<n && R[i].id!=k)//从表头开始查找
		i++;
	printf("查找了%d次\n",i+1);
	if(i>=n)
		return 0;//未找到返回0
	else
		return i+1;//找到返回逻辑序号i+1
}

int BinSearch(NodeType * R, int n, KeyType k)//折半查找
{
	int low=0,high=n-1,mid,i=0;
	while(low<=high)//当前区间存在元素时循环
	{
		mid = (low+high)/2;
		if(R[mid].id==k)//查找成功是返回其逻辑符号mid+1
		{
			printf("查找了%d次\n",i+1);
			return mid+1;
		}
		i++;
		if(R[mid].id>k)
			high=mid-1;
		else
			low=mid+1;//继续在R[mid+1,high]中查找
	}
	printf("查找了%d次\n",i+1);
	return 0;
}

int IdxSearch(IdxType * I,int m,NodeType * R,int n,KeyType k)//分块查找
{
	int low=0,high=m-1,mid,i,j=0;
	int s=ceil((double)n/(double)m);//s为每块的元素个数，应为n/b的向上取整
	while(low<=high)//在索引表中进行折半查找，找到的位置为high+1
	{
		mid=(low+high)/2;
		if(I[mid].key>=k)
			high=mid-1;
		else
			low=mid+1;
		j++;
	}
	//应在索引表的high+1块中，再在对应的线性表中尽享顺序查找

	if(high+1>=m)
	{
		printf("查找了%d次\n",j+2);
		return 0;
	}
	i=I[high+1].link;

	while(i<I[high+1].link+s-1&&R[i].id!=k)
	{
		i++;
		j++;
	}
	printf("qgwehrhwhtahaagagagagG\n");
	printf("查找了%d次\n",j+2);
	if(i<I[high+1].link+s)
		return i+1;//查找成功，返回该元素的逻辑符号
	else
			printf("查找了%d次\n",j+2);
		return 0;//查找失败返回0
}

NodeType * CreateList(int n)						//建立顺序表
{
	NodeType * R;
	R=(NodeType * )malloc(sizeof(NodeType)*n);		
	R->length=0;								
	return R;
}

void ListInsert(NodeType * R,int id,char name[20])	//插入数据并排序
{
	int i,j;
	for(i=0;i<R->length && id>R[i].id;i++);		
	if(i<MAXL)
	{
		for(j=R->length;j>i;j--)	
		{
			R[j].id=R[j-1].id;
			strcpy(R[j].name,R[j-1].name);
		}
		R[i].id=id;
		strcpy(R[i].name,name);
		R->length++;
	}
	else
		printf("插入失败\n");
}

void DispList(NodeType * R)						//输出线性表
{
	int i;
	printf("学号\t姓名\n");
	for(i=0;i<R->length;i++)					
		printf("%d\t%s\n",R[i].id,R[i].name);
	printf("\n");
}
