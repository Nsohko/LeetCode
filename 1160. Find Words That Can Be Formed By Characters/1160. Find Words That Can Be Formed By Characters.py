class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        output = 0

      # array to store the number of each character in chars. index 0 corresponds to the number of 'a', index 1 the number of 'b' and so on
        chars_array = [0] * 26

      # iterate through chars and initialise chars_array
        for char in chars:
            index = ord(char) - ord('a')
            chars_array[index] += 1

        # iterate through each word in words
        for word in words:
            word_leng = len(word)

          # a flag to check if the current word is good. Initialised to good
            good_string = True

          # make a copy of chars_array for use on the current word
            chars_array_copy = chars_array[:]
            
            # for each character in the word
            for char in word:
              # get the index of the current letter in chars_array
                index = ord(char) - ord('a')
              # if that letter is 0 or less than 0 in chars_array, it means there is no more "budget" of that character left
                if chars_array_copy[index] <= 0:
                  # Thus it is not a good string, and we can break the loop
                    good_string = False
                    break
                    
                else:
                  # else, reduce the "budget" of the character by 1
                    chars_array_copy[index] -= 1
                    continue
            # if it loops fully, and the good_string flag is still true, then we cad the length to output
            if good_string:
                output += word_leng
                
        return output
                
        
