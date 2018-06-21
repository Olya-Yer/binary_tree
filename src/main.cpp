#include <tree.hpp>
#include <iostream>


int main()
{
	Tree* t = new Tree();
	std::cout << "Adding elements to the tree" << std::endl;
	t->insert(20); 
	t->insert(22); 
	t->insert(14); 
	t->insert(9); 
	t->insert(16);
	t->insert(15);
	t->insert(76); 
	t->insert(54); 
	t->print2D(t->get_root(),1);
	std::cout << "right right rotate from root" << std::endl;
	t->right_right_rotate(t->get_root());
	t->print2D(t->get_root(),1);
	return 0;
	std::cout << "deleting node 20" << std::endl;
	t->delete_node(20);
	t->print();
	return 0;
	std::cout << t->contains(54) << std::endl;
	std::cout << t->contains(9) << std::endl;
	std::cout << t->contains(742) << std::endl;
	return 0;
}

