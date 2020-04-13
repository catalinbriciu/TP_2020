#include<stdio.h>
#include<stdlib.h>

int i, k, n, c, v[100], solutie = 0;
char isS, isV = 0;
void Init(int k) { // k – vârful stivei//
	v[k] = 0; //iniþializeazã valoarea din varful stivei//
}
int Succesor(int k) {
	if (v[k] < n) { // se poate creºte valoarea din vârf//
		v[k]++; // se incrementeazã valoarea din vârf//
		return 1; // funcþia a avut success//
	}
	else // nu se poate creºte valoarea din vârf//
		return 0;
}

int Valid(int k) {
	for (i = 1; i < k; i++) // verificã dacã elementul din vârf este diferit de elementele precedente din stiva//
		if (v[i] >= v[k]) 
			return 0; 
		else
	        return 1;
}
int Solution(k) {
	return (k == c);
}
void Print() {
	printf("%d : ", ++solutie);
	for (i = 1; i <= c; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void Back() {
	k = 1; Init(k);
	while (k > 0) // cât timp stiva nu e vidã//
	{
		isS = 0; isV = 0;
		if (k <= c) // nu face sens depãºirea nivelului n în stivã//
			do { // repetã cât timp//
				isS = Succesor(k);
				if (isS) isV = Valid(k);
			} while (isS && !isV); // existã succesor dar nu este valid//
			if (isS) //este succesor si este valid//
				if (Solution(k)) // verificã candidatul la soluþie//
					Print(); // afiºeazã soluþia//
				else { // dacã nu este soluþie//
					k++;
					Init(k); // creºte vârful stivei ºi iniþializeazã//
				}
			else // nu existã succesor pentru valoarea curentã din stivã//
				k--; // se coboarã o poziþie în stivã//
	}
}
int main()
{
	n = 6; c= 5;
	Back();
	return 0;
	system("pause");
	return 0;

}