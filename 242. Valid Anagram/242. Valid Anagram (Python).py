# A simple solution that works on the principle that if two anagram are sorted, they will be equal. This has a time complexity of O(nlog(n)) due to the sort function, and a constant space complexity 
def isAnagram(s, t):
    if sorted(s) == sorted(t):
      return True
    else: 
      return False
     
# this solution exploits the fact that the question mentioned that only the lower case English alphabets will be in the strings. It makes use fo the fact that the number of each letter in each of the two strings must be equal if they are anagrams.
# it works on O(n) time complexity 
  # this is a list that keeps count of the number of times we came across each character. In this list, index 0 corresponds to the letter a, index 1 to letter b and so on. This improves our efficiency by letting the list act something like a hash table. However, this constrains it as it means it can only accommodate up to 26 distinct character (ie each alphabetical letter) in the strings. However, this is fine in this case, since the question specified that only the 26 alphabetical letters in lower case would be present  
  tracker = [0] * 26

  # every time we see a particular letter in the first string, we increase it's corresponding count by 1
  for letter in s:
    tracker[ord(letter) - ord('a')] += 1
  # every time we see a letter in the second string, we decrease it corresponding count by 1
  for letter in t:
    tracker[ord(letter) - ord('a')] -= 1
   
  # thus, if the two strings had equal number of every letter, the count in each index of tracker list should be 0
  for count in tracker:
    if count != 0:
      return False
  else:
    return True
 
print(isAnagram2('pot', 'top'))
