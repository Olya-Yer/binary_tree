#ifndef NODE_HPP
#define NODE_HPP
class Node
{
	public:
		Node(int);
	private:
		int value;
		Node* left;
		Node* right;
		Node* parent;
	public:
		/**
		 * @brief sets the left subtree of the node
		 * @param Node* subtree, the parameter also can be NULL
		 * @return void;
		 */
		void set_left(Node*);
		/**
		 * @brief returns the left subtree of the node
		 * @return Node* left subtree of the node, the subtree
		 * can also be NULL;
		 */
		Node* get_left();
		/**
		 * @brief sets the right subtree of the node
		 * @param Node* subtree, the parameter also can be NULL
		 * @return void;
		 */
		void set_right(Node*);
		/**
		 * @brief returns the right subtree of the node
		 * @return Node* right subtree of the node, the subtree
		 * can also be NULL;
		 */
		Node *get_right();
		/**
		 * @brief sets the parent of the node
		 * @param Node* parent
		 * @return void;
		 */
		Node *get_parent();
		/**
		 * @brief returns the parent of the node
		 * @return Node* parent node of the given node, the parent
		 * can also be NULL;
		 */
		void set_parent(Node*);
		/**
		 * @brief returns the value of the node,
		 * @return int the value of the node,
		 */
		int get_value();
		/**
		 *@brief sets the value of the node;
		 *@param int the value to be assigned to the node
		 *@return void
		 */
		void set_value(int);
};
#endif
