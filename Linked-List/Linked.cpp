#include <iostream>
#include <cstdlib>

#include "Linked.h"

using namespace std;

Linked::Linked(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void Linked::add_node(int addData) {
	nodepointer n = new node; //nodepointer n points to new node
	n->next = NULL; // find the node n is pointing to and access its next element and set it to nothing
	n->data = addData;

	if (head != NULL) {
		curr = head; // curr pointer point to the head (front of list)
		while (curr->next != NULL) { // while the node that curr is pointing to not connected to NULL
			curr = curr->next; // make curr point to the node that the current node of curr is pointing to
		}
		curr->next = n; 
	}
	else {
		head = n;
	}
}

void Linked::delete_node(int delData) {
	nodepointer deletionpointer = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	
	if (curr == NULL) {
		cout << delData << " was not in the list\n";
		delete deletionpointer;
	}
	else {
		deletionpointer = curr;
		curr = curr->next;
		temp->next = curr;
		if (deletionpointer == head) {
			head = head->next;
			temp = NULL;
		}
		delete deletionpointer;
		cout << "The value " << delData << " was deleted.\n";
	}
}

void Linked::print_list() {
	curr = head;
	while (curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}