#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXL 50

typedef int KeyType;//KeyTypeΪ�ؼ��ֵ���������

typedef struct
{
	KeyType id;
	char name[20];
	int length;
}NodeType;

typedef struct
{
	KeyType key;//KeyTypeΪ�ؼ��ֵ�����
	int link;//ָ���Ӧ�����ʼ�±�
	int length;//��������
}IdxType;

NodeType * CreateList(int n);								  //����˳���
IdxType * CreateIDX(NodeType * R);							  //����������
void ListInsert(NodeType * R,int id,char name[20]);			  //�������ݲ�����
int Seqsearch(NodeType * R, int n, KeyType k);				  //˳�����
int BinSearch(NodeType * R, int n, KeyType k);				  //�۰����
int IdxSearch(IdxType * I,int m,NodeType * R,int n,KeyType k);//�ֿ����
void DispList(NodeType * R);							  	  //������Ա�

int main(){
	int id,choice,stu,n,i;
	char name[20];
	NodeType * R;
	IdxType * I;
	R=CreateList(MAXL);
	printf("������Ҫ����ѧ��������:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("������ѧ��%d��ѧ�ź�������\n",i);
		id=i;
		scanf("%s",name);
		ListInsert(R,id,name);
		getchar();
	}
	I=CreateIDX(R);
	while(1)
	{
		printf("\n1.˳�����\n2.�۰����\n3.�ֿ����\n4.ȫ����ӡ\n");
		printf("��ѡ��:\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
		case 1:
			{
				printf("������ѧ��\n");
				scanf("%d",&id);
				stu=Seqsearch(R,R->length,id);
				if(stu==0)
					printf("������");
				else
					printf("ѧ�ţ�%d\t������%s\n",R[stu-1].id,R[stu-1].name);
				break;
			}
		case 2:
			{
				printf("������ѧ��\n");
				scanf("%d",&id);
				stu=BinSearch(R,R->length,id);
				if(stu==0)
					printf("������");
				else
					printf("ѧ�ţ�%d\t������%s\n",R[stu-1].id,R[stu-1].name);
				break;
			}
		case 3:
			{
				printf("������ѧ��\n");
				scanf("%d",&id);
				stu=IdxSearch(I,I->length,R,R->length,id);
				if(stu==0)
					printf("������\n");
				else
					printf("ѧ�ţ�%d\t������%s\n",R[stu-1].id,R[stu-1].name);
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
				printf("�����������������");
			}
		}
	}
	return 0;
}

IdxType * CreateIDX(NodeType * R)//����������
{
	IdxType * I;
	int m,i;
	if(R->length>=5)
		m=R->length/5;//ÿ���һ��,���һ��>=5��
	else
		m=1;//����С��5ʱ��һ��
	I=(IdxType * )malloc(m*sizeof(IdxType));
	I->length=m;
	for(i=0;i<m;i++)
	{
		if((i+1)*5==R->length || (i+1)<m)
		{
			I[i].link=i*5;//��ʼ�±�
			I[i].key=R[(i+1)*5-1].id;//���ؼ���
		}
		else
		{
			I[i].link=i*5;
			I[i].key=R[R->length-1].id;
		}
	}
	return I;
	
}

int Seqsearch(NodeType * R, int n, KeyType k)//˳�����
{
	int i=0;
	while(i<n && R[i].id!=k)//�ӱ�ͷ��ʼ����
		i++;
	printf("������%d��\n",i+1);
	if(i>=n)
		return 0;//δ�ҵ�����0
	else
		return i+1;//�ҵ������߼����i+1
}

int BinSearch(NodeType * R, int n, KeyType k)//�۰����
{
	int low=0,high=n-1,mid,i=0;
	while(low<=high)//��ǰ�������Ԫ��ʱѭ��
	{
		mid = (low+high)/2;
		if(R[mid].id==k)//���ҳɹ��Ƿ������߼�����mid+1
		{
			printf("������%d��\n",i+1);
			return mid+1;
		}
		i++;
		if(R[mid].id>k)
			high=mid-1;
		else
			low=mid+1;//������R[mid+1,high]�в���
	}
	printf("������%d��\n",i+1);
	return 0;
}

int IdxSearch(IdxType * I,int m,NodeType * R,int n,KeyType k)//�ֿ����
{
	int low=0,high=m-1,mid,i,j=0;
	int s=ceil((double)n/(double)m);//sΪÿ���Ԫ�ظ�����ӦΪn/b������ȡ��
	while(low<=high)//���������н����۰���ң��ҵ���λ��Ϊhigh+1
	{
		mid=(low+high)/2;
		if(I[mid].key>=k)
			high=mid-1;
		else
			low=mid+1;
		j++;
	}
	//Ӧ���������high+1���У����ڶ�Ӧ�����Ա��о���˳�����

	if(high+1>=m)
	{
		printf("������%d��\n",j+2);
		return 0;
	}
	i=I[high+1].link;

	while(i<I[high+1].link+s-1&&R[i].id!=k)
	{
		i++;
		j++;
	}
	printf("qgwehrhwhtahaagagagagG\n");
	printf("������%d��\n",j+2);
	if(i<I[high+1].link+s)
		return i+1;//���ҳɹ������ظ�Ԫ�ص��߼�����
	else
			printf("������%d��\n",j+2);
		return 0;//����ʧ�ܷ���0
}

NodeType * CreateList(int n)						//����˳���
{
	NodeType * R;
	R=(NodeType * )malloc(sizeof(NodeType)*n);		
	R->length=0;								
	return R;
}

void ListInsert(NodeType * R,int id,char name[20])	//�������ݲ�����
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
		printf("����ʧ��\n");
}

void DispList(NodeType * R)						//������Ա�
{
	int i;
	printf("ѧ��\t����\n");
	for(i=0;i<R->length;i++)					
		printf("%d\t%s\n",R[i].id,R[i].name);
	printf("\n");
}
