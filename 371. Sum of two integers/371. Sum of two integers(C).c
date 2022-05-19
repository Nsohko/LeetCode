#include <stdio.h>
#include <math.h>
// TOTAL_BITS is the size of an integer
#define TOTAL_BITS 32

// a function to sun two integer x and y without the use of the + or - operator
int BinarySum(int x, int y)
{
        // This solution works by essentially doing manual long addition where it carries over the one into the next bit in the case that the current bit overflows
        // It uses the exact same method used when manually adding two numbers by hand 

	int result = 0;
	
        // I am iterating through each bit in the integer, where curbit is the "index" of the bit and curbit_val is the value held in that bit
        // for example, curbit = 0 corresponds to 1st bit which stores the value of 2^0 = 1 in curbit_val. curbit = 3 is the 4th bit which corresponds to a curbit_val of 2^3 = 8. It is noted that curbit_val increases by a factor of 2 for every bit
        // Also note that these are unsigned integers as they are always above 0. The final bit of these unsigned integers is a curbit_val of 2^31, which occurs when curbit = 32. Thus, using unsigned int lets me hold the max value of curbit_val. An unsigned int works linearly in that the value of each bit is 2 * the value of the previous bit, letting this solution work. If I used a normal integer, that last bit is the sign bit and does not actually correspond to a magnitude. Thus, the max curbit_val of a normal int is 2^30 only, which corresponds only to 31 bits, so my curbit_val would overflow on the final iteration
               
                // I just intiliase an unsigned int to 0. Note that this is also a unsigned int, since at some point I need it's value to equal 2^31 when the last bit is on, which would overflow a regular integer (since the last bit is used for signing on normal signed int)
		unsigned int nextbit_val = 0;
		
                // I check that curbit is equal to 30 or less. Ie basically I'm checking that curb it is not the last bit, but there is still at least 1 bit to the left of it. Note that the index of the final bit is 31, since I chose to 0 index it
                // case 1: there is one or more empty bits to the left of curbit. This means I have not yet reached the end of the integer, and there could still be significant bits to the left. I need to get the value of the nextbit for future use, which can just be found by multiplying curbit_val by 2. Since there are empty bits to the left of curbit, nextbit_val will not overflow, as instead the next bit will simply swap to 1
                // case 2: if curbit = 31, it means we are now on the last index of the integer already. Any value that I receive in the algorithm below that is supposed to go on the next bit should be thrown away as there are no more bits to store that data. Also note that since there are no more bits to the left of curbit now, if multiply curbit_val by 2, there will be an integer overflow, since there are no more bits to the left of cut it to swap to 1. Thus, I can leave nextbit_val as 0
		if (curbit < TOTAL_BITS - 1)
		{
			nextbit_val = curbit_val * 2;
		}
	  
                // this is how I find whether the current bit at curbit index of integers x and y is at 0 or 1
                // curbit_val is an integer with all bits at 0, except for the bit at curbit index. For eg, if curbit is 2, curbit_val is 0b . . . 0100, where the dots all represent the leading 0s (since there are 32 total bits in curbit_val)
                // The & operator works by setting a bit in a resultant to 1 if both corresponding bits in its operands are 1, else setting that bit in the output to 0. It does this for each bit in the operands
                // consider int val1 = x & curbit_val
                // since curbit_val 's bits are all 0 except for the bit at curbit index, the & operator will automatically set all these corresponding bits in val1 to 0
                // for the bit at curindex tho, it is 1 is curbit_val. If it is also 1 in x, the & operator will set the corresponding bit in val1 to 1. Else if the bit at curbit is 0 in x, it will set the bit at curbit in val1 to 0, since both operant bits are not 1
                // This way I can isolate the bit at cut it index in x. If that bit is 1 in x, it will also be 1 in val1 with all other bits in val1 being 0. Else if that bit is 0 in x, the correspond bit is val1 will also be 0 along with all the other bits in val1
 
                // Thus, val1 records the value of the bit at the curbit index of x, which equals the value of the bit at the curbit index of val1, while all other bits are set to 0 in val1. val2 does the same for y.
                // Note: if val1 is 0, that means that the value of the bit in curbit index of x must have been 0, since if val1 == 0, all bots in val1 (including the one at curbit index) must be 0. This is a quick way to check whether the value of the bit at curbit index is 0 or 1. The same can be done for val2 and y
		int val1 = x & curbit_val;
		int val2 = y & curbit_val;
		
		// case 1: Both val1 and val2 are not 0. Thus, the bit at curbit index of both x and y was 1
                // This would cause an overflow at the current bit of result, which means I need to carry over a 1 to the nextbit 
                // I can leave the value of the bit at curbit index of result, as in this case the carry over is independent of that value (ie happens regardless). Thus, if the value of curbit in result is 1, I can leave it as 1, or if the value of curbit in result is 0, I can leave it as 0
		if (val1 != 0 && val2 != 0)
		 	{
                         // The | operand works by setting a bit in a resultant to 1 if at least 1 bit of the two corresponding bits in its operands is 1, for each bit in its operands. Ie 0b0101 | 0b0001 = 0b0101
                         // in this case, all I have to do is to turn the next bit on result to 1, while leaving curbit and the rest of result as is
                         // nextbit_val is such that all it's bits are 0 except for the bit at (curbit + 1) index. Thus, if curbit == 2, nextbit_val = 0b . . . 1000, where the dots all represent leading 0s (since there are 32 totals bits in nextbit_val)
                         // Since the bit at next bit is 1 in nextbit_val, when I use the | operator on it and result, it will set the corresponding bit in result to 1, which is nextbit
                         // for the rest of the bits, since all the other bits of nextbit_val are 0, they will just follow the value of the corresponding bits in result. Ie if a bit is 1 in result, the | operator will return 1 for that corresponding bit in output. If a bit is 0 in result, the | operator will return 0 since that bit would be 0 in both result and nextbit_val
                         // this allows me to set next bit in result to 1, while leaving all other bits as is
		 	 result = result | nextbit_val;
		 	}
                // case 2: Either val1 or val2 is not 0, but not both. Thus, the value of the bit at curbit index is 1 for x and 0 for y or vice versa
		else if (val1 != 0 || val2 != 0)
		{
                        // subcase 1: the value of the bit at the curbit index of result is 1. Same method as above is used to calculate the value of the bit at curbit index of result
                        // in this case, again, there will be an overflow at the current bit of result, which means I again need to carry over a 1 to the next bit
                        // However, in this case, since it is overflowing after combining with the digit in the curbit of result, I will need to set the value of curbit to 0, before carrying over the 1
			if ((result & curbit_val) != 0)
		   {
			   result = result ^ curbit_val;
		   	   result = result | nextbit_val;
		   }
		   else
		   {
			   result = result | curbit_val;
		   }
		}
		
	}
	
	return result;
	
}

int main() {
	int x = 2;
	int y = -3;
	
	int result = BinarySum(x, y);
	
	printf("%d", result);
	
	return 0;
}
