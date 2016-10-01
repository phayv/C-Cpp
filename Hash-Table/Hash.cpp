#include <iostream>
#include <cstdlib>
#include <string>

#include "Hash.h"

using namespace std;

//CONSTRUCTOR
Hash::Hash() {
	for (int i = 0; i < table_size; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->sport = "empty";
		HashTable[i]->next = NULL;
	}
}

int Hash::hash(string key){
	int hash = 0;
	int index;
	
	for (int i = 0; i < key.length(); i++) {
		hash += ((int)key[i])*17;
	}

	index = hash % table_size; //store by remainder
	return index;
}
// CHAINING
void Hash::add_item(string name, string sport) {
	int index = hash(name);

	if (HashTable[index]->name == "empty") {
		HashTable[index]->name  = name;
		HashTable[index]->sport = sport;
	}
	else {
		item* pointer = HashTable[index];
		item* n = new item;
		n->name  = name;
		n->sport = sport;
		n->next  = NULL;

		while (pointer->next != NULL) {
			pointer = pointer->next;
		}
		pointer->next = n;
	}
}

void Hash::remove_item(string name) {
	int index = hash(name);

	item* delete_pointer;
	item* pointer1;
	item* pointer2;

	/*1 Case: Empty Bucket*/
	if (HashTable[index]->name == "empty") {
		cout << name << " is not in the Hash Table.\n";
	}
	/*2 Case: 1 Item containing name*/
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
		HashTable[index]->name  = "empty";
		HashTable[index]->sport = "empty";
		cout << name << " removed from Hash Table.\n";
	}
	/*3 Case: Multi Items, 1st item contains name*/
	else if (HashTable[index]->name == name) {
		delete_pointer = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delete_pointer;
		cout << name << " removed from Hash Table.\n";
	}
	/*4.1 Case: Multi Items, 1st item doesn't contain name*/
	else {
		pointer1 = HashTable[index]->next;
		pointer2 = HashTable[index];
		while (pointer1 != NULL && pointer1->name != name) {
			pointer2 = pointer1;
			pointer1 = pointer1->next;
		}
		/*4.2 Case: Multi Items, No items containing name*/
		if (pointer1 == NULL) {
			cout << name << " is not in the Hash Table.\n";
		}
		/*4.3 Case: Multi Items, Match Found*/
		else {
			delete_pointer = pointer1;
			pointer1 = pointer1->next;
			pointer2->next = pointer1;

			delete delete_pointer;
			cout << name << " removed from Hash Table.\n";
		}
	}
	
}

int Hash::num_of_items_in_index(int index) {
	int count = 0;
	if (HashTable[index]->name == "empty") {
		return count;
	}
	else {
		count++;
		item* pointer = HashTable[index];
		while (pointer->next != NULL) {
			count++;
			pointer = pointer->next;
		}
	}
	return count;
}

void Hash::print_table() {
	int num_of_elements;

	for (int i = 0; i < table_size; i++) {
		num_of_elements = num_of_items_in_index(i);
		cout << "------------------------------------\n";
		cout << "index: " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->sport << endl;
		cout << "Number of Items: " << num_of_elements << endl;
		cout << "------------------------------------\n";
	}
}

void Hash::print_more_in_index(int index) {
	item* pointer = HashTable[index];
	if (pointer->name == "empty") {
		cout << "index " << index << " is empty.\n";
	}
	else {
		cout << "index " << index << " contains:\n";
		while (pointer != NULL) {
			cout << "------------------------------------\n";
			cout << pointer->name  << endl;
			cout << pointer->sport << endl;
			cout << "------------------------------------\n";
			pointer = pointer->next;
		}
	}
}

void Hash::find_sport(string name) {
	int index = hash(name);
	bool name_exists = false;
	string sport;

	item* pointer = HashTable[index];
	while (pointer != NULL) {
		if (pointer->name == name) {
			name_exists = true;
			sport = pointer->sport;
			break;
		}
		pointer = pointer->next;
	}
	if (name_exists) {
		cout << "Favorite sport: " << sport << endl;
	}
	else {
		cout << name << "'s name is not in the Hash Table.\n";
	}
}


















