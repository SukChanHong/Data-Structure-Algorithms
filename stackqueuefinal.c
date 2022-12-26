#include <stdio.h>
#define STACKSIZE 100

struct stack
{
	char* arr; // 배열의 주소
	int top; // 배열의 top
};

typedef struct stack stack;

void create(stack* p);
void push(stack* p);
void pop(stack* p);
void print(stack* p);
char peek(stack* p);
int checkempty(stack* p);
int makeemtpy(stack* p);
void delete(stack* p);
int checktop(stack*p);


/////

struct node
{
	char input;
	struct node *next;
};
typedef struct node node;

struct queue
{
	node* front; // 배열의 주소
	node* rear;
	int size; // 배열의 top
};
typedef struct queue queue;

void qcreate(queue* p);
char qprint(queue* p);
void enq(queue* p);
char deq(queue *p);
int qcheckempty(queue *p);
void qmakeempty(queue *p);
void qdelete(queue *p);




int main()
{
	int sel = 0;

	printf("구현하고 싶은 기능을 선택하세요.\n1. Stack\n2.Queue\n번호 : ");
	scanf_s("%d", &sel);
	
	switch (sel) {
	case 1:

	{
		int MAX = -1;
		int sels = 0;
		stack stk;
		char ch;

		printf("구현하고 싶은 기능을 선택하세요.\n0. create a stack\n1.print \n2. push\n3. pop\n4. check a stack empty \n5. make a stack empty\n6. peek the top element of a stack\n7.delete a stack\n8.quit\n");
		while (sels != 8)
		{
			scanf_s("%d", &sels);

			switch (sels)
			{
			case 0:
				create(&stk);
				break;
			case 1:
				print(&stk);
				break;
			case 2:
				push(&stk);
				break;
			case 3:
				pop(&stk);
				break;
			case 4:
				checkempty(&stk);
				break;
			case 5:
				makeemtpy(&stk);
				break;
			case 6:
				peek(&stk);
				break;
			case 7:
				delete(&stk);
				break;
			}
		}
		return 0;
	}

	case 2:
	{

		int selq = 0;
		queue q;


		printf("구현하고 싶은 기능을 선택하세요.\n0. create a queue\n1.print \n2. enqueue\n3. dequeue\n4. check a queue empty \n5. make a queue empty\n6.delete a stack\n7.quit\n");
		while (selq != 7)
		{
			scanf_s("%d", &selq);

			switch (selq)
			{
			case 0:
				qcreate(&q);
				break;
			case 1:
				qprint(&q);
				break;
			case 2:
				enq(&q);
				break;
			case 3:
				deq(&q);
				break;
			case 4:
				qcheckempty(&q);
				break;
			case 5:
				qmakeempty(&q);
				break;
			case 6:
				qdelete(&q);
				break;
			}
		}
		return 0;
	}
	}
}

void create(stack* p)//MAX : 내가 만들고 싶은 배열의 사이즈 의미
{
	p->top = -1;

	p->arr = (char*)malloc(sizeof(char)*(STACKSIZE));
}

void push(stack* p)
{
	char ch;


	if ((p->top) >= (STACKSIZE)-1)// 스택 가득 찬다면 입력 불가.
	{
		printf("스택이 꽉 찼습니다.\n");
		return;
	}
	else

		printf("입력하고 싶은 문자를 입력하세요(다른 기능을 원하면 숫자를 입력해주세요) : ");
	scanf_s(" %c", &ch);//여기서 띄어쓰기를 해줘야 된다는 엄청난 사실.....도대체 이걸 어떻게 알 수 있는거지..

	p->arr[((p->top))] = ch;
	(p->top)++;



	return 0;


}

void pop(stack* p)
{
	if ((p->top) <= -1)
	{
		printf("스택에 자료가 없습니다.");
		return 0;
	}

	else
	{
		(p->top)--;
		return 0;
	}

}

void print(stack* p)//스택에 저장 된 값 출력하기.
{
	int i;

	printf("\n<stack>\n");

	for (i = 0; i <= (p->top); i++)
		printf("%c", p->arr[i - 1]);

	printf("\n\n");
}

char peek(stack* p)
{
	if ((p->top) == -1)
	{
		printf("스택에 자료가 없습니다.");
		return 0;
	}

	else
		printf("the top element of a stack : %c\n", p->arr[p->top - 1]);
	return 0;
}

int checkempty(stack* p)
{
	if ((p->top) == -1)
	{
		printf("stack is empty");
		return 1;
	}
	else
	{
		printf("stack is not empty");
		return 0;
	}
}

int makeemtpy(stack* p)
{
	(p->top) = -1;
	printf("Make stack empty\n");
	return 0;
}

int checktop(stack*p)
{
	printf("top : %d", p->top);

	return 0;
}

void delete(stack*p)
{
	free(p->arr);
	printf("delete the stack");
	system("pause");

	return 0;
}


////

void qcreate(queue* p)
{
	p->front = p->rear = NULL;
	p->size = 0;
}

void enq(queue* p)
{
	char ch;

	node *n = (node*)malloc(sizeof(node));
	scanf_s("%c", &ch);
	n->input = ch;
	n->next = NULL;

	if ((p->size) == 0)
	{
		p->front = n;
	}
	else
	{
		p->rear->next = n;
	}

	p->rear = n;
	p->size++;


	return 0;
}

char deq(queue *p)
{
	char data;
	node *ptr;//ptr이라는 node 생성
	if (p->size == 0)
	{
		printf("Q is empty");
		return 0;
	}
	else
		ptr = p->front;
	data = ptr->input;
	p->front = ptr->next;
	free(ptr);
	p->size--;

	return data;
}

int qcheckempty(queue *p)
{
	if (p->size == 0)
		printf("empty");
	else
		printf("not empty");
	return 0;
}

void qmakeempty(queue *p)
{
	p->front = p->rear = NULL;
	p->size = 0;
}

void qdelete(queue *p)
{
	free(p->front);
	free(p->rear);

	printf("delete the stack");
	system("pause");

}

char qprint(queue* p)
{
	int i;

	printf("<Queue>");
	node *n = p->front;

	for (i = 0; i < (p->size); i++)
	{
		printf("%c ", n->input);
		n = n->next;
	}

	return 0;
}