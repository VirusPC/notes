 #include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct {
	char name[20];
	int id;
} ElemType;
typedef struct {
	ElemType data;
	int length;
	int count;
}Sqlist;
Sqlist* CreateList(int);//����һ��˳���
bool Insert(Sqlist* );//��ָ��λ�ò���һ��Ԫ��
void Delete(Sqlist* ,int );//ɾ��ָ��λ�õ�Ԫ��
void Display(Sqlist* );//��ӡ˳���������Ԫ��
void Sort(Sqlist*);//��ѧ�������������
void StuIn(Sqlist*);//�жϸ�ѧ���Ƿ��ڱ���
int main(void)
{
	int n = 0,i = 0,pos = 0;
	Sqlist *sql;
	printf("������Ҫ��ౣ����ٸ�Ԫ�ء�����\n");
	scanf("%d",&n);
	sql = CreateList(n);
	while(true)
	{
		printf("\n\n\n                     1.����Ԫ��\n");
		printf("                     2.ɾ��Ԫ��\n");
		printf("                     3.��ӡ����Ԫ��\n");
		printf("                     4.����Ԫ�ز�ɾ��\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				Insert(sql);
				Sort(sql);
				break;
			}
			case 2:
			{
				printf("������ɾ��Ԫ�ص�λ��\n");
				scanf("%d",&pos);
				Delete(sql, pos);
				break;
			}
			case 3:
				{
					Display(sql);
					break;
				}
			case 4:
				{
					StuIn(sql);
					break;
				}
		}
	}
	return 0;
}
Sqlist* CreateList(int n)
{
	Sqlist *sql;
	sql = (Sqlist *)malloc(sizeof(Sqlist) * n);
	sql->count = 0;
	sql->length = n;
	return sql;
}
bool Insert(Sqlist* sql)
{
	int i,pos;
	Sqlist *sql2;
	sql2 = (Sqlist *)malloc(sizeof(Sqlist));
	printf("���������Ԫ�ص�λ��\n");
			scanf("%d",&pos);
			printf("������������ѧ��\n");
			scanf("%s%d",&(sql2->data.name),&(sql2->data.id));
	if(pos < 1 || pos > sql->length)
		return false;
	if(pos > sql->count)
	{
		sql[sql->count].data = sql2->data;
		sql->count++;
		return true;
	}
	for(i = sql->count-1;i >= pos-1;--i)
	{
		sql[i+1].data = sql[i].data;
	}
	sql[pos-1].data = sql2->data;
	++sql->count;
	return true;
}
void Delete(Sqlist* sql, int n)
{
	int i;
	if(n < 1 || n > sql->length)
		printf("ɾ��ʧ��");
	else
	{
		for(i = n - 1; i < sql->length;++i)
			sql[i].data = sql[i+1].data;
		sql->count--;
	}
}
void Display(Sqlist* sql)
{
	int i;
	if(sql->count == 0)
		printf("������Ԫ��\n");
	else
		for(i = 0;i < sql->count;++i)
			printf("������%s  ѧ�ţ�%d\n",sql[i].data.name,sql[i].data.id);
}
void Sort(Sqlist* sql)
{
	int i,j,k = 0;
	ElemType data;
	if(sql->count == 0)
		printf("˳�����������");
	else
		for(i = 0;i < sql->count - 1;++i)
		{
			data = sql[i].data;
			for(j = i + 1;j < sql->count;++j)
				if(data.id > sql[j].data.id)
				{
					k = j;
					data = sql[j].data;
				}
			data = sql[i].data;
			sql[i].data = sql[k].data;
			sql[k].data = data;
		}
}
void StuIn(Sqlist* sql)
{
	int i;
	ElemType stu;
	printf("������Ҫ����ѧ����������ѧ��\n");
	scanf("%s%d",stu.name,&stu.id);
	for(i = 0;i < sql->count;++i)
	{
		if(strcmp(sql[i].data.name,stu.name) && sql[i].data.id == stu.id)
		Delete(sql,i+1);
	}
	printf("��ɾ��������ѧ����Ϣ��ͬ��ѧ��\n");
}
