#include "binary_tree.h"

binary_tree::binary_tree()
{
	size = 0;

	cout << "build tree: " << endl;
	cout << "root: " << endl;
	root = build_tree();
}

binary_tree::~binary_tree()
{
	destroy_tree();
}

binary_tree_node* binary_tree::build_tree(void)
{
	ssize_t data;

	binary_tree_node* p = NULL;
	cin >> data;

	size++;

	if (data == 0) {
		return p;
	} else {
		p = new binary_tree_node(data);
		if (!p) {
			cerr << "Alloc memory failed." << endl;
			destroy_tree();
			exit(0);
		} else {
			cout << "the left child of: " << data << endl;
			p->left = build_tree();
			cout << "the right child of: " << data << endl;
			p->right = build_tree();
		}
	}

	return p;
}

void binary_tree::destroy_tree(void)
{
	queue<binary_tree_node*> q;
	binary_tree_node* p = NULL;

	q.push(root);
	while (!q.empty()) {
		p = q.front();
		q.pop();

		if (p->left) {
			q.push(p->left);
		}

		if (p->right) {
			q.push(p->right);
		}

		delete p;
	}
}

void binary_tree::do_preorder_traverse(binary_tree_node* p)
{
	if (p) {
		cout << setw(4) << p->data << ' ';
		do_preorder_traverse(p->left);
		do_preorder_traverse(p->right);
	}
}

void binary_tree::preorder_traverse(void)
{
	binary_tree_node* p = root;

	cout << "preorder traverse:" << endl;
	do_preorder_traverse(p);

	cout << endl;
}

void binary_tree::do_inorder_traverse(binary_tree_node* p)
{
	if (p) {
		do_inorder_traverse(p->left);
		cout << setw(4) << p->data << ' ';
		do_inorder_traverse(p->right);
	}
}

void binary_tree::inorder_traverse(void)
{
	binary_tree_node* p = root;

	cout << "inorder traverse:" << endl;
	do_inorder_traverse(p);

	cout << endl;
}

void binary_tree::do_postorder_traverse(binary_tree_node* p)
{
	if (p) {
		do_postorder_traverse(p->left);
		do_postorder_traverse(p->right);
		cout << setw(4) << p->data << ' ';
	}
}

void binary_tree::postorder_traverse(void)
{
	binary_tree_node* p = root;

	cout << "postorder traverse:" << endl;
	do_postorder_traverse(p);

	cout << endl;
}

void binary_tree::preorder_traverse_no_recursion(void)
{
	cout << "preorder traverse with no recursion:" << endl;

	if (!empty()) {
		stack<binary_tree_node*> s;
		binary_tree_node* p = root;

		s.push(p);

		while(!s.empty()) {
			cout << setw(4) << p->data << ' ';
			if (p->right) {
				s.push(p->right);
			}

			if (p->left) {
				p = p->left;
			} else {
				p = s.top();
				s.pop();
			}
		}

		cout << endl;
	}
}

void binary_tree::inorder_traverse_no_recursion(void)
{
	cout << "inorder traverse with no recursion:" << endl;

	if (!empty()) {
		stack<binary_tree_node*> s;
		binary_tree_node* p = root;

		while(!s.empty() || p) {
			if (p) {
				s.push(p);
				p = p->left;
			} else {
				p = s.top();
				s.pop();

				cout << setw(4) << p->data << ' ';
				p = p->right;
			}
		}

		cout << endl;
	}
}

void binary_tree::postorder_traverse_no_recursion(void)
{
	cout << "postorder traverse with no recursion:" << endl;

	if (!empty()) {
		stack<binary_tree_node*> s;
		binary_tree_node* p = root;
		binary_tree_node* last_visited = NULL;

		/* find the lowest node in sub-left tree */
		while (p) {
			s.push(p);
			p = p->left;
		}

		while (!s.empty()) {
			last_visited = p;

			p = s.top();
			s.pop();

			/* left -> right -> node */
			if (p->right == NULL || p->right == last_visited) {
				cout << setw(4) << p->data << ' ';
			} else {
				/* so if it is left sub tree, push to stack */
				s.push(p);
				p = p->right;

				while (p) {
					s.push(p);
					p = p->left;
				}
			}
		}

		cout << endl;
	}
}

