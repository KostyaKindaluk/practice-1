#include <stdio.h>
#include <ctype.h>
#include <math.h>


int char_to_digit(char c)
{
	if (isdigit(c)) return c - '0';
	if (isalpha(c)) return tolower(c) - 'a' + 10;
	return -1;
}

double parse_decimal()
{
	double result = 0;
	double fraction = 0;
	double div = 1;
	int seen_dot = 0;
	char c;
	
	while ((c = getchar()) != EOF && c != '\n')
	{
		if (c == '.' && !seen_dot)
		{
			seen_dot = 1;
			continue;
		}
		
		int digit = char_to_digit(c);
		if (digit >= 0 && digit < 10)
		{
			if (!seen_dot)
			{
				result = result * 10 + digit;
			}
			else
			{
				div *= 10;
				fraction += digit / div;
			}
		}
	}
	
	return result + fraction;
}

long long parse_number(int base)
{
	long long result = 0;
	char c;
	
	while ((c = getchar()) != EOF && c != '\n')
	{
		int digit = char_to_digit(c);
		if (digit >= 0 && digit < base)
		{
			result = result * base + digit;
		}
	}
	
	return result;
}


int main()
{
	int base;
	scanf("%d", &base);
	getchar();
	
	if (base < 2 || base > 36)
	{
		printf("Invalid base\n");
	}
	
	if (base == 10)
	{
		double value = parse_decimal();
		printf("%.10g\n", value);
	}
	else
	{
		long long value = parse_number(base);
		printf("%lld\n", value);
	}
	
	return 0;
}
