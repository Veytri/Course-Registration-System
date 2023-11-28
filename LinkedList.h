#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;
//******************* 
// LinkedList class * 
//*******************
class LinkedList{  
	private:                    // private data
		struct ListNode{           
			string value;   
			struct ListNode *next;  // Pointer to the next node
		};
		ListNode *head;  // pointer to the first node
	public:        // public data
		LinkedList(){   // constructor
			head = nullptr;     // head pointer to nullptr
		}
		~LinkedList();   // destructor
		void appendNode(string); //to add node (courses)
        void deleteNode(string); //to delete node (courses) 
        void searchNode(string); //to search node (courses)
        void displayList(); //to display all nodes (courses)
};
//********************************************************* 
// appendNode appends a node containing the value (courses) 
// passed into newValue, to the end of the list.  
//*********************************************************
void LinkedList::appendNode(string item){  
	ListNode *newNode;  // to point to a new node
	ListNode *nodePtr; // to move throught the list
	newNode = new ListNode;  //  Allocate a new node and store newValue there. 
	newNode->value = item;   // assign value
	newNode->next = nullptr;  // newNode point to nullptr
	// If there are no nodes in the list,make newNode the first node.
	if(!head){
		head = newNode;
	}else{          // Otherwise, insert newNode at end
		nodePtr = head; // Initialize nodePtr to head of list. 
		while(nodePtr->next){     // Find the last node in the list. 
			nodePtr = nodePtr->next;
		}
	nodePtr->next = newNode;   // append newNode as the last node.
	}
}
//***************************************************************
// searchNode searce a node containing the value (courses) 
// to determine whether that value is contain in link list or not
//***************************************************************
void LinkedList::searchNode(string item){
 ListNode *nodePtr; // To traverse throught the list
 ListNode *previousNode;  // To point to the previous node
 if (!head){ // If the list is empty, do nothing. 
 cout <<"List is Empty\n";   // display when list is empty
 system("pause");  
}
 if (head->value == item)   // Determine if the first node is the one.
 {
 cout<<"\n Found at first node \n"; 
 cout << head->value << endl; // Display the value in this node.
 system("pause");
 } 
 else
 {
 nodePtr = head;     // Initialize nodePtr to head of list 
 while (nodePtr != nullptr && nodePtr->value != item) // Skip all nodes whose value member is not equal to item.
 {
 previousNode = nodePtr; // position previousNode at position of nodePtr
 nodePtr = nodePtr->next; 
 }
 if (nodePtr) // If nodePtr is not at the end of the list,link the previous node to the node after nodePtr, then delete nodePtr.
 {
 cout<<"\n Found course\n"; 
 cout << nodePtr->value << endl;  // Display the value in this node.
 system("pause");
 } 
 else // otherwise, display information cannot search
 {
 cout<<"\nNot found this course\n";
 system("pause");
}
}
}
//******************************************************** 
// The deleteNode function searches for a node  (courses)
// with searchValue as its value. The node, if found, 
// is deleted from the list and from memory. 
//********************************************************
void LinkedList::deleteNode(string item){ 
	ListNode *nodePtr; // To traverse the list 
	ListNode *previousNode = nullptr; // To point to the previous node
	if(!head){ // If the list is empty, do nothing. 
		cout << "This is empty list" << endl;       // display when list is empty
		system("pause");      // pause the system, continue when press enter
	}
	if(head->value == item){         // Determine if the first node is the one.
		nodePtr = head->next;   // Position nodePtr at the head of the list. 
		delete head;       // delete from the list and from memory. 
		head = nodePtr;  // position head at the position of nodePtr
	}else{
		nodePtr = head;  // Initialize nodePtr to head of list 
		
		while(nodePtr != nullptr && nodePtr->value != item){// Skip all nodes whose value member is not equal to item
		previousNode = nodePtr;      // position previousNode at position of nodePtr
		nodePtr = nodePtr->next;  
	}
	    if(nodePtr){ // If nodePtr is not at the end of the list, link the previous node to the node after nodePtr, then delete nodePtr
	    	previousNode->next = nodePtr->next;
	    	delete nodePtr;
		}else{     // otherwise, display information cannot delete
			cout << "Cannot delete, maybe not has this course!" << endl;
			system("pause");
		}
		
	}
}
//*********************************************************
// displayList shows the value stored in each node (course) 
// of the linked list pointed to by head. 
//*********************************************************
void LinkedList::displayList(){
	ListNode *nodePtr = nullptr;  // To move through the list
	nodePtr = head;   // Position nodePtr at the head of the list. 
	while(nodePtr){           // While nodePtr points to a node, traverse the list.
		cout << nodePtr->value << endl; // Display the value in this node.
		nodePtr = nodePtr->next;// Move to the next node. 
	}
}
//************************************************** 
// Destructor 
// This function deletes every node  in the list. * 
//**************************************************
LinkedList::~LinkedList(){
	ListNode *nextNode; // To traverse the list 
	ListNode *nodePtr; // To point to the next node
	nodePtr = head; // Position nodePtr at the head of the list. 
	while(nodePtr != nullptr){ // While nodePtr is not at the end of the list
		nextNode = nodePtr->next;  //Save a pointer to the next node. 
		delete nodePtr; // Delete the current node. 
		nodePtr = nextNode; // Position nodePtr at the next node.
	} 
	head = nullptr;  // head pointer to nullptr
}
#endif
