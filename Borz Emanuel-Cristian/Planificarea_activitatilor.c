#include<stdio.h>
#include<stdlib.h>
#include<Bits.h>
#pragma warning (disable:4996)

typedef struct activ {
	int id, start, end;
}activity;

activity a[20];
int n,m, s[20];

void read()
{
	int i;
	printf("Number of planned activities: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("Activity #%d start date:", i);
		scanf("%d", &a[i].start);
		printf("Activity #%d end date:", i);
		scanf("%d", &a[i].end);
		a[i].id = i; // numarul activitatii
	}
}
void sort()
{
	int i, j; activity aux;
	for (i = 1; i < n; i++)
		for (j = i; j <= n; j++)
			if (a[i].end >= a[i].start) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
}
void solve()
{
	int i, j;  i = 0;
	printf("Activity %d \n", i);

	for (j = 1; j < n; j++){
			printf(" Activity %d \n", j);
			i = j;
	}
}


int main(){
	read();
	sort();
	solve();
	//print();
	return 0;
}
