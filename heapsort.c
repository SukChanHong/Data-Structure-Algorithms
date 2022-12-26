#include <stdio.h>

int a[100];
int sort[100];
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
void sort_decrease(int*arr)
{
	int origin_size = size;
	while (size > 0)
	{
		int temp = arr[0];
		sort[size] = temp;

		arr[0] = arr[size - 1];
		shiftdown(arr, 0, size);
		size--;
	}
	printf("heap sort_decreasing: ");
	for (int i = 1; i <= origin_size; i++)
	{
		printf("%d ", sort[i]);
	}
	printf("\n");
}
void sort_increase(int*arr)
{
	int origin_size = size;
	while (size > 0)
	{
		int temp = arr[0];
		sort[size] = temp;

		arr[0] = arr[size - 1];
		shiftdown(arr, 0, size);
		size--;
	}
	printf("heap sort_increasing: ");
	for (int i = origin_size; i >= 1; i--)
	{
		printf("%d ", sort[i]);
	}
	printf("\n");
}

int main()
{
	int selb = 0;
	printf("CHOOSE WHAT TO DO.\n1. build heap \n2. heapsort_decrease\n3. heapsort_increase\n");

	while (1)
	{
		int input = 0;

		scanf_s("%d", &selb);

		switch (selb)
		{
		case 1://build heap
			buildheap(a);
			break;

		case 2://sort_decrease
			sort_decrease(a);
			break;
		case 3://sort_increase
			sort_increase(a);
			break;		
		}

	}
	return 0;
}