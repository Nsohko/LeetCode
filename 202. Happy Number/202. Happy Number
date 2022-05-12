#include <stdio.h>
#include <stdbool.h>

int squaresum(int num)
{
	int sum = 0;
	
	while (num > 0)
	
	{
		int curdigit = num % 10;
		sum += (curdigit * curdigit);
		num /= 10;
	}
	
	return sum;
}

bool isHappy(int num)
{
	int slow, fast;
	slow = fast = num;
	
	while (fast != 1)
	{
		slow = squaresum(slow);
		fast = squaresum(squaresum(fast));
		
		if (slow == fast && fast != 1)
		{
			return false;
		}
	}
	return true;
}

int main() {
	
	printf("%d", isHappy(19));
	return 0;
}
