#pragma once
class Node
{
private:
	int data;
	Node *next;
public:
	Node(int data = -420);
	void setData(int);
	int getData() const;
	void setNext(Node*);
	Node* getNext() const;
	~Node();
};