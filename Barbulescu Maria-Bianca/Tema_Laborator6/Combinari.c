#include <stdio.h>
#include <stdlib.h>
int n, p, sol[10];

void back(int k)
{
	int i;
	if (k == p + 1) {
		for (i = 1;i <= p;i++) printf("%d",sol[i]);
		printf("\n");
	}
	else {
		if (k > 1) sol[k] == sol[k - 1];
		else sol[k] = 0;
		while (sol[k] < n - p + k) {
			sol[k]++;
			back(k + 1);
		}
	}
}

void main()
{
	printf("n="); scanf("%d", &n);
	printf("p="); scanf("%d", &p);
	back(1);
	system("pause");
	return 0;
}