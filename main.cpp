/*
 * main.cpp
 *
 *  Created on: May 1, 2017
 *      Author: David Storey
 */
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	int num = 0, value, location, b;
	NumberList x;
	while (num != 12)
	{
		cout: "Current list: \n";
		x.displayList();
		cout << endl;
		cout << "Menu:\n";
		cout << "------------------------------------\n";
		cout << "1. Display the value of a specified location.\n";
		cout << "2. Add a node at a specific location.\n";
		cout << "3. Add a node at the beginning of the list.\n";
		cout << "4. Add a node at the end of the list.\n";
		cout << "5. Add a node ahead of the first greater node value.\n";
		cout << "6. Delete a node by node value.\n";
		cout << "7. Delete a node by location.\n";
		cout << "8. Swap two nodes.\n";
		cout << "9. Add two nodes together, removing the second from the list.\n";
		cout << "10. Remove duplicates from the list.\n";
		cout << "11. Exit\n";
		cout << "------------------------------------\n";
		cout << "Please enter the number of your choice.";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "What location would you like the value of?";
			cin >> location;
			cout << "The value of that node is: " << x.getNodeValueAtLocation(location) << endl;
			break;
		}
		case 2:
		{
			cout << "Where would you like to insert a value?";
			cin >> location;
			x.insertNodeAtLoc(location);
			break;
		}
		case 3:
		{
			cout << "What value would you like to add to the beginning of the list?";
			cin >> value;
			x.addToStart(value);
			break;
		}
		case 4:
		{
			cout << "What value would you like to add to the end of the list?";
			cin >> value;
			x.appendNode(value);
			break;
		}
		case 5:
		{
			cout << "What value would you like to insert in the list?";
			cin >> value;
			x.insertNodeInSortedOrder(value);
			break;
		}
		case 6:
		{
			cout << "What value would you like to remove from the list?";
			cin >> value;
			x.deleteNodeOfValue(value);
			break;
		}
		case 7:
		{
			cout << "What node would you like to delete?";
			cin >> location;
			x.deleteNodeAtLocation(location);
			break;
		}
		case 8:
		{
			cout << "What is the first node you would like to swap?";
			cin >> location;
			cout << "What is the second node you would like to swap?";
			cin >> b;
			x.swapNodes(location, b);
			break;
		}
		case 9:
		{
			cout << "What is the first node you would like to add? (The result will take the place of this node";
			cin >> location;
			cout << "What is the second node you would like to add? (This node will be removed)";
			cin >> b;
			x.mergeTwoNodes(location, b);
			break;
		}
		case 10:
		{
			x.removeAllDuplicates();
			cout << "Duplicates removed.\n";
			break;
		}
		case 11:
			break;
		default:
			cout << "Invalid selection.  Please enter the number of your choice.";
		}
	}
	return 0;
}



