#include <stdio.h>
#include <stdbool.h>

// this uses same method as second solution in python solution
// note that s and t are proper strings and are thus null terminated
bool isAnagram(char *s, char *t)
{
    // an array to keep track of the count of each letter, where index 0 corresponds to the letter a, index 1 to letter b and so on
    int tracker[26] = {0};
    
    // iterate through the whole string s, incrementing corresponding counter in tracker array for each letter
    for(int index = 0; s[index] != '\0'; index ++)
    {
        char letter1 = s[index];
        // to get the corresponding array index for a particular letter, we simply have to subtract a from it, since a corresponds to 0 index
        tracker[(int) letter1 -'a'] ++;
    }
        
    // iterate through the whole string t, this decremnetinf corrsposnding counter for each letter in t
    for(int index = 0; t[index] != '\0'; index ++)
    {
        
        char letter2 = t[index];
        tracker[(int) letter2 - 'a'] --;
    }
    
    // if s and t are anagrams, they will have the same count for each letter. Thus, at the end, each index in tracker array should be 0 if s and t are anagrams
    for (int i = 0; i < 26; i++)
    {
        if (tracker[i] != 0)
        {
            return false;
        }
    }
    
    return true;
    
}

int main() 
{
    printf("%d", isAnagram("a", "jj"));
    return 0;
}
