#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 4
#define k 13

int	max(int n1, int n2)
{
	return ((n1 >= n2) ? n1 : n2);
}

int	main()
{
	int	w[num + 1]={-1,7,8,5,3};
	int	s[num + 1][k + 1];

	for (int i = 0; i<= num; i++)
		s[i][0] = 1;
	for (int j = 0; j<= k;j++)
		s[0][j] = 0;
	s[0][0] = 0;
	for (int i = 1; i <= num; i++)
	{
		for (int j= 1; j <=k; j++)
		{
			if (j - w[i] >= 0)
				s[i][j] = max(s[i - 1][j], s[i - 1][j - w[i]]);
			else
				s[i][j] = max(s[i - 1][j], 0);
			printf("i:%d, j:%d, s[i][j]:%d\n", i, j, s[i][j]);

		}
	}
	printf("저울이 4개, 무게는 13 일때 가능한가? (%d)\n", s[4][13]);
}
