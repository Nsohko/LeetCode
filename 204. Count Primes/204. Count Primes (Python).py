# this solution uses the sieve of ertosthenes method, the same as my second C solution. I opted not to implement the more simple naive first solution from the C code, as that is really simple
def countPrimes(n):
    # creates a list to keep track of which numbers are primes. Same as the C solution, each index corresponds to the value, and if it is true, that value is a prime, else it is not a prime. For eg the index 0 corresponds to the value 0, while the index 50 corresponds to value 50. If PrimeList[50] is False, it means 50 is not prime
    # although we don't use 0 and 1 in our solution (since 1st prime is 2), I still give them spots in the list to create a direct correlation between list index and value, as they will now be equal
    PrimeList = [True for i in range(n+1)]
 
    # since 2 is my first prime, I start with i = 2
    i = 2
    
    # I iterate through the list till i * i exceeds n (this is equivalent to i exceeding sqrt(n)). This is because by this point all non-prime values less than n would have been marked already. See the C solution for the proof
    while i * i <= n:

      # if the corresponding Boolean in PrimeList has not been marked as False yet, this number is a prime number
      if PrimeList[i]:

        # I must now mark all multiples of this new prime number as false. The first unique multiple of this prime number that has not been marked yet is i * i (see C solution for more details), so I start there and increment by i till the end of the list, marking each multiple as False
        for multiple in range(i*i, n+1, i):
          PrimeList[multiple] = False

      i += 1
    
    # count will keep track of the number of prime numbers 
    count = 0

    # I iterate though the list starting from index 2. This is because 0 and 1 are technically not prime numbers despite being marked as true above. I iterate till len(PrimeList) - 1 exclusive. This is because the leetcode problem only wants me to give the number of primes STRICTLY less than n. However it should be noted that if I wanted the number of primes less than n inclusive, I could simply iterate till len(PrimeList) exclusive instead, since my above algorithm did check for n, which is the last index in PrimeList
    for index in range(2, len(PrimeList)):
      if PrimeList[index]:
        count += 1
    return count

# for more details, see the second solution in my C solution to this same problem
