#include <stdio.h>
#include <stdlib.h>
////o(n)///memo를 완성하면 n번째를 완성할 수 있으므로.
int	fibonacci_dp(int n, int *memo)
{
	if (n == 0)
		return (memo[0]);
	else if (n == 1)
		return (memo[1]);
	else
	{
		if (memo[n] == -1)
			memo[n] = fibonacci_dp(n - 1, memo) + fibonacci_dp(n - 2, memo);
		return (memo[n]);
	}
}

int	main()
{
	int	n;
	int	result;
	int	*memo;
	int	i;

	printf("피보나치수를 구하려는 정수를 입력하시요. : ");
	scanf("%d", &n);
	memo = malloc(sizeof(int) * (n + 1));
	i = 0;
	while (i <= n)
	{
		memo[i] = -1;
		i++;
	}
	memo[0] = 0;
	memo[1] = 1;
	result = fibonacci_dp(n, memo);
	printf("fibonacci(%d) : %d\n", n, result);
}
