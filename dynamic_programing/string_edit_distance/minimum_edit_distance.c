#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//삽입비용 : 2 삭제비용 : 1 변경비용 : 3

int		min(int x, int y)
{
	return ((x >= y) ? y : x);
}

int		recur_solve(char *x, char *y, int	n, int	m, int *e)
{
	int	ret;

	if (e[n * strlen(y) + m] != -1)
		return (e[n * strlen(y) + m]);
	else
	{
		ret = min(min(recur_solve(x, y, n - 1, m, e) + 1, recur_solve(x, y, n, m - 1, e) + 2),
			recur_solve(x, y, n - 1, m - 1, e) + 3 * (x[n - 1] != y[m - 1]));
		e[n * strlen(y) + m] = ret;
		return (ret);
	}
}

int	solve(char *x, char *y, int	len_x, int	len_y)
{
	int	e[len_x + 1][len_y + 1];

	for (int	i = 0; i < len_x + 1; i++)
	{
		for (int j = 0; j < len_y + 1; j++)
			e[i][j] = -1;
	}
	e[0][0] = 0;b 
	for (int	i = 1; i < len_x + 1; i++)
		e[i][0] = 1 * i;
	for (int	i = 1; i < len_y + 1; i++)
		e[0][i] = 2 * i;
	recur_solve(x, y, len_x, len_y, e[0]);
	return (e[len_x][len_y]);
}

int	main(int argc, char **argv)
{
	char	*x;
	char	*y;
	int		len_x;
	int		len_y;
	int		result;

	if (argc != 3)
		{
			printf("x,y보다 많은 인자를 입력하였습니다.\n");
		}
	len_x = strlen(argv[1]);
	len_y = strlen(argv[2]);
	result = solve(argv[1], argv[2], len_x, len_y);
	printf("최소 편집거리는 : %d\n", result);
}