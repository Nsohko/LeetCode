#include <stdio.h>
#include<stdbool.h>
#include<string.h>


bool isValidparenthesis(char * s)
{
    int leng = strlen(s);
    char stack[leng + 1];
    stack[0] = '\0';
    int top = 0;
    empty = true; 
    for (int i = 0; i < leng; i++)
    {
        char curval = s[i];
        char topstack = stack[top];
        if (curval ==' (' || curval == '[' || curval == '{')
        {
            top++;
            stack[top] = curval;
            empty = false;
        }
        else
        {
            switch(curval)
            {
                case ')':
	            if (topstack != '(')
	            {
		        return false;
		    }
		    top--;
		    break;
		case ']':
		    if (topstack != '[')
		    {
		        return false;
		    }
		    top--;
                    break;
		case '}':
		    if (topstack != '{')
		    {
		        return false;
		    }
		    top--;
		    break;
		default:
		    return false;
		    break;
	    }
        }
    }
    if (top == 0 && !empty)
    {
        return true;
    }
    return false;
}

int main(void)
{
    char inp[] = "()[]{}";
    bool out = isValidparenthesis(inp);
    printf("%i",out);
    return 0;
}
