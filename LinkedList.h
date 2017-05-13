/*
 * LinkedList.h
 *
 *  Created on: May 1, 2017
 *      Author: David Storey
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_



using namespace std;

class NumberList {
private:
	struct ListNode {
		int value;
		struct ListNode *next = nullptr;
		struct ListNode *previous = nullptr;
	};

	ListNode *head;
	ListNode *tail;

public:
	NumberList();

	~NumberList();

	void addToStart(int);
	void appendNode(int);
	void insertNodeInSortedOrder(int);
	void insertNodeAtLoc(int);
	void deleteNodeOfValue(int);
	void deleteNodeAtLocation(int);
	int getNodeValueAtLocation(int);
	void mergeTwoNodes(int, int);
	void swapNodes(int, int);
	void removeAllDuplicates();
	void displayList() const;
};
#endif /* LINKEDLIST_H_ */

