#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice = 1;
	double a, b;

	while (choice != 0)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}
		if (choice == 1)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);
			printf("Result: %g\n", a + b);
		}
		if (choice == 2)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);
			printf("Result: %g\n", a - b);
		}
		if (choice == 3)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);
			printf("Result: %g\n", a * b);
		}
		if (choice == 4)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);
			if (b == 0)
			{
				printf("Error: division by zero\n");
			}
			else
			{
				printf("Result: %g\n", a / b);
			}
		}
	}
	printf("Bye!\n");
	return (0);
}
