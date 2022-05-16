#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// A very basic helper solution to check if a number is a prime number. Works on O(n^0.5) time complexity 
bool isPrime(int num)
{
    // Note that I only need to iterate till i * i exceeds num. this is the same as saying i exceeds sqrt(num). This is because the "midpoint" of the factors of any number is sqrt(num) * sqrt(num). On either side of this, the expressions will be the same just swapped
    // for eg consider 16. I can express it as follows: 1*16, 2*8, 4*4, 8*2, 16*1. Observe that on either side of 4*4, the expressions are the same, just flipped. By testing whether 16 is divisible by 1 and 2, I am already implicitly testing its divisibility by 16 and 8 respectively, so I do not need to test 8 and 16 again. Thus, the upper limit of values I need to test is sqrt(num)
    // writing the condition as i * i <= num also saves time compared to writing i <= sqrt(num), because i * i is a lot faster to evaluate than sqrt(num)
    // this gives this function a time complexity of O(n^0.5)
    for (int i = 2; i * i <= num ; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// My very basic first attempt at a solution. It is very slow, though it is accurate and self explanatory. Works on O(n^1.5) time complexity overall and O(1) space complexity  
int countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            count ++;
        }
    }
    
    return count;
}

// This is a much faster solution that works on the principle of the sieve of Eratosthenes.
int countPrimes2(int n)
{
    // I first create an array, where each index corresponds to a number, ie index x corresponds to the number x. For example index 0 corresponds to 0 and index 50 corresponds to 50. Note that we don't use 0 or 1 in this algorithm, but we still include them in the array to have easier more direct correspondence by equality between index and the number 
    // this is an array of bools. At the end of the entire algorithm, if the bool in a certain index is True, it means the corresponding number is prime, if the bool is false, the corresponding number is not prime
    bool PrimeList[n+1];
    
    // Initilises the whole bool array to initllay equal True
    memset(PrimeList, true, sizeof(PrimeList));

    // since 2 is the first prime number, we start with 2.
    // in this loop, we essentially iterate through all the prime numbers (till the square root of n) and then set all multiples of that prime number to false
    // we only need to iterate till the square root of n, because by the time we reach this value, all non prime numbers in up till n would have been marked already. This is because the first "unique" non prime multiple of any prime number,x, is x * x. Any previous multiple of x would also have to be a multiple of another prime (eg x * 2 or x * 3) and as such would be marked off already. Thus, when we reach a value of a prime number, i, such that i > sqrt(n) (which is equivalent to saying i * i > n), the first unique multiple of i that has not yet been marked is i * i, which exceeds n, and is hence not useful in our solution. All previous multiple of i, eg i * 2, i * 3, have already been marked when the loop was on 2 or 3, etc respectively. Thus, by the time I reach i = sqrt(n), all relevant non- primes would be marked alr
    // the limit of i * i <= n can also be somewhat explained using the same logic as the isPrime function above, in that once i exceeds sqrt(n), we are checking the same expression, just that they are flipped 
    // alternatively, we can explain this using the fact that if a number has no divisors less than it's square root, it's a prime. Thus, when we reach sqrt(n), we would have reached the sqrt of the biggest relevant number (n) to determine whether or not it is a prime. By this point, we would have reached the sqrt of all relevant numbers less than n, so we would already be able to determine if they were prime or not
    for(int i = 2; i * i <= n; i ++)
    {
        // this checks whether it is prime. If it is marked as true in PrimeList at the point we come across it, it means the value cannot be expressed as a multiple of any smaller numbers. Thus, it must be prime
        // if it is, we will have to mark out all the following multiples of this prime number as false, for future reference 
        if (PrimeList[i])
        {
            // As written above, the first new "unique" multiple of a prime number, that has not already been marked, is i * i, where i is a prime number. All previous multiples of i  can be expressed as i * c, where c is a combination of previous prime numbers. Thus, when the loop was on those previous prime numbers, this multiple would be marked as false already. For example, consider the multiple i * 2. This multiple would have already been marked as false when the loop was on 2. Thus, we do not need to check it again, and can instead start at i * i, which is the first new unmarked multiple
            // we keep iterating till we reach the last number,n
            // after every cycle, we increment multiple by i, ie we sat multiple = multiple + i. This is because this will directly give us the value of the next multiple of i
            for (int multiple = i * i; multiple < n; multiple = multiple + i)
            {
                // since multiple is a multiple of a prime number, it is not a prime number itself. Thus, we set it to False
                PrimeList[multiple] = false;
            }
        }
    }
    
    int count = 0;

    // Finally, we iterate through the entire list, and count the number of times we see a box marked as true. These boxes correspond to a prime number and hence the number of boxes that are True is equal to the number of prime numbers
    // note that although our algorithm above also determines whether n is prime or not, the leetcode question asks us for the count of primes STRICTLY less than n, this we ignore n.
    for (int Prime = 2; Prime < n; Prime++)
    {
        if (PrimeList[Prime])
        {
            count ++;
        }
    }
    return count;
}

// for more information on the above algorithm see the leetcode hint section for this problem.
// also a note on time complexity: a nested for loop will increase time complexity, but two spectate for loops will not. For eg, a for loop nested in a for loop will have a time complexity of O(n^2), but two separate for loops that run one after another will only have a time complexity of O(n), the same as a single for loop (though the two separate for loops will take longer than the single for loop)
int main() {
    printf("%d", countPrimes2(2));
    return 0;
}
