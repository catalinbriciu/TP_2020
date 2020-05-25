#include<string.h>
#include<stdio.h> 
#include<stdlib.h>
void TdHanoi(int n, char a, char b, char c)
{
	if (n == 1)
		printf("Punem discul de la %c la %c\n", a, b);
	else
	{
		TdHanoi(n - 1, a, c, b);
		printf("Punem discul de la %c la %c\n", a, b);
		TdHanoi(n-1, c, b, a);
	}
}
int main()
{
	int n;
	printf("Dati numarul de discuri n:\n");
	scanf("%d",&n); 
	void TdHanoi(n,a,b,c);
	printf("%d", TdHanoi);
	getch();
	return 0;
	system("pause");
}