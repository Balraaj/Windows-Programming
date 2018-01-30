#include<stdio.h>
#include<conio.h>
int main(void)
{
	int i = 1;
	int n, p, temp;
	int sum = 0;
	printf("Enter the no. = ");
	scanf("%d", &n);
	printf("\nPress 1 for sum of squares ");
	printf("\nPress 2 for sum of cubes");
	printf("\nPress 3 for sum of quads");
	printf("\n\nEnter your choice = ");
	scanf("%d", &p);

	switch (p)
	{
	case 1:
		while (i <=n)
		{
			temp = i*i;
			sum += temp;
			i++;
		}
		printf("\nSum of squares = %d", sum);
		break;
	
	case 2:
		while (i <= n)
		{
			temp = i*i*i;
			sum += temp;
			i++;
		}
		printf("\nSum of cubes = %d", sum);
		break;
	
	case 3:
		while (i <= n)
		{
			temp = i*i*i*i;
			sum += temp;
			i++;
        }

		printf("\nSum of quads = %d", sum);
		break;

	default:
		printf("\nSorry wrong choice");
	}
	return 0;
}