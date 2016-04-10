#include "List.h"

using std::cerr;
using std::endl;

List::List() :head(0){}

bool List::empty() const
{
    return (head == 0) ? true : false;
}

void List::push_back(int data)
{
	if (empty())
		head = new Node(data);
	else
	{
		Node *current=head;
		while (current->getNext() != 0)
			current = current->getNext();
		current->setNext(new Node(data));
		//current = 0;
	}
}

void List::clear()
{
    delete head;
    head=0;
}

unsigned List::size() const
{
	if (!empty())
	{
		unsigned i=0;
		Node *current=head;
		while (current->getNext() != 0)
		{
			current = current->getNext();
			i++;
		}
		current = 0;
		return i+1;
	}
	return 0;
}

void List::insert_at(int index, int data)
{
	if (empty())
		head = new Node(data);
	else
	{
		Node *current=0;
		if (index <= 0)
		{
			current = new Node(data);
			current->setNext(head);
			head = current;
            current=0;
		}
		else
		{
            int i=0;
            Node *current=head,*former=0;
            while((i<index)&&(current->getNext()!=0))
            {
                former=current;
                current=current->getNext();
                i++;
            }
            if(i==index)
            {
                former->setNext(new Node(data));
                former->getNext()->setNext(current);
            }
            else
                current->setNext(new Node(data));
            former=0;
		}
        current=0;
	}
}

void List::delete_at(int index)
{
	if (empty())
		cerr << "List is empty!" << endl;
	else
	{
		int i=0;
		Node *current=head, *former=0;
		while ((current->getNext() != 0)&&(i < index))
		{
			former = current;
			current = current->getNext();
			i++;
		}
		if (index == i)
		{
			former->setNext(current->getNext());
			current->setNext(0);
			delete current;
		}
		else
			cerr << "Index is out of bound!" << endl;
		current = former = 0;
	}
}

int List::get_at(int index) const
{
	if (empty())
		cerr << "List is empty!" << endl;
	else
	{
		int i=0;
		Node *current=head;
		while ((current->getNext() != 0)&&(i < index))
		{
			current = current->getNext();
			i++;
		}
		if (i == index)
		{
			i = current->getData();
			current = 0;
			return i;
		}
		else
		{
			cerr << "Index is out of bound!" << endl;
			current = 0;
		}
	}
	return -420;
}

List::~List()
{
    clear();
}
