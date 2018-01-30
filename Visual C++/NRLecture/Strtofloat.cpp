#include<stdio.h>
#include<conio.h>
void strtoflt(char *);
float power(int);
int main(void)
{
	char arr[10];
	printf("Enter your string = ");
	scanf("%s", arr);

	strtoflt(arr);
	return 0;

}

void strtoflt(char *x)
{
	float a=0;
	int i = 0;
	while (x[i]!='.')
	{ 
		if (x[i] == '\0')
		{
			printf("\nFloat value = %f", a);
			return;
		}
		a = a * 10 + (x[i]) - ('0');
		i++;
	}
	
	i++;

	int j = 1;
	while (x[i] != '\0')
	{
		float devide = power(j++);
		a = a + (1 / devide)*((x[i++]) - ('0'));
			

	}

	printf("\nFloat value = %f", a);
}

float power(int x)
{
	int value = 1;
		for (int i = 0; i < x; i++)
		{
			value = value * 10;
		}

		return value;
}