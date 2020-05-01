#include<stdio.h>
int Inversat(int n, int nou)
{
    if (n == 0)
        return nou;
    else
        return Inversat(n / 10, nou * 10 + n % 10);
}
int main()
{
    int n, nou = 0;
    printf("introduceti numarul: "); scanf("%d", &n);
    printf("Numarul interschimbat: %d", Inversat(n, nou));
    return 0;
    system("pause");
}