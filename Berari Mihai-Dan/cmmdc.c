#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmmdc(int a, int b){
	if (b == 0)
		return a;
	else
		return cmmdc(b, a % b);
}

int main(){
	printf("%d", cmmdc(4, 24));
	system("pause");
	return 0;
}