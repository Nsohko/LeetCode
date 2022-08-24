#include <stdio.h>
#include <stdbool.h>

bool isIsomorphic(char * s, char * t){
 
    // this soln uses two arrays one for S and one for t. each index in the array correpsononds to the ascii char with equal ascii val. the number stored in a particular index is the unique map value of that char in that word. if another char has the smae non zero value in its corrsposnding index in the other words index, the two chars from each word are paired
    // for eg if mapping_s[6] == mapping_t[4]==5. it means that the char with ascii 6 in s maps to char with ascii 4 in t and vice versa
	int mapping_s[256] = {0};
	int mapping_t[256] = {0};
	
	// tge specifuc char index im looking at in s and t
	int char_index = 0;
	
	// my unique map value. it increments every time a successful mapping js madr to remain unique
	int unique_map = 1;
	
	for (char char_s = s[char_index], char_t = t[char_index]; char_s != '\0' && char_t != '\0'; char_s = s[++char_index], char_t= t[char_index])
	{
		if (mapping_s[(int) char_s] == mapping_t[(int) char_t])
		{
		    // if both valued are equal to 0, it means both are unmapped, so a new mapping will be made
			if (mapping_s[(int) char_s] == 0)
			{
				mapping_s[(int) char_s] = unique_map;
	  			mapping_t[(int) char_t] = unique_map;
 				unique_map ++;
			}
			else
		   {
		   // if borh are ewual to a non zero value, just continue
			   continue;
		   }
 		 }
 		 else
 		 {
 			 // if the values are different, they are not mapped, so return false
 			 return false;
 		 }
	}
	if (s[char_index]== '\0' && t[char_index]== '\0')
	{
	    // check that both s and t reached their end, so they are of same lngrh. if so return true
		return true;
	}
	else
	{
	    // if s and t are diff length, return false
		return false;
	}
}


int main() {
	
	char *s = "egg";
	char *t = "add";
	
	int result = isIsomorphic(s,t);
	printf("%d", result);
	
	return 0;
}
