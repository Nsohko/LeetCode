#include <stdio.h>
#include <stdbool.h>

// this is just a useful helper function that returns to me the sum of the squares of all the digits of a number. It just helps beaten up the code in my actual solution function below
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

// this is my solution function, it works using Floyd's cycle detection programme. This is the same algorithm used in my C solution for the linked list cycle problem in leetcode
bool isHappy(int num)
{
        // start with two nodes, which are in this case integers, initial used to the first term. The purpose of this algorithm is to see whether as I keep summing the square of the digits of the number, does it result in a loop, or does it reach the end state, which is 1
        // the "process" that links two nodes together in this case is the summing of the squares of the numbers digits
        // the slow int will undergo this process once per cycle, while the fast int will undergo it twice. If there is no cycle, the fast integer will ultimately reach 1, signifying the end, which means the number is happy. If there is a cycle, the fast integer will ultimately catch up to the slow integer again, as it loops through the cycle, at a value other than 1. This means the number is not happy
        // this is what this algorithm has implemented.
	int slow, fast;
	slow = fast = num;
	
        // if fast ever reaches 1, it means the cycle has an end, so the number is happy. This, the function returns true
	while (fast != 1)
	{
                // slow changes by 1 step per cycle
		slow = squaresum(slow);
                // fast changes by 2 steps per cycle 
		fast = squaresum(squaresum(fast));
		
                // if fast ever equals slow at any value other than 1, it means fast has "caught up" to slow. This, there must be a cycle, so number is not happy, so function returns false.
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
