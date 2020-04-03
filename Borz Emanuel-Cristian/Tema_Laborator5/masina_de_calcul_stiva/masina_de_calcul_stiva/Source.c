#include<stdio.h>
#include<string.h>
#include<conio.h>
#pragma warning(disable:4996)
int v[20];  int vf = 0, i, n;
void Push(int k){
	v[++vf] = k;
}
int wipe_data(){
	/*while (vf!=0)
		vf--;*/
	vf = 0;
	return v[vf];
}
int Pop(){
	vf--;
	return v[vf];
}
void suma(){
	int sum = 0;
	for (int i = 1; i <= vf; i++)
	sum = sum + v[i]; 
	wipe_data();
	printf("S=%d", sum);
}
void afisare_stiva()
{
	int i;
	printf("\n\n");
	for (i = 1; i <= vf; i++)
		printf("%d ", v[i]);
	printf("\n");
}
int main()
{
	char input;  int nr,s=0;
	
	while (1)
	{
		scanf("%c", &input);
		if (input == 'p'){
			scanf("%d", &nr);
			//printf("%u", input);
			Push(nr);
		 }
		if (input == '+'){ 
			suma();  
			afisare_stiva();
		}
		if (input == ','){
			Pop();
			printf("\n \n");
			afisare_stiva();
		}
		if (input == '.'){
			wipe_data();
			afisare_stiva();
		}
		if (input == 'e')
			exit(0);
	}
	
	return 0;
}
