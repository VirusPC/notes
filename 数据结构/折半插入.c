#include<stdio.h>
#include<string.h>
//#define RecType int;
void InsertSort1(int R[] ,int n)
{
	int i,j,low,high,mid;
	int tmp;
	for(i=1;i<n;i++)
	{
		tmp=R[i];
		low=0;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(tmp<R[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)
			R[j+1]=R[j];
		R[high+1]=tmp;
	}
}
void main(){
	int i;
	int R[5]={3,4,1,5,2};
//	i=strlen(R);
	InsertSort1(R,5);
	for(i=0;i<5;i++)
	{
		printf("%d",R[i]);
	}
}
