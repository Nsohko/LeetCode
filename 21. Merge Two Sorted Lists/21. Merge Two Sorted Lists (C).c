#include <stdio.h>
#include <stdlib.h>

// A macro to get the length  of an array
#define length(array) ((int)(sizeof(array)/sizeof(array[0])))

struct node // A linked list node
{
	int val;
	struct node *next;
};

typedef struct node node;

/* Note that in this programme's implementation of a linked list, I don't create a linked list object to contain and access the head node. Instead I declare and access the head node directly. 
This has some advantages and disadvantages as seen below. For the alternative method of declaring another linked list object, see the python solution to this same problem */

// Function to initialise a linked list node
node* nodecreator(int val) 
{
	node* newnode = (node*)malloc(1*sizeof(node));
	newnode -> val = val;
	newnode -> next = NULL;
	return newnode;
}

// Initialises a linked list with the values in the array vals[] and then returns the head node
node* initialiser(int vals[], int leng) 
{
	node* headnode;
	if (leng == 0) // Just checks for the case of an empty linked list
	{
		headnode = NULL;
		return headnode;
	}
	headnode = nodecreator(vals[0]);
	node* currnode = headnode;
	for (int i = 1; i < leng; i++)
	{
		node* newnode = nodecreator(vals[i]);
		currnode -> next = newnode;
		currnode = newnode;
	}
	return headnode;
}

// Prints out all the values in a linked list starting from a particular node
void nodeprinter(node* curnode)
{ 
	while (curnode != NULL)
	{
		printf("%d ",curnode -> val);
		curnode = curnode -> next;
	}
	printf("\n");
}

// Inserts a value (val) at the end of a linked list. Note that I've passed a reference to the head node's pointer as the parameter. This same concept applies to the functions below too
void endinsert(node **head_ref, int val)
{
	node* newnode = nodecreator(val);

        // I had to pass the head node's pointer's address into the function, rather than the head node's pointer itself, as I need to modify the head node's pointer in the case it is NULL below (for eg if the linked list was empty). Thus, I have to pass the head node's pointer by reference
	if (*head_ref == NULL)
	{
		*head_ref = newnode;
		return;
	}
	node* curnode = *head_ref;
	while (curnode -> next != NULL)
	{
		curnode = curnode -> next;
	}
	curnode -> next = newnode;
	return;
}

// Inserts a value (val) at  a specific position(pos) in the linked list
void insert(node **head_ref, int pos, int val)
{
	if (pos < 0)
	{
		printf("Pos must be more than 0!");
		return;
	}
	
	node *newnode = nodecreator(val);
	
        // In the case that pos == 0, I will need to modify the head node pointer itself (as the pointer will have to point at the newly created node instead). Thus, I had to pass the node's pointer's address to the function
	if (pos==0)
	{
		newnode -> next = *head_ref;
		*head_ref = newnode;
		return;
	}
	
        // I already checked for the case where the position for newnode to be added is 0 using the previous if statement. from here,the newnode will be inserted just after the curnode. Thus, the starting index for where i can insert the newnode is 1 (just after *head_ref)
	int curindex = 1; 
	
        // keeps iterating till curnode=NULL. if curnode==NULL, it means the loop has exceeded the linked list length, without curindex reaching pos. thus, pos was outside of max index. thus, for loop is exited and error code is printed
	for(node* curnode = *head_ref; curnode != NULL; curnode = curnode -> next) 
	{
                // checks whether the list has recahed the correct index for newnode to be inserted. if so, newnode is inserted and the function returns
		if(curindex == pos) 
		{
			newnode -> next = curnode -> next;
			curnode -> next = newnode;
			return;
		}
		curindex++; //increments curindex by 1
		continue;
	}
	printf("Linked list index out of bounds. Max index is %d\n", curindex-1);
}
	
void fullclear(node **head_ref)
{
   node* curnode =* head_ref;
   while (curnode != NULL)
   {
	   node *temp = curnode -> next;
	   free(curnode);
	   curnode = temp;
   }
   *head_ref = NULL;
}

void enddelete(node **head_ref)
{
	if (*head_ref == NULL)
	{
		printf("Linked list is already empty");
		return;
	}
	
	if ((*head_ref) -> next == NULL)
	{
		free(*head_ref);
		*head_ref = NULL;
		return;
	}
	
	node* prevnode = *head_ref;
	node* curnode = prevnode -> next; //curnode is the node we are checking. if curnode is the last node, we delete, else we continue traversing through the list. curmode starts at the second node, to make soace for prevnode, which is the node just before curnode. this is fine though, since we already checked whether the first nodd in the list(*head_ref which id tge head node) is the last nide using the orevious if block
	while (curnode -> next != NULL)
	{
		prevnode = prevnode -> next;
		curnode = curnode -> next;
	}
	node *temp = curnode -> next;
	free(curnode);
	prevnode -> next = temp;
	return;
}

void posdelete(node** head_ref, int pos)
{
	if (pos < 0)
	{
		printf("Pos must be more than 0!");
		return;
	}
	 
	if (*head_ref == NULL)
	{
		printf("Linked list is already empty");
		return;
	}
	
	node* temp;
	if (pos == 0)
	{
		temp=(*head_ref) -> next;
		free(*head_ref);
		*head_ref = temp;
		return;
	}
	
	int curindex = 1; //uses same principle as insert function above. i iterate through the list starting from the node with index 1, until curindex=pos. then i cna delete the node at that pos. I start with curindex as i already chekd the node iwth index 0(the head node) in the previous if loop
	for(node *prevnode = *head_ref, *curnode = prevnode -> next; curnode != NULL; prevnode = prevnode -> next, curnode = curnode -> next) //this is a slightly messy for loop , but what it is essentually doing is it first declares prevnode as *head_ref and curnide as prevnode->next. curnode is thr node we are checking the position of. we start with curnode at index 1 as we already accounted for the case where pos=0 in the orevious if block. our looping condition is whether curnode!=NULL. this is becuase when curnode hits NULL, it means we have reached the end of the list without curindex reaching pos. thus pos was out of the maximum index range. after very loop, we check if curindex==pos, as this means we have reached the node to be deleted, if not, we increase curindex by one as we continue iterateing theough the list, as we set prevnode to prevndoe->next and curnode to curnode->next. for the traditional alrernative to this somewhat complex for loop, please see the next function, valdelete
	{
		if (curindex == pos)
		{
			temp=curnode -> next;
			free(curnode);
			prevnode -> next = temp;
			return;
		}
		curindex++;
	}
	printf("Linked list index out of bounds. Max index is %d\n", curindex-1);
	
}

void valdelete(node **head_ref, int val)
{
	if (*head_ref == NULL)
	{
		printf("Linked list is already empty");
		return;
	}
	node *temp;
	if ((*head_ref) -> val == val)
	{
		temp = (*head_ref) -> next;
		free(*head_ref);
		*head_ref = temp;
		return;
	}
	
	node *prevnode = *head_ref;
	node *curnode = prevnode -> next;
	while (curnode != NULL)
	{  
		if (curnode -> val == val)
		{
			temp = curnode -> next;
			free(curnode);
			prevnode -> next = temp;
			return;
		} 
		prevnode = prevnode -> next;
		curnode = curnode -> next;
	}
	printf("Value is not in the linked list\n");
}

node *linkedlistmerger1(node *head1, node *head2);

node *recurslinkedlistmerger(node *head1, node *head2);
	
	



int main() {
	int lt1[]={1,5,8};
	int lt2[]={2,6,10};
	node* head1=initialiser(lt1,length(lt1));
	node* head2=initialiser(lt2,length(lt2));
	node* out=recurslinkedlistmerger(head1,head2);
	nodeprinter(out);
	printf("Done");
	return 0; 
}

node *linkedlistmerger1(node *head1, node *head2) //not that since i pass tge pointers as parameters, the catual values of head1 and head2 in the caller will be modified. thus, i cannot cl this function twice on the same two node pointers in tge same caller(see the python code fir a more detailed explanation). if i wanted to leave the linked lists associated with head1 and head2 unchanfed inbthe caller scope, i should only pass the nodes
{
	node* dummy = malloc(1 * sizeof(node));
	node* curnode = dummy;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1 -> val >= head2 -> val)
		{
			curnode -> next = head2;
			curnode = curnode -> next;
			head2 = head2 -> next;
		}
		else if(head2 -> val > head1 -> val)
		{
			curnode -> next = head1;
			curnode = curnode -> next;
			head1 = head1 -> next;
		}
	}
	if (head1 == NULL)
	{
		curnode -> next = head2;
		return dummy -> next;
	}
	if (head2==NULL)
	{
		curnode -> next = head1;
		return dummy -> next;
	}
	else
	{
		return NULL;
	}
}


node *recurslinkedlistmerger(node *head1, node *head2)
{
	if (head1==NULL)
	{
		return head2;
	}
	else if (head2==NULL)
	{
		return head1;
	}
	else
	{
		if(head1 -> val >= head2 -> val)
		{
			head2-> next = recurslinkedlistmerger(head1, head2->next);
 			return head2;
		}
		else if(head2 -> val > head1 -> val)
		{
			head1-> next = recurslinkedlistmerger(head1->next, head2);
			return head1;
		}
	}
	return NULL;
}
