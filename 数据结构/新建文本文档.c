#include<stdio.h>
#include<malloc.h>
	
typedef struct Stu//���嵥����ڵ�����
{
	int id;	//���ѧ��
	char name;//�������
	struct Stu * next;//ָ���̽ڵ�
}Student;

void InitList(LinkList * &L);//��ʼ�����Ա�
void DestroyList(LinkList * &L)//�������Ա�
bool ListEmpty(LinkList);//�ж����Ա��Ƿ�Ϊ�ձ�
//bool InsertList(Sqlist* );//��ָ��λ�ò���һ��Ԫ��
//void Delete(Sqlist* ,int);//ɾ��ָ��λ�õ�Ԫ��
//void Display(Sqlist* );//��ӡ˳���������Ԫ��
//void Sort(Sqlist*);//��ѧ�������������
//void StuIn(Sqlist*);//�жϸ�ѧ���Ƿ��ڱ���
//int ListLength(Sqlist*);

int main()
{
	return 0;
}

void InitList(LinkList * &L)
{
	l=(Linklist*)malloc(sizeof(LinkList));
	L->next=NULLl;//����ͷ��㣬��next����ΪNULL
}

void DestroyList(LinkList * &L)
{
	LinkList * pre=L, * p=L->next;//preָ�� * p��ǰ���ڵ�
	while(p!=NULL){//ɨ�赥����L
		free(pre);//�ͷ� * pre �ڵ�
		pre=p;//pre��pͬ������һ����
		p=pre->next
	}
	free(pre)//ѭ������ʱ��pΪNULL��preָ��β�ڵ㣬�ͷ���
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