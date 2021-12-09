#include <stdio.h>

// A function to that find the most frequent
void checkmostfrequent(int *new, int *no)
{
	int konst = 0, n = 0, count = 0, initial = 0, max = 0, frequency = 0, length = 0;
	length = *no;
	// A loop throught the lenght 
	for (konst = 0; konst < length; konst++)
	{
		for (n = 0; n < length; n++)
		{
			if (*(new + konst) == *(new + n))
			{
				count = count + 1;
			}
		}

		if (frequency < count)
		{
			frequency = count;
			max = *(new + konst);
		}
		count = 0;
	}
	*no = frequency;
	*new = max;
}

// Drivers function
int main(void)
{
	//declearing input variable to be 1,
	int input = 1;


	while (input == 1)
	{
		int number[100];
		int i = 0, j = 0, length = 100;
		printf("Please enter numbers between 0 and 1000 and End with a negative number\n");
		for (i = 0; i < length; i++)
		{
			printf("number:");
			scanf("%d", &number[i]);
			if (number[i] > 999 || number[i] == 0)
			{
				//printf("you enter incorrect no, please reenter the no\n");
			}
			if (number[i] < 0)
			{
				length = i;
			}
		}
		for (i = 0; i < length; i++)
		{
			if (number[i] < 1000 && number[i] > 0)
			{
				number[j] = number[i];
				j = j + 1;
			}
		}
		checkmostfrequent(&number[0], &j);
		if (j == 0)
		{
			printf("\nThere was no valid number entered!");
		}
		else if (j == 1)
		{
			//printf("\nThe frequency of each number is same.");
		}
		else
		{
			printf("\nThe no %d occurs a total of %d times\n", number[0], j);
		}
		printf("\nDo you want to continue again? Press 1 or 0 to discontinue: ");
		scanf("%d", &input);
	}
	return 0;
}