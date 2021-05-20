#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 4

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
////////////어떤 배열을 그 배열을 대표하는 어떤값을 기준으로 sorting하고 싶을때는 배열을 동시에 sorting 하면된다는것을 알았다.///////
void	sort_dump(int *w, int *p, double *rate)
{
	double	temp;

	for (int i = 0; i<num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (rate[i] < rate[j])
			{
				swap(w + i, w + j);
				swap(p + i, p + j);
				temp = rate[i];
				rate[i] = rate[j];
				rate[j] = temp;
			}
		}
	}
}

int	main()
{
	int w[num] = {4, 3, 5, 3};
	int p[num] = {14, 15, 20, 9};
	double	rate[num];
	int	M = 10;
	int	p_sum;
	int	w_result[num];

	for(int i = 0; i< num; i++)
		rate[i] = (double)p[i] / w[i];
	sort_dump(w, p, rate);
	p_sum = 0;
	for (int i = 0; i < num; i++)
	{
		if (M - w[i] >= 0)
		{
			p_sum += p[i];
			M -= w[i];
			w_result[i] = 1;
		}
		else
			w_result[i] = 0;
	}
	for (int i = 0; i < num ; i++)
		printf("%dkg : %d\n", w[i], w_result[i]);
	printf("p_sum:%d\n", p_sum);
}