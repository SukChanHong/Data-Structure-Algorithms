#include <stdio.h>

int a[100];
int size = 0;
void shiftup(int* arr, int index)
{
	int parentindex = (index - 1) / 2;
	int temp; // 임시저장소

	if (parentindex >= 0)
	{
		if (arr[index] < arr[parentindex])
		{
			temp = arr[parentindex];
			arr[parentindex] = arr[index];
			arr[index] = temp;
			shiftup(arr, parentindex);
		}

	}
}
void shiftdown(int* arr, int index, int size)
{
	int lc = index * 2 + 1;
	int rc = index * 2 + 2;

	int small = -1;//작은 것의 index -1로 초기화(선택 불가)

	if (lc < size)
		small = lc;
	if (rc < size && arr[lc]> arr[rc])
		small = rc;
	if (small != -1 && arr[index] > arr[small])//small =! -1 인경우 생각?
	{
		int temp;
		temp = arr[index];
		arr[index] = arr[small];
		arr[small] = temp;
		shiftdown(arr, small, size);
	}
}
void insert(int* arr, int input)
{
	if (size == 100)
	{
		printf("full");
		return;
	}
	else
	{
		a[size] = input;
		shiftup(a, size);
		size++;
	}
}
void display(int* arr)
{
	printf("heap : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void exmin(int* arr) 
{
	if (size > 0)
	{
		int temp = arr[0];
		arr[0] = arr[size - 1];
		shiftdown(arr, 0, size);
		size--;
		printf("after delete min\n");
		display(a);
	}
	else
		printf("heap is empty\n");
}
void deleteheap(int*arr)
{
	size = -1;
	
	size = 0;
}
void buildheap(int*arr)
{
	int num = 0;
	int input = 0;

	printf("how many data do you have? : ");
	scanf_s("%d", &num);//입력 받고자 하는 데이터의 개수

	printf("\ninsert data : ");
	for (int j = 0; j < num; j++)
	{
		scanf_s("%d", &input);
		a[j] = input;
		shiftup(a, j);
	}

	size = num;
	display(a);

}
void heapify(int*arr)
{
	for (int i = 0; i < size; i++)
	{
		shiftup(a, i);
	}
}

void one()
{
	int sela = 0;
	printf("CHOOSE WHAT TO DO.\n1. insert \n2. extract min\n3. delete heap\n4. heapify\n5. heapdispay\n");

	while (1)
	{
		int input = 0;

		scanf_s("%d", &sela);

		switch (sela)
		{
		case 1://insert
			printf("insert data : ");
			scanf_s("%d", &input);
			insert(a, input);
			display(a);
			break;

		case 2://extract min
			exmin(a);
			break;
		case 3://delete heap
			printf("delete heap\n");
			deleteheap(a);
			break;

		case 4: //heapify
			heapify(a);
			break;

		case 5: //heapdisplay
			display(a);
			break;
		}

	}
}
void multiple()
{
	int selb = 0;
	printf("CHOOSE WHAT TO DO.\n1. build heap \n2. extract min\n3. delete heap\n4. heapify\n5. heapdispay\n");

	while (1)
	{
		int input = 0;
			
		scanf_s("%d", &selb);
		
		switch (selb)
		{
		case 1://build heap
			buildheap(a);
			break;
		
		case 2://extract min
			exmin(a);
			break;
		case 3://delete heap
			printf("delete heap\n");
			deleteheap(a);
			break;
		
		case 4: //heapify
			heapify(a);
			break;

		case 5: //heapdisplay
			display(a);
			break;

		}
		
	}
}

int main()
{
	int type = 0;
	printf("Choose data input method\n\n1. Enter one by one\n2. Enter multiple simulatneously\n\n");

	while (type != 1000000)
	{
		scanf_s("%d", &type);
		switch (type)
		{
		case 1:
			one();
			break;

		case 2:
			multiple();
			break;
		}
	}
	return 0;
}