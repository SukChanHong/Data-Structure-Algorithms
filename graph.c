#include <stdio.h>
#include <stdbool.h>
//100000000를 무한히 큰 수 INFINITE로 생각.

bool v[6]; //각 vertex의 방문 여부
int d[6]; //최단 거리 표시, 매번 최신화

int small();//매 과정에서 방문하지 않은 vertex중 가장 작은 d[i]값을 가지는 vetex를 찾는 함수
void Dijk(int start);
void Dijk_stopover(int start, int stopover, int des);

int num = 0;//number of vertex 
int start = 0;//출발(0)
int des = 0;//목적지(5)
int stopover = 0;//경유지(3)//경유지가 여러개일 경우 추가해야함.


int edge[6][6];





int main()
{
	FILE *fp;

	fopen_s(&fp, "graph.txt", "rt");//rt의 의미는 파일을 텍스트 모드로 나타낸 것

	if (fp == NULL)
	{
		printf("file open fail\n");
	}
	else
		printf("file open success\n");

	
	
	//txt 파일에서 각 변수에 알맞은 값 불러오기.
	fscanf_s(fp, "%d", &num);
	fscanf_s(fp, "%d", &start);
	fscanf_s(fp, "%d", &des);
	fscanf_s(fp, "%d", &stopover);//경유지 여러개로 바뀔 경우 여기서 추가하기.
	for (int m = 0; m < 6; m++)//각 노드별 거리에 대한 정보 받아오기
	{
		for (int n = 0; n < 6; n++)
			fscanf_s(fp, "%d", &edge[m][n]);
	}
	//여기까지 입력.
	fclose(fp);//여기까지 파일에서 정보 받아오는 것 마무리.

	//제대로 작동하는 지 확인. 
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
	//여기부터 shortest path Algorithm 시작

	Dijk(start);

	for (int i = 0; i < num; i++)
	{
		printf("shortest path to %d : %d\n",i, d[i]);
	}
	//시작점에서 모든 지점까지의 최단 거리 표시

	printf("\n\n\nshortest path from start point\(%d\) vertex to destination \(%d\) vertex : %d\n\n",start, des, d[des]);
	//경유지를 거치지 않고 시작점에서 도착지점까지의 최단거리
	
	Dijk_stopover(start, stopover, des);
	


	


	return 0;
}

int small()//매 과정에서 방문하지 않은 vertex중 가장 작은 d[i]값을 가지는 vetex를 찾는 함수
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

	v[start] = 1;//시작 vertex 방문 표시

	for (int j = 0; j < num - 2; j++)
	{
		int now = small(); //가장 작은 값 찾기
		v[now] = 1; //가장 작은 값에 방문 했다는 것 표시

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
	}//거리값,방문 여부 초기화

	Dijk(start);
	p1 = d[stopover];
	printf("\nshortest path from start to stopover : %d\n", p1);

	for (int i = 0; i < num; i++)
	{
		d[i] = 0;
		v[i] = 0;
	}//거리값, 방문 여부 초기화

	Dijk(stopover);
	p2 = d[des];
	printf("\nshortest path from stopover to destination : %d\n", p2);
	p = p1 + p2;

	printf("\nshortest path to destination\(%d\) vertex when passing through a stopover\(%d\) vertex : %d\n", des, stopover, p);

}