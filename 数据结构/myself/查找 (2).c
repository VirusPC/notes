#include<stdio.h>
#include<math.h>
#define MAXI 50
#define KeyType int 

typedef struct
{
	KeyType key;//KeyTypeΪ�ؼ��ֵ�����
	int link;//ָ���Ӧ�����ʼ�±�
}IdxType;
typedef IdxType IDX[MAXI];//����������

int IdxSearch(IDX I,int b,SeqList R,int n,KeyType k)//bΪ��������
{
	int low=0,high=m-1,mid,i;
	int s=ceil((double)n/b);//sΪÿ���Ԫ�ظ�����ӦΪn/b������ȡ��
	while(low<=high)//���������н����۰���ң��ҵ���λ��Ϊhigh+1
	{
		mid=(low+high)/2;
		if(I[mid].key>=k)
			high=mid-1;
		else
			low=mid+1;
	}
	//Ӧ���������high+1���У����ڶ�Ӧ�����Ա��о���˳�����
	i=I[high+1].link;
	while(i<I[high+1].link+s-1&&R[i].key!=k)
		i++;
	if(i<I[high+1].link+s-1)
		return i+1;//���ҳɹ������ظ�Ԫ�ص��߼�����
	else
		return 0;//����ʧ�ܷ���0
}
int main(){}
