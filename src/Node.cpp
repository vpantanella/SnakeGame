#include "Node.h"

Node::Node(int data) :data(data),next(0){}

void Node::setData(int data)
{
	this->data = data;
}

int Node::getData() const
{
	return data;
}

void Node::setNext(Node *node)
{
	next = node;
}

Node* Node::getNext() const
{
	return next;
}

Node::~Node()
{
	delete next;
	next = 0;
}