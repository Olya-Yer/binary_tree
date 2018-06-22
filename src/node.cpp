#include <iostream>
#include <node.hpp>

Node::Node(int v):
	value(v)
	,left(NULL)
	,right(NULL)
	,parent(NULL)
{
}

void Node::set_left(Node* l)
{
    left = l;
}

Node* Node::get_left()
{
	return left;
}

void Node::set_right(Node* r)
{
	right = r;
}
Node* Node::get_right()
{
	return right;
}

void Node::set_parent(Node* r)
{
	parent = r;
}

Node* Node::get_parent()
{
	return parent;
}
int Node::get_value()
{
    return value;
}

void Node::set_value(int v)
{
    value = v;
}
