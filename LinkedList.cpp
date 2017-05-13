/*
 * LinkedList.cpp
 *
 *  Created on: May 1, 2017
 *      Author: David Storey
 */

#include "LinkedList.h"
#include <iostream>

using namespace std;

//Constructor
NumberList::NumberList() {
	head = nullptr;
	tail = nullptr;
}

//Destructor
NumberList::~NumberList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr = head;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//Adds a value to the end of the list

void NumberList::appendNode(int num)
{
	ListNode *newNode;
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	//If statement creating the list if no list previously existed.

	if (!head){
		head = newNode;
		tail = newNode;
	}

	//Else statement using tail to append the node.

	else
	{
		newNode->previous = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

//Adds the value before the first number that is greater in the list

void NumberList::insertNodeInSortedOrder(int num)
{
	ListNode *newNode = nullptr;
	ListNode *nodePtr = nullptr;
	ListNode *previousNode = nullptr;
	newNode = new ListNode;
	newNode->value = num;

	//If statement placing node at the head if it is the first node created.

	if(!head)
	{
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;

		//Traversing the list

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		/*If/else if statements to deal with cases at the beginning and end of the list without creating seg
		  faults, as well as ensure proper placement of head and tail pointers.*/

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else if (nodePtr != nullptr)
		{
			nodePtr->previous = newNode;
			previousNode->next = newNode;
			newNode->next = nodePtr;
			newNode->previous = previousNode;
		}
		else if (nodePtr == nullptr)
		{
			previousNode->next = newNode;
			newNode->next = nullptr;
			newNode->previous = previousNode;
			tail = newNode;
		}
	}
}

void NumberList::addToStart(int value)
{
	ListNode *newNode;
	ListNode *nodePtr;
	newNode = new ListNode;
	newNode->value = value;

	//If statement creating the list if no list previously existed.

	if (!head){
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
	}

	//Else statement placing new node at the front, using the head pointer.

	else
	{
		nodePtr = head;
		head = newNode;
		newNode->next = nodePtr;
		nodePtr->previous = newNode;
	}
}

void NumberList::insertNodeAtLoc(int loc)
{
	int value, count = 0;
	ListNode *nodePtr;
	ListNode *previousNode;
	ListNode *newNode;

	//Dyanmically allocating new node, getting value for it, and placing user-defined value in the node.

	newNode = new ListNode;
	cout << "What value would you like to insert at position " << loc << "?";
	cin >> value;
	newNode->value = value;
	nodePtr = head;
	previousNode = nullptr;

	//Traversing the list with a trailer keeping track of previous node position.

	while(nodePtr != nullptr && count < loc)
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
		count++;
	}

	/*If/Else if statements as sanity check, as well as dealing with cases at the beginning and end
	  of the lists without creating seg faults and ensuring proper placement of head and tail pointers.*/

	if (nodePtr == nullptr && count < loc)
		cout << "The list is not that long!\n";
	else if (nodePtr == nullptr && count == loc)
	{
		previousNode->next = newNode;
		newNode->previous = previousNode;
		newNode->next = nullptr;
		tail = newNode;
	}
	else if (nodePtr != nullptr && count == loc)
	{
		previousNode->next = newNode;
		newNode->previous = previousNode;
		newNode->next = nodePtr;
		nodePtr->previous = newNode;
	}
}

//Function returning the value of a user-specified list location.

int NumberList::getNodeValueAtLocation(int loc)
{
	int value, count = 0;
	ListNode *nodePtr;

	//If statement with an early return if no list created.

	if (!head)
	{
		cout << "List not yet created.\n";
		return 0;
	}
	nodePtr = head;

	//Traversing the list while keeping track of what number node it is on.

	while(nodePtr != nullptr && count < loc)
		{
			nodePtr = nodePtr->next;
			count++;
		}

	//If/else if statement as sanity check on list length.

	if (nodePtr == nullptr && count < loc)
		cout << "The list isn't that long!\n";
	else if (count == loc)
		value = nodePtr->value;
	return value;
}

//Function merging two nodes, stored the summed value in the first node and deleting the second.

void NumberList::mergeTwoNodes(int a, int b)
{
	ListNode *nodePtrA;
	ListNode *nodePtrB;
	ListNode *previous;
	ListNode *temp;
	int valueA, valueB, countA = 0, countB = 0;
	bool beyondTheList = false;
	nodePtrA = head;

	//Finding the location of the first node.

	while(nodePtrA != nullptr && countA < (a-1))
	{
		nodePtrA = nodePtrA->next;
		countA++;
	}

	//If/else if statement as sanity check on list length.

	if (nodePtrA == nullptr)
	{
		cout << "Location "<< a << "is beyond the list!\n";
		beyondTheList = true;
	}
	else if (countA == (a - 1))
		valueA = nodePtrA->value;
	nodePtrB = head;

	//Finding the location of the second node.

	while(nodePtrB != nullptr && countB < (b-1))
	{
		previous = nodePtrB;
		nodePtrB = nodePtrB->next;
		countB++;
	}

	//If/else if statement as sanity check on list length.

	if (nodePtrB == nullptr)
	{
		cout << "Location "<< b << "is beyond the list!\n";
		beyondTheList = true;
	}
	else if (countB == (b - 1))
		valueB = nodePtrB->value;

	//If statement checking that neither location is beyond the list length.

	if (!beyondTheList)
	{
		nodePtrA->value = valueA + valueB;
		temp = nodePtrB->next;
		previous->next = temp;

		/*Dual if/else if statements dealing with the second location being at the front or back of the list
		  without creating seg faults, and deleting the second node to avoid memory leaks. */

		if (temp != nullptr)
			temp->previous = previous;
		else if (temp == nullptr)
			tail = previous;
		if (nodePtrB->previous == nullptr)
			head = nodePtrB->next;
		delete nodePtrB;
	}
}

//Function swapping two nodes position in the list, while maintaining their value and addresses.

void NumberList::swapNodes(int a, int b)
{
	ListNode *nodePtrA;
	ListNode *nodePtrB;
	ListNode *previousA;
	ListNode *previousB;
	ListNode *nextA;
	ListNode *nextB;
	int countA = 0, countB = 0;
	bool beyondTheList = false;

	//If statement with an early return if no list created.

	if (!head)
	{
		cout << "List not yet created.\n";
		return;
	}
	nodePtrA = head;

	//Locating the first node.

	while(nodePtrA != nullptr && countA < (a-1))
	{
		previousA = nodePtrA;
		nodePtrA = nodePtrA->next;
		countA++;
	}

	//If statement checking to see if first location is beyond the list.

	if (nodePtrA == nullptr)
	{
		cout << "Location "<< a << "is beyond the list!\n";
		beyondTheList = true;
	}
	nodePtrB = head;

	//Locating the second node.

	while(nodePtrB != nullptr && countB < (b-1))
	{
		previousB = nodePtrB;
		nodePtrB = nodePtrB->next;
		countB++;
	}

	//If statement checking to see if second location is beyond the list.

	if (nodePtrB == nullptr)
	{
		cout << "Location "<< b << "is beyond the list!\n";
		beyondTheList = true;
	}

	//If statement checking that neither location is beyond the list.

	if (!beyondTheList)
	{

		//Getting addresses of previous and next nodes in the list independent of the nodes to be swapped.

		nextA = nodePtrA->next;
		nextB = nodePtrB->next;
		nodePtrA->previous = previousB;
		nodePtrA->next = nextB;
		nodePtrB->next = nextA;
		nodePtrB->previous = previousA;

		/*Dual if/else if statements for each node, dealing with either being at the front or back without
		  seg faults, as well as properly placing head and tail pointers.*/

		if (previousA != nullptr)
			previousA->next = nodePtrB;
		else if (previousA == nullptr)
			head = nodePtrB;
		if(previousB != nullptr)
			previousB->next = nodePtrA;
		else if (previousB == nullptr)
			head = nodePtrA;
		if (nextA != nullptr)
			nextA->previous = nodePtrB;
		else if (nextA == nullptr)
			tail = nodePtrB;
		if (nextB != nullptr)
			nextB->previous = nodePtrA;
		else if (nextB == nullptr)
			tail = nodePtrA;
	}
}

//Function to remove all duplicates from the list

void NumberList::removeAllDuplicates()
{
	ListNode *nodePtr;
	ListNode *nodePtrDup;
	ListNode *nodePtrDupNext;
	ListNode *nodePtrDupPrev;
	int value;

	//If statement with early termination if there is no list created yet.

	if (!head)
	{
		cout << "List not yet created.\n";
		return;
	}
	nodePtr = head;

	/*Nested while statements to search for duplicates of each node, and cut the duplicate out of the list,
	  deleting the duplicate node to avoid memory leaks.*/

	while (nodePtr != nullptr)
	{
		value = nodePtr->value;
		nodePtrDup = nodePtr->next;
		while (nodePtrDup != nullptr)
		{
			nodePtrDupNext = nodePtrDup->next;
			nodePtrDupPrev = nodePtrDup->previous;
			if (nodePtrDup->value == value)
			{
				if (nodePtrDupPrev != nullptr)
					nodePtrDupPrev->next = nodePtrDupNext;
				if (nodePtrDupNext != nullptr)
					nodePtrDupNext->previous = nodePtr;
				else if (nodePtrDupNext == nullptr)
					tail = nodePtrDupPrev;
				delete nodePtrDup;
			}
			nodePtrDup = nodePtrDupNext;
		}
		nodePtr = nodePtr->next;
	}
}

//Function for deleting a node of specified value

void NumberList::deleteNodeOfValue(int num)
{
	ListNode *nodePtr;
	ListNode *previousNode;
	ListNode *temp;

	//If statement with an early return if no list created.

	if (!head)
		{
			cout << "List not yet created.\n";
			return;
		}

	//If statement dealing with if the head is the value to be deleted.

	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			if (nodePtr != nullptr)
				nodePtr->previous = previousNode;
		}
		if (nodePtr)
		{
			temp = nodePtr->next;
			previousNode->next = temp;

			/*If/else if statement to ensure proper placement of the tail and avoid seg faults, deleting
			  specified node to avoid memory leaks.*/

			if (temp != nullptr)
				temp->previous = previousNode;
			else if (temp == nullptr)
				tail = previousNode;
			delete nodePtr;
		}
	}
}

//Function for deleting a node at a user specified location

void NumberList::deleteNodeAtLocation(int loc)
{
	ListNode *nodePtr;
	ListNode *previous = nullptr;
	ListNode *next;
	int count = 0;
	nodePtr = head;

	//Locating the proper node.

	while(nodePtr != nullptr && count < loc)
		{
			previous = nodePtr;
			nodePtr = nodePtr->next;
			count++;
		}

	//Sanity check

	if (nodePtr == nullptr && count < loc)
		cout << "The list isn't that long!\n";
	else if (count == loc)
	{
		next = nodePtr->next;

		//If/else if statement to ensure proper placement of the tail and avoid seg faults.

		if (next != nullptr && previous != nullptr)
		{
			next->previous = previous;
			previous->next = next;
		}
		else if (next == nullptr)
		{
			previous->next = nullptr;
			tail = previous;
		}
		else if (previous == nullptr)
		{
			next->previous = nullptr;
			head = next;
		}

		//Deleting the node to avoid memory leaks.

		delete nodePtr;
	}

}

//Function for displaying the list, including an option for displaying the list with memory address pointers.

void NumberList::displayList() const
{
	ListNode *nodePtr;
	char memChoice;
	nodePtr = head;
	cout << "Would you like to display the list with memory locations included? (y/n)";
	cin >> memChoice;

	//If/else if/else statements to deal with yes, no, or improperly formatted user choice.

	if (memChoice =='y' || memChoice == 'Y')
	{
		cout << "Head = " << head << endl;
		while (nodePtr)
		{
			cout << "Previous address: "<< nodePtr->previous << ", value: " << nodePtr->value << ", next address: " << nodePtr->next << "\n";
			nodePtr = nodePtr->next;
		}
		cout << "Tail = " << tail << endl;
	}
	else if (memChoice == 'n' || memChoice == 'N')
	{
		while (nodePtr)
			{
				cout << "Value: " << nodePtr->value << endl;
				nodePtr = nodePtr->next;
			}
	}
	else
		cout << "Invalid choice, returning to main menu.\n";
}
