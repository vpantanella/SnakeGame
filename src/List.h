#pragma once
#include "Node.h"
#include <iostream>
class List
{
private:
	Node *head;
public:
	List();
	bool empty() const;
	void push_back(int);
	unsigned size() const;
	void insert_at(int, int);
	void delete_at(int);
	int get_at(int) const;
    void clear();
	~List();
};