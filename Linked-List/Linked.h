#pragma once

using namespace std;

class Linked{

public: // we should put functions in here
	Linked();
	void add_node(int addData);
	void delete_node(int delData);
	void print_list();

private: // we should put variables in here

	typedef struct node {
		int data;
		node* next; // point to next node in list

	}*nodepointer;

	nodepointer head;
	nodepointer curr;
	nodepointer temp;

protected:
};

