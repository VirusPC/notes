#include<stdio.h>
#include<math.h>
#define MAXI 50
#define KeyType int 

typedef struct
{
	KeyType key;//KeyType为关键字的类型
	int link;//指向对应块的起始下标
}IdxType;
typedef IdxType IDX[MAXI];//索引表类型

int IdxSearch(IDX I,int b,SeqList R,int n,KeyType k)//b为索引表长度
{
	int low=0,high=m-1,mid,i;
	int s=ceil((double)n/b);//s为每块的元素个数，应为n/b的向上取整
	while(low<=high)//在索引表中进行折半查找，找到的位置为high+1
	{
		mid=(low+high)/2;
		if(I[mid].key>=k)
			high=mid-1;
		else
			low=mid+1;
	}
	//应在索引表的high+1块中，再在对应的线性表中尽享顺序查找
	i=I[high+1].link;
	while(i<I[high+1].link+s-1&&R[i].key!=k)
		i++;
	if(i<I[high+1].link+s-1)
		return i+1;//查找成功，返回该元素的逻辑符号
	else
		return 0;//查找失败返回0
}
int main(){}
