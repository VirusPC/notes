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
Sqlist* CreateList(int);//创建一个顺序表
bool Insert(Sqlist* );//在指定位置插入一个元素
void Delete(Sqlist* ,int );//删除指定位置的元素
void Display(Sqlist* );//打印顺序表中所有元素
void Sort(Sqlist*);//以学号升序进行排序
void StuIn(Sqlist*);//判断该学生是否在表中
int main(void)
{
	int n = 0,i = 0,pos = 0;
	Sqlist *sql;
	printf("请输入要最多保存多少个元素。。。\n");
	scanf("%d",&n);
	sql = CreateList(n);
	while(true)
	{
		printf("\n\n\n                     1.插入元素\n");
		printf("                     2.删除元素\n");
		printf("                     3.打印各个元素\n");
		printf("                     4.查找元素并删除\n");
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
				printf("请输入删除元素的位置\n");
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
	printf("请输入插入元素的位置\n");
			scanf("%d",&pos);
			printf("请输入姓名与学号\n");
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
		printf("删除失败");
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
		printf("表中无元素\n");
	else
		for(i = 0;i < sql->count;++i)
			printf("姓名：%s  学号：%d\n",sql[i].data.name,sql[i].data.id);
}
void Sort(Sqlist* sql)
{
	int i,j,k = 0;
	ElemType data;
	if(sql->count == 0)
		printf("顺序表中无数据");
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
	printf("请输入要查找学生的姓名与学号\n");
	scanf("%s%d",stu.name,&stu.id);
	for(i = 0;i < sql->count;++i)
	{
		if(strcmp(sql[i].data.name,stu.name) && sql[i].data.id == stu.id)
		Delete(sql,i+1);
	}
	printf("已删除与输入学生信息相同的学生\n");
}
