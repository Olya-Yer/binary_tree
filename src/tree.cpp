#include <tree.hpp>
#include <iostream>
#include <limits.h>
#include <cstddef>
#include <assert.h>
#include <iomanip> 

Tree::Tree():root(0)
{}

void Tree::insert(int v)
{
	if(!root) {
		root = new Node(v);
		return;
	}
	insert_node(root,v);
	return;
}

void Tree::insert_node(Node* n, int v) 
{
	if(n->get_value() < v) {
		if(!n->get_right()) {
			Node* x = new Node(v);
			n->set_right(x);
			x->set_parent(n);
			return;
		}
		insert_node(n->get_right(),v);
		return;
	} else {
		if(!n->get_left()) {
			Node* x = new Node(v);
			n->set_left(x);
			x->set_parent(n);
			return;
		}
		insert_node(n->get_left(),v);
		return;
	}
}

Tree::Tree(const Tree& t)
	:root(NULL)
{
	if(NULL != t.root) {
		int v = t.root->get_value();
		root = new Node(v);
		assert(NULL == root);
		copy_tree(root, t.root);
	}
}
void Tree::copy_tree(Node* t, Node* f)
{
	Node* l = f->get_left();
	if(l) {
		int v = l->get_value();
		Node* n = new Node(v);
		t->set_left(n);
		copy_tree(n, l);
	}
	Node* r = f->get_right();
	if(r) {
		int v = r->get_value();
		Node *n = new Node(v);
		t->set_right(n);
		copy_tree(n, r);
	}
}
Tree::~Tree()
{
	if(root){
		delete_tree(root);
	}
}

void Tree::delete_tree(Node* r)
{
	if(r->get_left()) {
		delete_tree(r->get_left());
	}
	if(r->get_right()) {
		delete_tree(r->get_right());
	}
	delete root;
	root = NULL;
}


void Tree::print() const
{
	if(!root) {
		std::cout << "The tree is empty" << std::endl;
		return;
	}
	print(root);
}


void Tree::print2D(Node *current, int indent)
{
    if (current != nullptr)
    {
        print2D(current->get_left(), indent + 4);
        if (indent > 0) {
            std::cout << std::setw(indent) << " ";
        }
        std::cout << current->get_value() << std::endl;
        print2D(current->get_right(), indent + 4);
    }
}

void Tree::print(Node* r) const
{
	if(r){
		std::cout << r->get_value() << std::endl;
		print(r->get_left());
		print(r->get_right());
	}
}

bool Tree::contains(int v) const
{
	if(!root) {
		return false;
	}
	return contains(root,v);
}

bool Tree::contains(Node* r, int v) const
{
	if(!r){
		return false;
	}
	int s = r->get_value();

	if(v == s) {
		return true;
	}

	if(v > s) {
		return contains(r->get_right(), v);
	}
	return contains(r->get_left(),v);
}

Node* Tree::find_node(Node* r, int v)
{
	if(!r){
		return NULL;
	}
	int s = r->get_value();
	std::cout << s << "->" << v << std::endl;
	if(v == s) {
		return r;
	}

	if(v > s) {
		return find_node(r->get_right(), v);
	}
	return find_node(r->get_left(),v);
}

bool Tree::delete_node(int v) {
    return delete_node(root, v);
}

bool Tree::delete_node(Node* from, int v)
{
	if(NULL == from) {
		return false;
	}
	if(v < from->get_value()) {
		return delete_node(from->get_left(), v);
	}
	if(v > from->get_value()) {
		return delete_node(from->get_right(), v);
	}
	if( NULL == from->get_left() || NULL == from->get_right()) {
		Node* old_node = from;
		Node* parent = from->get_parent();
		if( NULL == from->get_left()) {
			if(parent->get_right() == from) {
				parent->set_right(from->get_right());
			} else {
				parent->set_left(from->get_right());
			}
		} else {
			if(parent->get_right() == from) {
				parent->set_right(from->get_left());
			} else {
				parent->set_left(from->get_left());
			}
		}
		delete old_node;
		return true;
	}
	Node* old_node = right_most(from->get_left());
	from->set_value(old_node->get_value());
	return delete_node(from->get_left(),from->get_value());
}

Node* Tree::right_most(Node* from)
{
	while(NULL != from->get_right()) {
		from = from->get_right();
	}
	return from;
}


bool Tree::is_balanced(Node* n)
{
	if(NULL == n) {
		return true;
	}
	int l = get_height(n->get_left());
	int r = get_height(n->get_right());
	if(l-r <=1 || l-r >= -1) {
		return true;
	}
	return false;
}

void Tree::rebalance(Node* r)
{
    if(is_balanced(r)) {
	    return;
    }
}

int Tree::get_height(Node* r)
{
	if(NULL == r) {
	    return 0;
	}
	return 1+ std::max(get_height(r->get_left()),get_height(r->get_right()));
}

void Tree::left_left_rotate(Node* r)
{
    Node* pivot = r->get_left();
    Node* b = pivot->get_right();
    Node* anc = r->get_parent();
    if(anc) {
	    if(r->get_value() < anc->get_value()) {
		    if(anc) {
			anc->set_left(pivot);
		    }
	    } else {
		    if(anc) {
			    anc->set_right(pivot);
		    }
	    }
    }
    pivot->set_right(r);
     r->set_left(b);
     if(root == r) {
	     root = pivot;
     }

}

void Tree::right_right_rotate(Node* r)
{
    Node* pivot = r->get_right();
    Node* b = pivot->get_left();
    Node* anc = r->get_parent();
    if(anc) {
	    if(r->get_value() < anc->get_value()) {
		    if(anc) {
			anc->set_left(pivot);
		    }
	    } else {
		    if(anc) {
			    anc->set_right(pivot);
		    }
	    }
    }
    pivot->set_left(r);
     r->set_right(b);
     if(root == r) {
	     root = pivot;
     }

}

void Tree::left_right_rotate(Node* root)
{
	
	left_left_rotate(root->get_left());
	right_right_rotate(root);
}

void Tree::right_left_rotate(Node* root)
{
	
	right_right_rotate(root->get_right());
	left_left_rotate(root);
}

