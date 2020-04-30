#include <stdio.h>
#include<stdlib.h>
int digitsSum(int num)
{
		int digit = num % 10;

		if (num == 0)
		
			return digit;

		else
		
			return digit + digitsSum(num / 10);
}

int main()
{
	int res, num;

	scanf("%d", &num);
	res = digitsSum(num);

	printf("The sum of digits in %d is %d", num, res);

	return 0;

}
