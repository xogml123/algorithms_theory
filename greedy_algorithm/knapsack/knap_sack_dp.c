#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 4

int	max(int a, int b)
{
	return ((a >= b) ? a : b);
}
int	main()
{
	int w[num + 1] = {-1, 4, 3, 5, 3};
	int p[num + 1] = {-1, 14, 15, 20, 9};
	int	M = 10;
	int	p_sum[num + 1][M + 1];

	for (int i = 1; i <= num; i++)
	{
		p_sum[i][0] = 0;
	}
	for (int j = 0; j <= M; j++)
	{
		p_sum[0][j] = 0;
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j - w[i] >= 0)
				p_sum[i][j] = max(p_sum[i - 1][j], p_sum[i - 1][j - w[i]] + p[i]);
			else
				p_sum[i][j] = p_sum[i - 1][j];
		}
	}
	printf("최대 이윤은 %d\n", p_sum[num][M]);
}