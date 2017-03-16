#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <cstdlib>

using namespace std;

class binary_tree_node
{
public:
	ssize_t data;
	binary_tree_node* left;
	binary_tree_node* right;
	binary_tree_node(int data, binary_tree_node* left = NULL, binary_tree_node* right = NULL)
	: data(data), left(left), right(right) {}
};

class binary_tree
{
public:
	binary_tree();
	~binary_tree();

	binary_tree_node* build_tree(void);

	bool empty(void) { return root == NULL; }
	ssize_t get_size(void) { return size; }

	void preorder_traverse(void);
	void inorder_traverse(void);
	void postorder_traverse(void);

	void preorder_traverse_no_recursion(void);
	void inorder_traverse_no_recursion(void);
	void postorder_traverse_no_recursion(void);

protected:
	void destroy_tree(void);
	void do_preorder_traverse(binary_tree_node *p);
	void do_inorder_traverse(binary_tree_node *p);
	void do_postorder_traverse(binary_tree_node *p);

private:
	binary_tree_node* root;
	ssize_t size;
};

