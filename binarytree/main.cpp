#include "binary_tree.h"

int main()
{
	binary_tree tree;
	tree.preorder_traverse();
	tree.inorder_traverse();
	tree.postorder_traverse();

	tree.preorder_traverse_no_recursion();
	tree.inorder_traverse_no_recursion();
	tree.postorder_traverse_no_recursion();

	return 0;
}

