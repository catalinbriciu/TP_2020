#include <stdio.h>
#include <stdlib.h>

int s1[100], s2[100], x, vf1, vf2;
void Punctul_1() {
	scanf("%d", &x);
	while (x) {
		s1[++vf1] = x % 8;
		x /= 8;
	}

}
void Punctul_2() {
	int i;
	for (i = vf1; i; i--)
		if ((s1[i] & (s1[i] - 1)) != 0)
			s2[++vf2] = s1[i];
}
void Punctul_3() {
	int i;
	for (i = vf2; i; i--)
		if ((s2[i] & 1 << 0) && (s2[i] & 1 << 2))
			printf("%d\n", s2[i]);


}

int main() {
	Punctul_1();
	Punctul_2();
	Punctul_3();
	return 0;
}