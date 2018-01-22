#include<stdio.h>

#define MAXL 50

typedef int KeyType;//KeyTypeΪ�ؼ��ֵ���������
typedef struct
{
	int name;
}InfoType;
typedef struct
{
	KeyType key;
	InfoType data;//��������
}NodeType;
typedef NodeType SeqList[50];//˳�������ΪSeqList

int Seqsearch(SeqList R, int n, KeyType k)
{
	int i=0;
	while(i<n && R[i].key!=k)//�ӱ�ͷ��ʼ����
		i++;
	if(i>n)
		return 0;//δ�ҵ�����0
	else
		return i+1;//�ҵ������߼����i+1
}

int BinSearch(SeqList R, int n, KeyType k)//�۰����
{
	int low=0,high=n-1,mid;
	while(low<=high)//��ǰ�������Ԫ��ʱѭ��
	{
		mid = (low+high)/2;
		if(R[mid].key==k)//���ҳɹ��Ƿ������߼�����mid+1
			return mid+1;
		if(R[mid].key>k)
			high=mid-1;
		else
			low=mid+1;//������R[mid+1,high]�в���
	}
	return 0;
}
int main(){
	SeqList Stu;
	Stu[1].key=1;
}
