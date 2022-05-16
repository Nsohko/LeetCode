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
    for(int i = 2; i * i <= n; i ++)
    {
        if (PrimeList[i])
        {
            for (int multiple = i * i; multiple < n; multiple = multiple + i)
            {
                PrimeList[multiple] = false;
            }
        }
    }
    
    int count = 0;
    
    for (int Prime = 2; Prime < n; Prime++)
    {
        if (PrimeList[Prime])
        {
            count ++;
        }
    }
    return count;
    
    
}

int main() {
    printf("%d", countPrimes2(2));
    return 0;
}
