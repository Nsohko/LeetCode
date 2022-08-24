def isIsomorphic(s, t):
   # a dict that maps letters in s to corresponding letter in t
   mapping_s = {}
   # a dict that maps letters in t to correponfing letter in s
   mapping_t = {}
   
   len_s = len(s)
   len_t= len(t)
   
   # if not same length, it is guaranteed to be false
   if len_s != len_t:
       return False
     
    else:
      # iterate theough each char in the word
      for i in range(len_s):
        char_s = s[i]
        char_t = t[i]
        
        # if both chars are in their respetive mapping dict
        if char_s in mapping_s and char_t in mapping_t:
          # check that mapping matches
          if mapping_s[char_s] == char_t and mapping_t[char_t] == char_s:
            continue
          else:
            # if mapping dont match it is false
            return False
        elif not(char_s in mapping_s or char_t in mapping_t):
          # case where the char in s and the char in t are both not in their respective dicts. thus, a new mapping must be created
          mapping_s[char_s] = char_t
          mapping_t[char_t] = char_s
         else:
           # if only one of char from s or t is in their repsective dictionary but not both, it is guranteed to be a mismatch. thus, false is returned
                    return False
            else:
              # return true after hcekcing all xhar
                return True
