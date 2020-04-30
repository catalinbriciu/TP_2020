#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int oglindit(int n){
	if (n == 0)
		return 0;
	else{
		printf("%d", n % 10);
		return oglindit(n / 10);
	}
}
int main(){
	printf("%d", oglindit(1331));
	system("pause");

	return 0;
}