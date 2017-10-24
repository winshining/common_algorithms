#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

struct bst_node
{
    int        key;
    bst_node  *left;
    bst_node  *right;
};

bool valid_bst(bst_node *node)
{
    static bst_node *visited = NULL;

    if (node) {
        if (!valid_bst(node->left)) {
            return false;
        }

        if (visited && visited->key >= node->key) {
            return false;
        }

        visited = node;

        return valid_bst(node->right);
    }

    return true;
}

bst_node *create_bst_node(int key)
{
    bst_node *node = new bst_node;

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void destroy_bst(bst_node *root)
{
    queue<bst_node *> q;
    bst_node *p;

    if (!root) {
        return;
    }

    p = root;
    q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->left) {
            q.push(p->left);
        }

        if (p->right) {
            q.push(p->right);
        }

        cout << p->key << ' ';
        delete p;
    }
}

void inorder_bst(bst_node *root)
{
    if (root) {
        inorder_bst(root->left);
        cout << root->key << ' ';
        inorder_bst(root->right);
    }
}

int main()
{
    bst_node *root;

    root = create_bst_node(5);

    root->left = create_bst_node(3);
    root->right = create_bst_node(7);

    root->left->left = create_bst_node(1);
    root->left->right = create_bst_node(4);

    root->right->left = create_bst_node(6);
    root->right->right = create_bst_node(9);

    if (valid_bst(root)) {
        cout << "OK" << endl;
    } else {
        cout << "X" << endl;
    }

    inorder_bst(root);
    cout << endl;

    destroy_bst(root);
    cout << endl;

    return 0;
}

