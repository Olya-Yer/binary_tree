#include <tree.hpp>
#include <iostream>
#include <limits.h>
#include <cstddef>
#include <assert.h>
#include <iomanip> 
#include <stack>
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
			balance_tree(n, 1, RIGHT);
			return;
		}
		insert_node(n->get_right(),v);
		return;
	} else {
		if(!n->get_left()) {
			Node* x = new Node(v);
			n->set_left(x);
			x->set_parent(n);
			balance_tree(n, 1, LEFT);
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
/*	if(!root) {
		std::cout << "The tree is empty" << std::endl;
		return;
	}
	print(root);
*/	
    std::stack<Node*> global_stack;
    global_stack.push(root);
    int n_blanks = 32;
    bool is_row_empty = false;
    std::cout << "......................................................" << std::endl;
    while (is_row_empty == false) 
    {
        std::stack<Node*> local_stack;
        is_row_empty = true;
        for (int j = 0; j < n_blanks; ++j) 
            std::cout << " ";
        
        while (global_stack.empty() == false) 
        {
            Node* temp = global_stack.top();
            global_stack.pop();
            if (temp != NULL) 
            {
                std::cout << temp->get_value();
                local_stack.push(temp->get_left());
                local_stack.push(temp->get_right());
                if (temp->get_left() != NULL || temp->get_right() != NULL) 
                    is_row_empty = false;
            }
            else 
            {
                std::cout << "--";
                local_stack.push(NULL);
                local_stack.push(NULL);
            }
            for (int j = 0; j < (n_blanks * 2 - 2); ++j) 
                std::cout << " ";
        }                
        std::cout << std::endl;
        std::cout << std::endl;
        n_blanks /= 2;
        while (local_stack.empty() == false) 
        {
            global_stack.push(local_stack.top());
            local_stack.pop();
        } 
   }
   std::cout << "......................................................" << std::endl;

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

int Tree::get_height(Node* r)
{
	if(NULL == r) {
		return 0;
	}
	if(!(r->get_right() || r->get_left())) {
		return 0;
	}
	return 1+ std::max(get_height(r->get_left()),get_height(r->get_right()));
}

void Tree::right_rotate(Node* r)
{
	std::cout << "right rotate" << std::endl;
	std::cout << "root is " << r->get_value() << std::endl;
	Node* pivot = r->get_left();
	assert(NULL != pivot);
	std::cout << "pivot is "<< pivot->get_value() << std::endl;
	Node* b = pivot->get_right();
	Node* anc = r->get_parent();
	if(anc) {
		if(r->get_value() < anc->get_value()) {
			if(anc) {
				anc->set_left(pivot);
				pivot->set_parent(anc);
			}
		} else {
			if(anc) {
				anc->set_right(pivot);
				pivot->set_parent(anc);
			}
		}
	}
	pivot->set_right(r);
	r->set_parent(pivot);
	r->set_left(b);
	if(b) {
		b->set_parent(r);
	}
	if(root == r) {
		root = pivot;
		pivot->set_parent(NULL);
	}

}

void Tree::left_rotate(Node* r)
{
	std::cout << "left rotate" << std::endl;
	std::cout << "root is " << r->get_value() << std::endl;
	Node* pivot = r->get_right();
	assert(NULL != pivot);
	std::cout << "pivot is "<< pivot->get_value() << std::endl;
	Node* b = pivot->get_left();
	Node* anc = r->get_parent();
	if(anc) {
		if(r->get_value() < anc->get_value()) {
			if(anc) {
				anc->set_left(pivot);
				pivot->set_parent(anc);
			}
		} else {
			if(anc) {
				anc->set_right(pivot);
				pivot->set_parent(anc);
			}
		}
	}
	pivot->set_left(r);
	r->set_parent(pivot);
	r->set_right(b);
	if(b) {
		b->set_parent(r);
	}
	if(root == r) {
		root = pivot;
		pivot->set_parent(NULL);
	}

}

void Tree::left_right_rotate(Node* root)
{
	std::cout << "left right rotate" << std::endl;

	left_rotate(root->get_left());
	right_rotate(root);
}

void Tree::right_left_rotate(Node* root)
{
	std::cout << "right left rotate" << std::endl;
	right_rotate(root->get_right());
	left_rotate(root);
}





Tree::Dir Tree::get_dir(Node* n)
{
	if( NULL == n) {
		throw("get_dir is called to a NULL node");
		exit(1);
	}
	Node* p = n->get_parent();
	if( p->get_left() == n) {
		return LEFT;
	}
	return RIGHT;
}

void Tree::balance_tree(Node* n, int h, Dir d_child) // int v)
{

	if(NULL == n) {
	    return;
	}
	Node* r = n->get_parent();
	if( NULL == r) {
		return;
	}
	Dir d = get_dir(n);
	
	if(RIGHT == d) {
		int left_height = get_height(r->get_left());
		if(h == 1 && NULL != r->get_left()){
			left_height = 1;
			balance_tree(r, h+1, d);
			return;
		}
		if(h - left_height > 0) {
			if(RIGHT == d_child) {
				left_rotate(r);
			} else {
				right_left_rotate(r);
			}
		}
		balance_tree(n->get_parent(), h+1, d);
		return;
	}else {

		int right_height = get_height(r->get_right());
		if(h == 1 && NULL != r->get_right()){
			right_height = 1;
			balance_tree(r, h+1, d);
			return;
		}
		if(h - right_height > 0) {
			if(LEFT == d_child) {
				right_rotate(r);
			} else {
				left_right_rotate(r);
			}
		}

		balance_tree(n->get_parent(), h+1, d);  
		return;
	}
	return;
}

