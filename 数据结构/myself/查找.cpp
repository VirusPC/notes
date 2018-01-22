#include<stdio.h>

#define MAXL 50

typedef int KeyType;//KeyType为关键字的数据类型
typedef struct
{
	int name;
}InfoType;
typedef struct
{
	KeyType key;
	InfoType data;//其他数据
}NodeType;
typedef NodeType SeqList[50];//顺序表类型为SeqList

int Seqsearch(SeqList R, int n, KeyType k)
{
	int i=0;
	while(i<n && R[i].key!=k)//从表头开始查找
		i++;
	if(i>n)
		return 0;//未找到返回0
	else
		return i+1;//找到返回逻辑序号i+1
}

int BinSearch(SeqList R, int n, KeyType k)//折半查找
{
	int low=0,high=n-1,mid;
	while(low<=high)//当前区间存在元素时循环
	{
		mid = (low+high)/2;
		if(R[mid].key==k)//查找成功是返回其逻辑符号mid+1
			return mid+1;
		if(R[mid].key>k)
			high=mid-1;
		else
			low=mid+1;//继续在R[mid+1,high]中查找
	}
	return 0;
}
int main(){
	SeqList Stu;
	Stu[1].key=1;
}
