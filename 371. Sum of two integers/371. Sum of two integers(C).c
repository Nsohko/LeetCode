#include <stdio.h>
#include <math.h>
// TOTAL_BITS is the size of an integer
#define TOTAL_BITS 32

// a function to sun two integer x and y without the use of the + or - operator
// This works on the assumption that the integers are stored as two's complements values. This will allow me to safely throw away any 1 that gets carried over beyond the final bit. It also lets me carry out addition and subtraction the same way, since when using twos complements to represent negative numbers, the addition of a negative number to a positive number (which is equivalent to subtraction) can be carried out as if I was just adding the two values in their binary form, which will give me the correct resultant value, also in its two's complement form. This is the default way C stores integers
// in the two's compelemnt method of storing integers, 2 - 3 = 2 + (-3) = 2 + two's complement representation of -3.
// the two's complement representation of the negative number -x can be found by inverting all the bits of x and then adding 1
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
		 	 // Note: there is 1 special case: in the case that we are on the last bit (curbit = 31), there will be no more bits to carry over the 1, instead we must simply throw away the carried over 1. Thus, in this case, result would simply not be modified. 
                         //Luckily my code accounts for this. When we reach the last bit and curbit = 1, nextbit_val is set to 0, which is 0b . . . 0000, where the dots are all 0s (This is done in the code above). By doing the | operand on result and 0, it will simply return back a number exactly equal to result unmodified 
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
                           // to set the value of the bit at cue it index from 1 to 0, I can use the ^ operator. This works by setting a resultant bit to 1 in the case that the two corresponding bits in the operant are different. Ie 0101 ^ 0011 = 0110
                           // recall that cut is such that all it's bits are 0 except for the bit at curbit index which is 1
                           // Thus, since the bit at curbit index of both result and curbit_val is 1, the ^ operator will set the corresponding bit in the output to 0
                           // for the rest of the bit, curbit_val has all bits set to 0, while result has a unique set of bits
                           // in the case that a bit at a particular index of result is 0, and given that the corresponding bit of curbit_val is also 0, the ^ value would return a 0 for the correposning bit in its output, since the two bits are the same in its input. Thus, wherever result has a 0 bit, the output will also have a 0 bit
                           // on the other hand, if a bit a particular index of result is 1, and given that the corresponding bit of curbit_val is 0, the ^ operator would return a 1 for the corresponding bit in its output, since the two input bits are different, Thus, wherever result has a 1 bit, the output will also have a 1 bit, except for the bit at the curbit index as explained above
                           // this way I can set the bit at curbit index of result from 1 to 0, while leaving the rest of result unmodified  
			   result = result ^ curbit_val;
        
                           // After that I will need to carry over the 1 to next bit. This is done the same way as above, using the | operator
                           // Similarly to above, when we reach the last bit (ie curbit = 31), I need to throw away the carried over 1. Same as above, my code handles this by setting nextbit_val to 0, which would return me back result when I do result | nextbit_val effectively throwing away the carried over 1. Note that in this case, I still need to set the value of curbit in result from 1 to 0, since it is still combining with the current bit of result, so the previous line of code still needs to execute
		   	   result = result | nextbit_val;
		   }
                   // subacase 2: value of the bit at curbit index of result is 0
                   // this is very simple, I just have to set the value of the curbit in result to 1
		   else
		   {
                           // to set a particular bit to 1, I can use the | operator as explained above, in this case, since I'm setting curbit to 1, my second operand for the | operator is curbit_val, instead of nextbit_val
			   result = result | curbit_val;
		   }
		}
                // Technically there is a case 3, where the val1 and val2 are both 0. Thus curbit of both x and y are both 0. Since 0 + 0 = 0, in this case I do not need to do anything, and instead just leave result as is
		
	}
	
	return result;
	
}

// Another possible solution. This works on the same principle of manual addition through carrying
// this solution first does addition of the two numbers without carry to get one value. It then gets another value which equal to the carried over bits, after that the algorithm sums this two values recursively using the same process. This is done until the carry equals 0
int getSum(int a, int b){
	
        // for the purposes of this solution, I'll use a to store the value of the sum (ignoring the carry) and b to store the value of the carry after every cycle
        // thus the end condition for the cycle is when b == 0, which means the carry is 0. Thus, the sun excluding carry will equal the actual sun. Since I stored the sun in a, I just have to return a after that
	while (b != 0)
	{
                // sun is a temporary value to hold the value of the sum of a and b excluding carry
                // the ^ operator will give me this value as it will give me a 1 where 1 bit is 1 in a and 1 bit is 0 in b. 
                // when both bits are 0 in a and b the ^ operator gives 0
                // finally when both bits are 1 in a and b, the ^ operator gives 0, which is correct since if both bits are 1 in a and b it means that that but must be carried over to the next bit and current bit must be set to 0
		int sum = a ^ b;
		
                // this is some very scuffed casting that I don't like, but there are not many alternatives. In C standard, support for the left shift of negative numbers eg -1<<5 is not supported for some reason. Thus, I first need to cast a&b to an unsigned int before shifting
                // the resultant value then must get auto cast back into an int since b is an int. Usually C does this by just taking the bits of the unsigned int and reading it using the two's complement method to get back a valid int, however, this is also risk
                // luckily some compilers have been optimised to allow the left shift of negative numbers, so in those cases such risky casting will not be needed
                // now to explain what I'm doing. b stores the value of the carried over bits. A bit will have to be carried over if both bits in a and b are 1. This can be found using & operator which will return 1 every time both bits are 1
                // also since once a bit is carried, it will be carried onto the next position, we must shift the carried bit to the left by 1 place, which is done by the << operator
		b = (unsigned int) (a & b) << 1;
		
                // finally set a to sum and continue with the loop till the carry value (b)= 0 
		a = sum;
	}
	
	return a;
}

int main() {
	int x = 2;
	int y = -3;
	
	int result = BinarySum(x, y);
	
	printf("%d", result);
	
	return 0;
}
