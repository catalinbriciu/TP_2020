#include <stdio.h>
#include <stdlib.h>

int factorial( int value)
{
	if (value <= 1 )
		return 1;
	else
	return value * factorial(value - 1);
		
	
}

int digitSum(int val)
{
	int sum = 0;
	if (val < 10)
		return val;
	return (val % 10) + digitSum(val / 10);
}

int mannaPnueli(int value)
{
	if (value >= 12)
		return value - 1;
	else
		return mannaPnueli(mannaPnueli(value + 2));
}

int cmmdc(int val1, int val2)
{
	if (val2 == 0)
		return val1;
	else
		return cmmdc(val2, val1 % val2);
}

int fibonacci(int val)
{
	if (val == 0)
		return 0;
	else if (val == 1)
		return 1;
	else
		return(fibonacci(val - 1) + fibonacci(val - 2));

}

int invertDigits(int value, int inv)
{
	if (value == 0)
		return inv;
	else
		return invertDigits(value / 10, inv * 10 + value % 10);
}

int main()
{
	int value, opt, fact, dig_sum, manna, value1, value2, cmm, fibo, inv_dig, inv=0;
	
	do
	{
		printf("1.Factorial \n");
		printf("2.Digit sum \n");
		printf("3.Manna-Pnueli \n");
		printf("4.CMMDC \n");
		printf("5.Fibonacci \n");
		printf("6.Invert digits \n");
		printf("0.Exit \n");
		printf("Select an option in this menu: \n");
		scanf("%d", &opt);
		printf("Type in the principal number you would like to work with in the single-parameter methods: ");
		scanf("%d", &value);
		switch (opt) {
		case 0: exit(0);
			break;
		case 1:
			fact = factorial(value);
			printf("The factorial value of %d is %d \n", value, fact);
			break;
		case 2:
			dig_sum = digitSum(value);
			printf("Sum of the digits is %d \n",dig_sum);
			break;
		case 3:
			manna = mannaPnueli(value);
			printf("Manna-Pnueli(%d)= %d \n", value, manna);
			break;
		case 4:
			printf("Value 1: ");
			scanf("%d", &value1);
			printf("value 2: ");
			scanf("%d", &value2);
			cmm = cmmdc(value1, value2);
			printf("CMMDC of %d and %d is %d \n", value1, value2, cmm);
			break;
		case 5:
			fibo = fibonacci(value);
			printf("Fibonacci for %d is: %d", value, fibo);
			break;
		case 6:
			inv_dig = invertDigits(value);
			printf("This is what inverted digits of %d look like: %d", value, inv_dig);
			break;
		}
	} while (1);
	system("pause");
	return 0;
}