#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inf 10000000
#define vertice 4

int	min(int n1, int n2)
{
	return ((n1 >= n2) ? n2 : n1);
}

void	path_recur(int (*p)[vertice], int s, int e)
{
	int	inter;
	inter = p[s][e];
	if (inter != -1)
	{
		path_recur(p, s, inter);
		printf("%d->", inter);
		path_recur(p, inter, e);
	}
}

void	path_print(int (*p)[vertice], int s, int e)
{
	printf("최단경로는\n");
	printf("%d->", s);
	path_recur(p, s, e);
	printf("%d\n", e);
}

int	main()
{
	int	d[vertice][vertice]=
	{
		{0, 4, 2, inf},
		{inf, 0, 5, inf},
		{inf, -1, 0, inf},
		{3, inf, inf, 0}
	};
	int p[4][4];

	for(int	i = 0; i < vertice; i++)
	{
		for (int j = 0;j < vertice; j++)
			p[i][j] = -1;
	}

	for(int	k = 0; k < vertice; k++)
	{
		for (int i = 0; i< vertice; i++)
		{
			for (int j = 0; j< vertice; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
		}
	}
	printf("최단길이는 %d\n", d[3][1]);

	path_print(p, 3, 1);
	////만약 i->j까지의 최단경로의 길이는 d[i][j]이고
	/////경로는 p[i][j]를 읽고 나온 x 값에서 p[i][x] p[x][j]
	////의 값을 각각 읽어 recursive 하게 경로를 찾아낸다. p값이 -1
	////나오면 중간 경로가 없는 경우이다.
}
