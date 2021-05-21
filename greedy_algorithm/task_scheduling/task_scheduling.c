#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 4

int	cmp(const void *n1, const void *n2)
{
	return (*(int *)n1 - *(int *)n2);
}

int	main()
{
	int t[8][2]={
		{0, 5},
		{6, 9},
		{4, 9},
		{2, 4},
		{0, 7},
		{9, 10},
		{7, 10},
		{5, 8}
	};
	int m = 1;

	qsort(t[0], 8, sizeof(int) * 2 ,cmp);
	for (int i = 0; i < 8; i++)
	{

	}
//향후 c++로 구현.

	// for (int i = 0; i< 8;i++)
	// {
	// 	printf("(%d, %d)\n", t[i][0], t[i][1]);
	// }

}