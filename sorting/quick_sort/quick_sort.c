#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int	*input_array(int n)
{
	int	i;
	int *arr;

	arr = malloc(sizeof(int) * n);
	i = 0;
	printf("input array with space\n");
	while (i < n)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	return (arr);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		median_of_three(int *arr, int s, int f)
{
	int	a;
	int	b;
	int	c;
	int	ia;
	int	ib;
	int	ic;

	srand(time(0));
	ia = rand() % (f - s + 1) + s;
	a = arr[ia];
	ib = rand() % (f - s + 1) + s;
	b = arr[ib];
	ic = rand() % (f - s + 1) + s;
	c = arr[ic];
	if ((a <= b) && (b <= c)) return ib; 
    if ((a <= c) && (c <= b)) return ic; 
    if ((b <= a) && (a <= c)) return ia; 
    if ((b <= c) && (c <= a)) return ic; 
    if ((c <= a) && (a <= b)) return ia; 
    return ib;                           
}

void	quick_sort(int *arr, int s, int f)
{
	int	p_i;
	int	i;
	int	j;

	if (f - s > 0)
	{
		p_i = median_of_three(arr, s, f);
		swap(arr + s, arr + p_i);
		i = s + 1;
		j = f;
		while(1)
		{
/////////////////never compare pivot and element by including equal case. Because 
///////////it can be j down to pivot which is located in index s/////////////////
			while (arr[i] < arr[s])
				i++;
			while (arr[j] > arr[s])
				j--;
			if (j < i)
				break;
			swap(arr + i, arr + j);
			i++;
			j--;
		}
		swap(arr + s, arr + j);
		quick_sort(arr, s, j - 1);
		quick_sort(arr, j + 1, f);
	}
//////doesn't have to branch element 2case because it can'be treated well by code
}

int main(int argc, char **argv)
{
	int	*arr;
	int	target;
	int	n;

	printf("input array size : ");
	scanf("%d", &n);
	arr = input_array(n);
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
}