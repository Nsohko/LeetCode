#include <stdio.h>
#include <stdlib.h>

// I chose to make my stack out of a linked list to give it easily variable size, unlike an array
// This node structure is just the data structure that represents 1 node in the linked list
typedef struct node
{
        // val is the value contained in the node 
	int val;

        // minval is very interesting and is the primary reason this solution works to find the minimum value of the stack in constant time
        // minval is the minimum value of all the stack nodes below the current node and including the current node
        // thus minval of any node in the stack will give me the minimum value contained anywhere below that node (including itself) on the stack
        // this to get the minimum value of the stack at any point, I just have to read this field of the stacks top node
        // this removed the error that may arise when popping a node that contained the original minimum value. With this method, if I pop such a node, the new stack minimum will just be given by minval of the next node, which is the next top node.
        // this is because the minbar if any particular mode does not consider the nodes above it, it only considers itself and nodes below it.
        // For eg, consider the stack: Node 1(top): 3 -> Node 2: 5 -> node 3: 1 -> node 4: 8 -> node 5: 6
        // the min sls for nodes 1-5 in order will be 1, 1, 1, 6, 6, since this is the minimum value of the nodes below and the node itself for each node.
        // thus, even as I pop minimum nodes, tge minval field of the next node will give me an accurate minval, once it gets pushed to top
	// since this process just needs to read the value, it is constant time complexity of O(1)
        int minval;

        // just a pointer to next node in linked list
	struct node *bottom;
	
}node;

typedef struct 
{
        // a pointer to the top node of the stack
        // the minval field of this node will contain the minimum value of this node and all the nodes below it
        // this the minval value of this node will give a constant time method to get the minimum value in the stack
	node *top;
	
} MinStack;

// this function just initialises a pointer to the stack
MinStack* minStackCreate() 
{
	MinStack *obj = malloc(1 * sizeof(MinStack));
	obj -> top = NULL;
	return obj;
}

// this function pushes a new node to the top of a stack
void minStackPush(MinStack* obj, int val) 
{
        // initialise a new node 
	node *newnode = malloc(1* sizeof(node));
	newnode -> val = val;

	// this if-else statement serves to compare the nodes value with the current minval from the previous head, to update the minval field of the newnode so that it accurately equals the minimum value of the newnode and all nodes below it. Since new node is pushed to top of the stack, all nodes will be below it. This, at that point of time, minval of newnode equals minval of stack
        // case 1: if the top node is NULL, the stack is empty, so the minval of the stack must the val of newnode. This, i update newnode's min am field to equal its value
        // case 2: if the newnodes value is the less than the current minval field of the current head of the linked list stack, it means that newnode's value is the new minimum. This, before pushing newnode to be the new head, I must update its minval field to equal its val, since val is now the minimum of the new node and all nodes below it in the entire list. Case 1 and case 2 are combined into the same if statement 
        // case 3: if the newnodes value is more than the current minval field of the current head of the linked list, it means that current head's minval will continue to be the minimum of the stack, even after the newnode is added to become the new head. This, the minimum value of newnode and all the modes under it, will just be the minval of the previous head, since it is less than newnode's value. Thus, newnodes minval will be set to current heads minval, before new node becomes the head. This is done in the else branch 
	if (obj -> top == NULL || newnode -> val < obj -> top -> minval)
	{
		newnode -> minval = val;
	}
	else
	{
		newnode -> minval = obj -> top -> minval;
	}
	
        // this code just places new mode as the new head
	newnode -> bottom = obj -> top;
	obj -> top = newnode;	
}

// this function just pops the topmost node form the stack and deletes it by freeing it.
void minStackPop(MinStack* obj) 
{
        // when the topmost node is popped using the code below, the new minimum of the list, will just be given by the minval field of the next node, since that node will now become the head
        // this is because the minval field of next node gives minimum value of itself and all nodes below it in the stack. In this case, that is just equivalent to minimum value of all nodes except the current head that is about to be popped.
        // this is perfect, as once we pop the node, our nee min cal should no longer consider the popped mode to be accurate
	node *temp = obj -> top;
	obj -> top = temp -> bottom;
	free(temp);
	
}

// this function just returns the value of topmost node in the stack
int minStackTop(MinStack* obj) 
{
	node *topnode = obj -> top;
	int topval = topnode -> val;
	return topval;
}

// this function just returns minimum value of all nodes in the stack
int minStackGetMin(MinStack* obj) 
{
        // the minimum value of all nodes in the stack is just given by the minval field of the topmost node, since that is the minimum value of the node and all nodes below it in the stack
        // this method is even resilient to if you pop the node with current minimum value, since the next node, that will become the new head, will contain the minimum value of the stack excluding the popped node that was above it, since the minval field only has the minimum value of the node and all nodes below it, but it ignores any nodes above it
        // this will accurately give us the new minimum value
	int minval = obj -> top -> minval;
	return minval;
}

// this function just deletes the stack and clears all memory associated with it 
void minStackFree(MinStack* obj) 
{
	node *curnode = obj -> top;
	while (curnode != NULL)
	{
		node *temp = curnode -> bottom;
		free(curnode);
		curnode = temp;
	}
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
