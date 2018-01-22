#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 100
typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
} BTNode;

BTNode *CreateBTNode(BTNode * b, char *str);
void PreOrder(BTNode * b);		// �������
void InOrder(BTNode * b);		// �������
void PostOrder(BTNode * b);		// �������
void LevelOder(BTNode * b);		// ��α���
int BTNodeHeight(BTNode * b);	// ��߶�
void Find(BTNode * b, char x);	// ��˫�׽ڵ�
void Leaf(BTNode * b);			// ��������ĵݹ��㷨

static int i = 0;

int main(void)
{
	char a, x;
	BTNode *b;
	char str[] = "A(B(D(,G)),C(E,F))";
	b = CreateBTNode(b, str);
	printf("1.�������\n2.�������\n3.�������\n4.��α���\n5.����Ҷ�ӽڵ���\n6.�������\n7.����x��˫��\n0.�˳�\n\n");
	while (1)
	{
		printf("\n\n");
		printf("������:\n");
		scanf("%c", &a);
		getchar();
		switch (a)
		{
		case '1':
			printf("�������:\n");
			PreOrder(b);		// �������
			break;
		case '2':
			printf("�������:\n");
			InOrder(b);			// �������
			break;
		case '3':
			printf("�������:\n");
			PostOrder(b);		// �������
			break;
		case '4':
			printf("��α���:\n");
			LevelOder(b);
			break;
		case '5':
			printf("Ҷ�ӽڵ�����");
			Leaf(b);
			if (i == -1)
				printf("������Ϊ��");
			else if (i == 0)
				printf("ֻ�и��ڵ�");
			else
				printf("%d", i);
			i = 0;
			break;
		case '6':
			printf("���Ϊ:%d", BTNodeHeight(b));
			break;
		case '7':
			printf("������ڵ��ֵx:\n");
			scanf("%c", &x);
			getchar();
			Find(b, x);
			break;
		case '0':
			return 0;
			break;
		default:
			printf("�����������������\n");
		}
	}
	return 0;
}

BTNode *CreateBTNode(BTNode * p1, char *str)
{
	BTNode *St[MaxSize], *p2;
	int top = -1, k, j = 0;
	char ch;
	p1 = NULL;					// �����Ķ�������ʼʱΪ��
	ch = str[0];
	while (ch != '\0')			// ѭ��ɨ��str��ÿ���ַ�
	{
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p2;
			k = 1;
			break;				// ��ʼ���������ӽڵ�
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;				// ��ʼ�����Һ��ӽ��
		default:
			p2 = (BTNode *) malloc(sizeof(BTNode));
			p2->data = ch;
			p2->lchild = p2->rchild = NULL;
			if (p1 == NULL)		// ����δ�������ڵ�
				p1 = p2;		// *pΪ�������ĸ��ڵ�
			else				// �ѽ������������ڵ�
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p2;
					break;
				case 2:
					St[top]->rchild = p2;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
	return p1;
}

int BTNodeHeight(BTNode * b)	// ��߶�
{
	int lchildh, rchildh;
	if (b == NULL)
		return 0;				// �����ĸ߶�Ϊ0
	else
	{
		lchildh = BTNodeHeight(b->lchild);	// ���������ĸ߶�Ϊlchildh
		rchildh = BTNodeHeight(b->rchild);	// ���������ĸ߶�Ϊrchildh
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}


void PreOrder(BTNode * b)		// ��������ĵݹ��㷨
{
	if (b != NULL)
	{
		printf("%c", b->data);	// ���ʸ��ڵ�
		PreOrder(b->lchild);	// �������������
		PreOrder(b->rchild);	// �������������
	}
}

void InOrder(BTNode * b)		// ��������ĵݹ��㷨
{
	if (b != NULL)
	{
		InOrder(b->lchild);		// �������������
		printf("%c", b->data);	// ���ʸ��ڵ�
		InOrder(b->rchild);		// �������������
	}
}

void PostOrder(BTNode * b)		// ��������ĵݹ��㷨
{
	if (b != NULL)
	{
		PostOrder(b->lchild);	// ��������������
		PostOrder(b->rchild);	// �������������
		printf("%c", b->data);	// ���ʸ��ڵ�
	}
}

void LevelOder(BTNode * b)		// ��α���
{
	
	BTNode *p;
	BTNode *qu[MaxSize];		// ���廷�ζ��У���Žڵ�ָ��
	int front, rear;			// �����ͷ�Ͷ�βָ��
	front = rear = -1;			// �ö���Ϊ�ն���
	rear++;
	qu[rear] = b;				// ���ڵ�ָ��������
	while (front != rear)		// ���в�Ϊ��
	{
		front = (front + 1) % MaxSize;
		p = qu[front];
		printf("%c", p->data);
		if (p->lchild != NULL)	// ���Һ���ʱ�������
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)	// ���Һ���ʱ�������
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}

void Leaf(BTNode * b)			// ��Ҷ�ӽڵ��������������
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
			i++;
		Leaf(b->lchild);		// �������������
		Leaf(b->rchild);		// �������������
	}
}

void Find(BTNode * b, char x)	// ����ֵΪx�Ľڵ㣬���˫�׽ڵ�
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag, top = -1,i=0;
	if (b == NULL)
		printf("������������");
	else if (b->data == x)
		printf("�ýڵ�Ϊ���ڵ�");
	else if (b != NULL)
	{
		do
		{
			while (b != NULL)
			{
				top++;
				St[top] = b;
				b = b->lchild;
			}
			p = NULL;
			flag = 1;
			while (top != -1 && flag)
			{
				b = St[top];
				if (b->rchild == p)
				{
					if (b->data == x)
					{
						printf("˫�׽ڵ�Ϊ:\n%c", St[top - 1]->data);
						return;
					}
					top--;
					p = b;
				}
				else
				{
					b = b->rchild;
					flag = 0;
				}
			}
			if(top==-1)
			{
				printf("�ýڵ㲻����");
			}
		}
		while (top != -1);
		printf("\n");
	}
	else
		printf("������Ϊ��");
}
