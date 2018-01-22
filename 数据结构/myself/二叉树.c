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
void PreOrder(BTNode * b);		// 先序遍历
void InOrder(BTNode * b);		// 中序遍历
void PostOrder(BTNode * b);		// 后序遍历
void LevelOder(BTNode * b);		// 层次遍历
int BTNodeHeight(BTNode * b);	// 求高度
void Find(BTNode * b, char x);	// 求双亲节点
void Leaf(BTNode * b);			// 先序遍历的递归算法

static int i = 0;

int main(void)
{
	char a, x;
	BTNode *b;
	char str[] = "A(B(D(,G)),C(E,F))";
	b = CreateBTNode(b, str);
	printf("1.先序遍历\n2.中序遍历\n3.后序遍历\n4.层次遍历\n5.计算叶子节点数\n6.计算深度\n7.求结点x的双亲\n0.退出\n\n");
	while (1)
	{
		printf("\n\n");
		printf("请输入:\n");
		scanf("%c", &a);
		getchar();
		switch (a)
		{
		case '1':
			printf("先序遍历:\n");
			PreOrder(b);		// 先序遍历
			break;
		case '2':
			printf("中序遍历:\n");
			InOrder(b);			// 中序遍历
			break;
		case '3':
			printf("后序遍历:\n");
			PostOrder(b);		// 后序遍历
			break;
		case '4':
			printf("层次遍历:\n");
			LevelOder(b);
			break;
		case '5':
			printf("叶子节点数：");
			Leaf(b);
			if (i == -1)
				printf("二叉树为空");
			else if (i == 0)
				printf("只有根节点");
			else
				printf("%d", i);
			i = 0;
			break;
		case '6':
			printf("深度为:%d", BTNodeHeight(b));
			break;
		case '7':
			printf("请输入节点的值x:\n");
			scanf("%c", &x);
			getchar();
			Find(b, x);
			break;
		case '0':
			return 0;
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	}
	return 0;
}

BTNode *CreateBTNode(BTNode * p1, char *str)
{
	BTNode *St[MaxSize], *p2;
	int top = -1, k, j = 0;
	char ch;
	p1 = NULL;					// 建立的二叉树初始时为空
	ch = str[0];
	while (ch != '\0')			// 循环扫描str中每个字符
	{
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p2;
			k = 1;
			break;				// 开始处理做左孩子节点
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;				// 开始处理右孩子结点
		default:
			p2 = (BTNode *) malloc(sizeof(BTNode));
			p2->data = ch;
			p2->lchild = p2->rchild = NULL;
			if (p1 == NULL)		// 若尚未建立根节点
				p1 = p2;		// *p为二叉树的根节点
			else				// 已建立二叉树根节点
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

int BTNodeHeight(BTNode * b)	// 求高度
{
	int lchildh, rchildh;
	if (b == NULL)
		return 0;				// 空树的高度为0
	else
	{
		lchildh = BTNodeHeight(b->lchild);	// 求左子树的高度为lchildh
		rchildh = BTNodeHeight(b->rchild);	// 求右子树的高度为rchildh
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}


void PreOrder(BTNode * b)		// 先序遍历的递归算法
{
	if (b != NULL)
	{
		printf("%c", b->data);	// 访问根节点
		PreOrder(b->lchild);	// 先序遍历左子树
		PreOrder(b->rchild);	// 先序遍历右子树
	}
}

void InOrder(BTNode * b)		// 中序遍历的递归算法
{
	if (b != NULL)
	{
		InOrder(b->lchild);		// 中序遍历左子树
		printf("%c", b->data);	// 访问根节点
		InOrder(b->rchild);		// 中序遍历右子树
	}
}

void PostOrder(BTNode * b)		// 后序遍历的递归算法
{
	if (b != NULL)
	{
		PostOrder(b->lchild);	// 后续遍历左子树
		PostOrder(b->rchild);	// 后序遍历右子树
		printf("%c", b->data);	// 访问根节点
	}
}

void LevelOder(BTNode * b)		// 层次遍历
{
	
	BTNode *p;
	BTNode *qu[MaxSize];		// 定义环形队列，存放节点指针
	int front, rear;			// 定义队头和队尾指针
	front = rear = -1;			// 置队列为空队列
	rear++;
	qu[rear] = b;				// 根节点指针进入队列
	while (front != rear)		// 队列不为空
	{
		front = (front + 1) % MaxSize;
		p = qu[front];
		printf("%c", p->data);
		if (p->lchild != NULL)	// 有右孩子时将其进队
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)	// 有右孩子时将其进队
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}

void Leaf(BTNode * b)			// 求叶子节点数（先序遍历）
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
			i++;
		Leaf(b->lchild);		// 先序遍历左子树
		Leaf(b->rchild);		// 先序遍历右子树
	}
}

void Find(BTNode * b, char x)	// 查找值为x的节点，输出双亲节点
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag, top = -1,i=0;
	if (b == NULL)
		printf("二叉树不存在");
	else if (b->data == x)
		printf("该节点为根节点");
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
						printf("双亲节点为:\n%c", St[top - 1]->data);
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
				printf("该节点不存在");
			}
		}
		while (top != -1);
		printf("\n");
	}
	else
		printf("二叉树为空");
}
