#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int v[MAX];
int i=1;
int k; // k - varf stiva
int m,n,p;
int isS, isV;

void init(int k)
{
	v[k]=0;
}

int succesor(int k)
{
	if(v[k]<n)
	{
		v[k]++;
		return 1;
	}
	else return 0;
}

int valid(k)
{
	for(i=1;i<k;i++)
	if(v[i]==v[k]) return 0;
	return 1;
}

int solution(k)
{
	if(k==p && v[k-1]<v[k])
    return 1;
    else return 0;
}

void print()
{
	for (i=1;i<=p;i++)
	printf("%d ",v[i]);
	printf("\n");
}

void back(int k)
{
	k=1; init(k);
	while (k>0){ 
	isS=0;isV=0;
	if (k<=n) 
	
	do{ 
	isS=succesor(k);
	if (isS) isV=valid(k);
	} 
	while (isS && !isV); 
	if (isS) 
	if (solution(k)) 
	print(); 
	else
	 { 
	 k++;
	 init(k);}
	else k--;
	}
}

int main()
{
    printf("n=");
    scanf("%d", &n);
    printf("p=");
    scanf("%d", &p);
    back(n);
}

/*if(k==p)
    return 1;
else
    return 0;*/
