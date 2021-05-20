#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 4

int main(int argc, char **argv)
{
	int coin[num]={500, 100, 50, 10};
	int	n[num];
	int	i;
	int	money;

	money = atoi(argv[1]);
	i = 0;
	while (i < num)
	{
		n[i] = money / coin[i];
		money -= n[i] * coin[i];
		i++;
	}
	for (int j = 0; j < i; j++)
		printf("%d : %d\n", coin[j], n[j]);
	printf("잔돈은 %d\n", money);
}