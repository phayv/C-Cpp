#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Hash{
public:
	Hash();
	int hash(string key);
	void add_item(string name, string sport);
	int num_of_items_in_index(int index);
	void print_table();
	void print_more_in_index(int index);
	void find_sport(string name);
	void remove_item(string name);

private:
	static const int table_size = 4;

	// Things inside Hash Table
	struct item {
		string name;
		string sport;
		item* next;
	};
	item* HashTable[table_size];

};

