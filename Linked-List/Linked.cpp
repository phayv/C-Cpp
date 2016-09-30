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
	nodepointer n = new node; 
	n->next = NULL; 
	n->data = addData;

	if (head != NULL) {
		curr = head; 
		while (curr->next != NULL) { 
			curr = curr->next; 
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
		cout << delData << " was deleted from the list.\n";
	}
}

void Linked::print_list() {
	curr = head;
	while (curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}
