#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N -100000 // �ſ� ���� ��.


typedef struct node
{
	int data;

	struct node* left;
	struct node* right;
	

}node;

void pointer();//pointer�� Ȱ���� bst ����� �����ϴ� �Լ��� ����
	node* insert(node* p,int input);
	node* delete(node*p, int deldata);
	node* findmin(node*p);
	node* findmax(node*p);
	void inorder(node*p);
	void preorder(node*p);
	node* search(node*p, int searchdata);
	node* findchildren(node*p, int input);
	node* findparent(node*p, int input);

void array();//array�� Ȱ���� bst����� �����ϴ� �Լ��� ����
	int* insert_a(int* arr, int input);
	void delete_a(int deldata);
	void inorder_a(int arr[], int index);
	void preorder_a(int arr[], int index);
	int findchildren_a(int arr[], int index, int input);
	int findparent_a(int arr[], int index, int input);
	
	
int main()
{
	int type = 0;
	printf("���ϴ� ������ ���� ����� �����Ͻÿ�.\n\n1. pointer\n2. array\n\n");

	while(type!=1000000)
	{
		scanf_s("%d", &type);
		switch (type)
		{
		case 1:
			pointer();
			break;

		case 2:
			array();
			break;
		}
	}
	return 0;
}


void pointer()
{
	printf("*���� : ���� ���� �Է����� ���ÿ�.");
	
	char selp = 'z';
	node *p = NULL;
	node *searchnode;
	int input = 0;
	int searchdata = 0;
	node *parent;
	printf("�����ϰ� ���� ����� �����ϼ���.\na. insert \nb. delete \nc. find children \nd. find parent \ne. inorder traversal\nf. preorder traversal\ng. search \n\nh. clear the console \nq.quit\n\n");
	

	while (selp != 'q')
	{
		scanf_s("%c", &selp, 1);
		switch (selp)

		{
		case 'a':
			printf("insert data(if you want insert more data, press a again and insert data : ");
			scanf_s("%d", &input);
			p = insert(p, input);
			break;

		case 'b':
			printf("delete data : ");
			scanf_s("%d", &input);
			p = delete(p, input);
			break;

		case 'c' :
			printf("find children : ");
			scanf_s("%d", &input);
			findchildren(p, input);
			break;

		case 'd':
			printf("findparent : ");
			scanf_s("%d", &input);
			parent = findparent(p, input);
			if (parent == NULL)
				printf("there is no parent node(root).\n");
			else
				printf("\nparent of %d : %d\n\n", input, parent->data);
			
			break;
		
		case 'e':
			printf("inorder : ");
			inorder(p);
			printf("\n");
			break;
		
		case 'f':
			printf("preorder : ");
			preorder(p);
			printf("\n");

			break;

		case 'g':
			printf("search data : ");
			scanf_s("%d", &searchdata);
			
			searchnode = search(p, searchdata);
			
			if (searchnode == NULL)
				printf("there are no data");
			else
				printf("there is a data(%d)", searchnode->data);

			break;

		case 'h':
			system("cls");
			printf("�����ϰ� ���� ����� �����ϼ���.\na. insert \nb. delete \nc. find children \nd. find parent \ne. inorder traversal\nf. preorder traversal\ng. search \n\nh. clear the console \nq.quit\n\n");
			break;
		}
	}
	return 0;
}
void array()
{
	_set_printf_count_output(1);//"'n' format specifier disabled", 0 ������ ���� ���� ����
	printf("*���� : ���� ���� �Է����� ���ÿ�.");

	///��������
	char sela = 'z';
	int arr[100];
	int input;
	int index;
	printf("�����ϰ� ���� ����� �����ϼ���.\na. insert \nb. delete \nc. find children \nd. find parent \ne. inorder traversal\nf. preorder traversal\n\ng. clear the console\nq. quit\n\n");

	for (int index = 0; index < 100; index++)
	{
		arr[index] = N;
	}

	while (sela != 'q')
	{
		scanf_s("%c", &sela, 1);
		switch (sela)

		{
		case 'a':
		{
			printf("insert data(if you want insert more data, press a again and insert data : ");
			scanf_s("%d", &input);
			insert_a(arr, input);
			break;
		}

		case 'b':
		{

			printf("delete data : ");
			scanf_s("%d", &input);

			break;
		}
		case 'c':
		{
			int index = 0;
			printf("find children : ");
			scanf_s("%d", &input, sizeof(input));//���� �߻�(0x7BB905B8(ucrtbased.dll), BST.exe): 0xC0000005: 0x00000004 ��ġ�� ����ϴ� ���� �׼��� ������ �߻��߽��ϴ�..

			if (arr[0] == input)
			{
				if (arr[1] == N && arr[2] == N)
					printf("there are no children\n");

				else if (arr[1] == N && arr[2] != N)
					printf("right child : %d\n", arr[2]);
				else if (arr[1] != N && arr[2] == N)
					printf("left child : %d\n", arr[1]);

				else if (arr[1] != N && arr[2] != N)
					printf("left child : %d\nright child : %d\n", arr[1], arr[2]);

				break;
			}//root�� ��� children �� ǥ������ �ʾƼ� ���� �߰� ������.
			else
			{
				findchildren_a(arr, index, input);
			}

			printf("\n");

			break;
		}
		case 'd':
		{
			int index = 0;
			printf("findparent : ");
			scanf_s("%d", &input);
			findparent_a(arr, index, input);
			printf("\n");

			break;
		}
		case 'e':
			index = 0;
			printf("inorder : ");
			inorder_a(arr, index);
			printf("\n");
			break;

		case 'f':
			printf("preorder : ");
			preorder_a(arr, index);
			printf("\n");

			break;

		case 'g':
			system("cls");
			printf("�����ϰ� ���� ����� �����ϼ���.\na. insert \nb. delete \nc. find children \nd. find parent \ne. inorder traversal\nf. preorder traversal\n\ng. clear the console\nq. quit\n\n");
			break;
		}
	}
	return 0;
}


node*  insert(node* p, int input)
{
	if (p == NULL)
	{
		p = (node*)malloc(sizeof(node));

		p->data = input;
		p->left = NULL;
		p->right = NULL;
	}

	else if (p->data > input)
	{
		p->left = insert(p->left, input);
	}
	else if (p->data < input)
	{
		p->right = insert(p->right, input);
	}
	else if (p->data == input)
	{
		printf("There are same data\n");
	}
	return p;
}
node* delete(node*p, int deldata)
{
	node *fake;
	
	if (p)

		if (p->data == deldata)
		{
			if (p->left == NULL && p->right == NULL)
			{
				free(p);
				return NULL;					////�ڽ� ��尡 ���� ���
			}
			else
			{
				if (p->left == NULL)
				{
					fake = p->right;
					free(p);
					return fake;
				}
				else if (p->right == NULL)
				{
					fake = p->left;
					free(p);
					return fake;					///�ڽ� ��尡 �ϳ��϶�
				}
				else
				{
					fake = findmin(p->right);
					p->data = fake->data;
					p->right = delete(p->right, fake->data);
				}
													///�ڽ� ��尡 �ΰ��϶�
			}
		}
		else if(p->data != deldata)
		{
			if (p->data > deldata)
				p->left = delete(p->left, deldata);
			else if (p->data < deldata)
				p->right = delete(p->right, deldata);
			else if (p->data == NULL)
				printf("There are no data.\n");				///��忡 ������ ���� ���� ��
		}

	return p;
}
node* findmin(node*p)
{
	if(p)
	{
		while(p->left)
		p = p->left;
		
	}
	return p;
}
node* findmax(node*p)
{
	if (p)
	{
		while (p->left)
			p = p->left;
	}
	return p;
}
void inorder(node* p)
{
	if (p != NULL)
	{
		inorder(p->left);
		printf("%d ", p->data);
		inorder(p->right);
	}
}
void preorder(node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
node* search(node* p, int searchdata)
{
	if (p == NULL)
		return NULL;

	if (searchdata == p->data)
		return p;
	else if (p->data< searchdata)
		return search(p->right, searchdata);
	else if (p->data> searchdata)
		return search(p->left, searchdata);
}
node* findchildren(node*p, int input)
{
	int leftchild, rightchild = 0;

	node* find;
	find = search(p, input);

	if (find->left == NULL && find->right == NULL)
	{
		printf("there are no child\n");
		return p;
	}
	else if (find->left == NULL && find->right != NULL)
	{
		find = find->right;
		rightchild = find->data;
		printf("rightchild : %d\n", rightchild);
	}
	else if (find->left != NULL && find->right == NULL)
	{
		find = find->left;
		leftchild = find->data;
		printf("leftchild : %d\n", leftchild);
	}
	else if (find->left != NULL && find->right != NULL)
	{
		
		leftchild = find->left->data;
		printf("leftchild : %d\n", leftchild);
		rightchild = find->right->data;
		printf("rightchild : %d", rightchild);
	}

}
node* findparent(node*p, int input)
{
	node* parent = NULL;
	if (p == NULL)
		parent = NULL;
	else if (p->data == input)
		parent == NULL;

	else
	{
		if (input == p->right->data)
			parent = p;
		else if (input == p->left->data)
			parent = p;
		else if (p->data < input)
			return findparent(p->right, input);
		else if (p->data > input)
			return findparent(p->left, input);
	}

	return parent;
}
///pointer�� �̿��� �Լ���

int* insert_a(int* arr, int input)
{
	int index = 0;

	if (arr[0] == N)
	{
		arr[0] = input;
	}		// root�� �� ����
	else
	{
		while (arr[index] != N)
		{


			if (input > arr[index])
			{
				index = 2 * index + 2;

			}
			else if (input < arr[index])
			{
				index = 2 * index + 1;

			}
			else if (arr[index] == input)
			{
				printf("there are same data");
				break;
			}
		}
		arr[index] = input; // �� �ڵ尡 ���� if, else if �� ������ ���� stackoverflow�߻�, arr[index]���� ���ŵǸ鼭 !=N�̶�� ������ ��� �����Ǿ ���� ��� ���� �ǰ�??���� �м� �ʿ�.
	}
	return arr;
}
void inorder_a(int arr[], int index)
{

	if (arr[index] != N)
	{
		inorder_a(arr, index * 2 + 1);
		printf("%d ", arr[index]);
		inorder_a(arr, index * 2 + 2);
	}

}
void preorder_a(int arr[], int index)
{
	if (arr[index] != N)
	{
		printf("%d ", arr[index]);
		preorder_a(arr, index * 2 + 1);
		preorder_a(arr, index * 2 + 2);
	}
}
int findchildren_a(int arr[], int index, int input)
{

	while (arr[index] != input)
	{
		{
			if (arr[index] > input)
				index = index * 2 + 1;
			else if (arr[index] < input)
				index = index * 2 + 2;
		}
		if (arr[index] == input)
		{
			if (arr[index * 2 + 1] == N && arr[index * 2 + 2] == N)
				printf("there are no children\n");

			else if (arr[index * 2 + 1] == N && arr[index * 2 + 2] != N)
				printf("right child : %d\n", arr[index * 2 + 2]); ///index�� �ؾ��ϴ��� index*2 +2�� �ؾ��ϴ��� Ȯ�� �ʿ�
			else if (arr[index * 2 + 1] != N && arr[index * 2 + 2] == N)
				printf("left child : %d\n", arr[index * 2 + 1]);

			else if (arr[index * 2 + 1] != N && arr[index * 2 + 2] != N)
				printf("left child : %d\nright child : %d\n", arr[index * 2 + 1], arr[index * 2 + 2]);

			break;
		}
	}


}
int findparent_a(int arr[], int index, int input)
{
	if (input == arr[0])
	{
		printf("the node is root node\n");
	}
	else
	{
		while (arr[index] != input)
		{

			{
				if (arr[index] > input)
					index = index * 2 + 1;
				else if (arr[index] < input)
					index = index * 2 + 2;
			}
			if (arr[index] == input)
			{
				if (index % 2 == 1)
					printf("parent : %d", arr[(index - 1) / 2]);
				else if (index % 2 == 0)
					printf("parent : %d", arr[(index - 2) / 2]);

			}
		}
	}
}
//array�� �̿��� �Լ���