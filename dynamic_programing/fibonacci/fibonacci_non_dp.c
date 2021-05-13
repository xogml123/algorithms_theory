#include <stdio.h>
#include <stdlib.h>
////o(2^n)
int	fibonacci_non_dp(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (fibonacci_non_dp(n - 1) + fibonacci_non_dp(n - 2));
}

int	main()
{
	int	n;
	int	result;

	printf("피보나치수를 구하려는 정수를 입력하시요. : ");
	scanf("%d", &n);
	result = fibonacci_non_dp(n);
	printf("fibonacci(%d) : %d\n", n, result);
}
