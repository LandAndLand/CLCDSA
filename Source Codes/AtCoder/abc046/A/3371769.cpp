#include <stdio.h>
#include <stdlib.h>
int  main()
{
	int a, b, c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if (a == b && b == c)
	{
		printf("1");
	} 
	else
	if (a != b && a != c && b != c)
	{
		printf("3");
	}
	else printf("2");
	system("pause");
}