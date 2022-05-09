#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
	int val;
	struct node *next;
}node;


// Since C has no built in hash table, unlike python's sets, I opted to only the implement this one solution in C
// To expand on C's functionality and include more data structures, like hash tables, I should consider moving over to C++ at some point!
bool linkedlistcycle2(node* head)
{
    node *slow, *fast;
    slow = fast = head;
    while (slow && fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast)
        {
            return true;
        }
        continue;
    }
    return false;
}
