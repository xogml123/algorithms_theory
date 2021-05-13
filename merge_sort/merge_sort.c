#include "stdio.h"
#include "stdlib.h"

int	*input_array(int n)
{
	int	i;
	int *arr;

	
	arr = malloc(sizeof(int) * n);
	i = 0;
	printf("input array with space\n");
	while (i < n)
	{
		scanf(" %d", &arr[i]);
		i++;
	}
	return (arr);
}

void	merge(int *result, int *arr, int s, int f)
{
	int	mid;
	int	i;
	int	j;
	int	min;
	int	r_i;

	min = -10000000;
	mid = (s + f)/2;
	i = s;
	j = mid + 1;
	r_i = s;
	while(i == mid || j == f)
	{
		if (arr[i] <= arr[j])
		{
			result[r_i] = arr[i];
			i++;
			r_i;
		}
		else
		{
			result[r_i] = arr[j];
			j++;
			r_i;
		}
	}
	if (i == mid)
}

void	merge_sort(int *result, int *arr, int s, int f)
{
	int	mid;

	if (n > 1)
	{
		mid = (s + f)/2;
		merge_sort(result, arr, s, mid);
		merge_sort(result, arr, mid + 1, f);
		merge(result, arr, s, f);
	}
}

int main(int argc, char **argv)
{
	int	*arr;
	int	target;
	int	n;
	int	*result;

	printf("input array size : ");
	scanf("%d", &n);
	arr = input_array(n);
	result = malloc(sizeof(int) * n);
	merge_sort(result, arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);
	printf("\n");
	free(result);
	free(arr);
}