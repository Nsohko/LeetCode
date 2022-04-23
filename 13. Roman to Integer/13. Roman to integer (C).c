#include <stdio.h>
#include <string.h>

struct key {
char roman;
int dec;
}keys[7] = {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
	};
	
typedef struct key key;
int romantointeger(char inp[]);

int main() 
{
    char inp[] = "CII";
    int out = romantointeger(inp);
    printf("%d",out);
    return 0;
}

int returndecimal(char rom)
{
    for (int i = 0; i < 7; i++)
    {
        if (keys[i].roman == rom)
	{
	    return keys[i].dec;
	}
    }
    return -1;
}

int romantointeger(char inp[])
{
    int leng = strlen(inp);
    int i = 0;
    int out = 0;
    while (i < leng)
    {
        int val1 = returndecimal(inp[i]);
	if(i + 1 < leng)
        {
	    int val2 = returndecimal(inp[i + 1]);
	    if (val2 > val1)
	    {
	        out += (val2 - val1);
		i += 2;
	    }
	    else
	    {
	        out += val1;
		i++;
	    }
        }
	else
	{
	    out += val1;
	    i++;
	}
    }
    return out;
}
