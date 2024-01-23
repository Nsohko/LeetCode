class Solution:
    def reverseWords(self, s):

        # Add a space to the end of s to ensure that the last word is reversed too (the algorithm below flips the previous word when it encounters a space
        s += ' '

        # This will be my output
        output = ""

        # This is the starting index of the current word, initialised to 0
        word_start = 0

        # iterate through s
        for i in range(len(s)):

            # when it comes across a space, it has reached the end of the word
            if s[i] == ' ':
                # now iterate across the word in reverse. the word starts at index word_start and ends at index i - 1 (since index i is the space)
                for j in reversed(range(word_start, i)):
                    # add the reversed word to output
                    output += s[j]
                    
                # add a space to output to account for the speration between words
                output += ' '

                # the next word will start at the index after the space, which is i+1
                word_start = i + 1
                

            else:
                continue

        # the algorithm above adds an extra space to the end of output, so we need to remove that
        return output[0:-1]
