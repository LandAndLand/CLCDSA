# include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a+b==c)
	{
		printf("Yes\n");
	}
	else 
	{
		if (b+c==a)
		{
			printf("Yes\n");
		}
		else 
		{
			if (c+a==b)
			{
				printf("Yes\n");
			}
			else 
			{ 
				printf("No\n");
			}
		}
	}
	system("pause");
}