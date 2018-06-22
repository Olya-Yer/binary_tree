#ifndef TREE_HPP
#define TREE_HPP
#include <node.hpp>
class Tree 
{
	protected:
		/**
		 * a pointer to the root
		 */
		Node* root;

		/**
		 *@brief inserts a node to the given tree, corrects the balance
		 if needed
		 *@param Node* the tree
		 *@param int value
		 *@return void
		 */
		void insert_node(Node*, int);
		/**
		 * @brief deletes the tree with the given root
		 * @param Node* the root
		 * @return void
		 */
		void delete_tree(Node*);
		/**
		 * @brief prints the tree with the given root
		 * @param Node* the root
		 * @return void
		 */
		void print(Node*) const;
		/**
		 * @brief copies the given tree to the given root
		 * @param Node* the root
		 * @param Node* the tree
		 * @return void
		 */
		void copy_tree(Node*, Node*);
		/**
		 * @brief checks if the value exists in the given tree
		 * @param int the value
		 * @return bool true, if the value exists, false otherwise
		 */
		bool contains(Node*, int) const;
		/**
		 *@brief finds the node with the give value
			    in the given tree
		 *@param Node* the root of the tree
		 *@param int the value of the node
		 *@return Node* a pointer to the node if exists,
		 *	    NULL otherwise 
		 */
		Node* find_node(Node*, int);
		bool delete_node(Node*, int);
	public:
		/**
		 * @brief the default constructor
		 */
		Tree();
		/**
		 * @brief the copy constructor
		 * @param const Tree&
		 */
		Tree(const Tree &);
		
		/**
		 * @brief inserts a node to the tree and corrects the balance if
		 * needed
		 * @details if new added node ruins the balance of the tree
		 *	   the function corrects it. 
		 * @param int the value
		 * @return void
		 */
		void insert(int);	
		/**
		 * @brief checks if the value exists in the tree
		 * @param int the value
		 * @return bool true, if the value exists, false otherwise
		 */
		bool contains(int) const; 
		/**
		 * @brief deletes the node with the given value, corrects the
		 * balance of the tree if needed
		 * @param int the value
		 * @return bool true, if the value exists, false otherwise
		 */
		bool delete_node(int);
		Node* right_most(Node*);
		int get_height(Node* r);
		Node* get_root() { return root;};
		void left_rotate(Node* r);
		void right_rotate(Node* root);
		void left_right_rotate(Node* root);
		void right_left_rotate(Node* root);
		void print2D(Node *r, int space);
		enum Dir{RIGHT,	LEFT};
		/**
		 * @brief checks if the given tree is balanced and balances it
		 * if needed
		 * @param Node* root of the tree
		 * @return true if the tree is balanced, false otherwise
		 */
		void balance_tree(Node*, int, Dir);
		Tree::Dir get_dir(Node*);
		/**
		 * @brief corrects the balance of the tree by swaping nodes
		 * @param Node* the root of the tree that needs to be balanced
		 * @return void
		 */
		void rebalance(Node*);

		/**
		 * @brief class destructor
		 * @iterates over all existing nodes and deletes them
		 */
		~Tree();
		/**
		 * @brief prints the tree
		 * @return void
		 */
		void print() const;
		
};
#endif
