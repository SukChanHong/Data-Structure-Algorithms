#include <stdio.h>
#include <stdbool.h>
//100000000�� ������ ū �� INFINITE�� ����.

bool v[6]; //�� vertex�� �湮 ����
int d[6]; //�ִ� �Ÿ� ǥ��, �Ź� �ֽ�ȭ

int small();//�� �������� �湮���� ���� vertex�� ���� ���� d[i]���� ������ vetex�� ã�� �Լ�
void Dijk(int start);
void Dijk_stopover(int start, int stopover, int des);

int num = 0;//number of vertex 
int start = 0;//���(0)
int des = 0;//������(5)
int stopover = 0;//������(3)//�������� �������� ��� �߰��ؾ���.


int edge[6][6];





int main()
{
	FILE *fp;

	fopen_s(&fp, "graph.txt", "rt");//rt�� �ǹ̴� ������ �ؽ�Ʈ ���� ��Ÿ�� ��

	if (fp == NULL)
	{
		printf("file open fail\n");
	}
	else
		printf("file open success\n");

	
	
	//txt ���Ͽ��� �� ������ �˸��� �� �ҷ�����.
	fscanf_s(fp, "%d", &num);
	fscanf_s(fp, "%d", &start);
	fscanf_s(fp, "%d", &des);
	fscanf_s(fp, "%d", &stopover);//������ �������� �ٲ� ��� ���⼭ �߰��ϱ�.
	for (int m = 0; m < 6; m++)//�� ��庰 �Ÿ��� ���� ���� �޾ƿ���
	{
		for (int n = 0; n < 6; n++)
			fscanf_s(fp, "%d", &edge[m][n]);
	}
	//������� �Է�.
	fclose(fp);//������� ���Ͽ��� ���� �޾ƿ��� �� ������.

	//����� �۵��ϴ� �� Ȯ��. 
	printf("num : %d, start :  %d, des :  %d, stopover :  %d\n\n", num, start, des, stopover);
	for (int m = 0; m < 6; m++)
	{
		printf("distance of %d vertex to each  vertex \n", m);
		for (int n = 0; n < 6; n++)
		{
			printf("%d ", edge[m][n]);
		}
		printf("\n");
	}

	printf("\n\n");
	//������� shortest path Algorithm ����

	Dijk(start);

	for (int i = 0; i < num; i++)
	{
		printf("shortest path to %d : %d\n",i, d[i]);
	}
	//���������� ��� ���������� �ִ� �Ÿ� ǥ��

	printf("\n\n\nshortest path from start point\(%d\) vertex to destination \(%d\) vertex : %d\n\n",start, des, d[des]);
	//�������� ��ġ�� �ʰ� ���������� �������������� �ִܰŸ�
	
	Dijk_stopover(start, stopover, des);
	


	


	return 0;
}

int small()//�� �������� �湮���� ���� vertex�� ���� ���� d[i]���� ������ vetex�� ã�� �Լ�
{
	int min = 100000001;
	int index = 0;
	for (int i = 0; i < num; i++)
	{
		if (v[i] == 0 && d[i] < min)
		{
			min = d[i];
			index = i;
		}
	}

	return index;
}

void Dijk(int start)
{

	for (int i = 0; i < num; i++) 
	{
		d[i] = edge[start][i];
	}

	v[start] = 1;//���� vertex �湮 ǥ��

	for (int j = 0; j < num - 2; j++)
	{
		int now = small(); //���� ���� �� ã��
		v[now] = 1; //���� ���� ���� �湮 �ߴٴ� �� ǥ��

		for (int k = 0; k < num; k++)
		{
			if (v[k] == 0 && d[now] + edge[now][k] < d[k])
				d[k] = d[now] + edge[now][k];
		}

	}

}


void Dijk_stopover(int start, int stopover, int des)
{
	int p1, p2, p;

	for (int i = 0; i < num; i++)
	{
		d[i] = 0;
		v[i] = 0;
	}//�Ÿ���,�湮 ���� �ʱ�ȭ

	Dijk(start);
	p1 = d[stopover];
	printf("\nshortest path from start to stopover : %d\n", p1);

	for (int i = 0; i < num; i++)
	{
		d[i] = 0;
		v[i] = 0;
	}//�Ÿ���, �湮 ���� �ʱ�ȭ

	Dijk(stopover);
	p2 = d[des];
	printf("\nshortest path from stopover to destination : %d\n", p2);
	p = p1 + p2;

	printf("\nshortest path to destination\(%d\) vertex when passing through a stopover\(%d\) vertex : %d\n", des, stopover, p);

}