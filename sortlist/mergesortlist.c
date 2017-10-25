#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s list_node_t;

struct list_node_s
{
    int           key;
    list_node_t  *next;
};

list_node_t *get_mid_node(list_node_t *head)
{
    list_node_t *slow, *fast, *iter;

    iter = head;
    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL) {
        iter = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    iter->next = NULL;

    return slow;
}

list_node_t *create_list_node(int key)
{
    list_node_t *node = malloc(sizeof(list_node_t));
    node->key = key;
    node->next = NULL;

    return node;
}

void destroy_list(list_node_t *head)
{
    list_node_t *iter;

    iter = head;
    while (iter) {
        head = iter->next;
        free(iter);
        iter = head;
    }
}

list_node_t *merge(list_node_t *head1, list_node_t *head2)
{
    list_node_t *node, *head;

    if (head1 && head2) {
        if (head1->key < head2->key) {
            head = head1;
            head1 = head1->next;

            node = head;
            node->next = head2;
        } else {
            head = head2;
            head2 = head2->next;

            node = head;
            node->next = head1;
        }
    } else if (head1) {
        return head1;
    } else {
        return head2;
    }

    while (head1 && head2) {
        if (head1->key < head2->key) {
            node->next = head1;
            head1 = head1->next;
        } else {
            node->next = head2;
            head2 = head2->next;
        }

        node = node->next;
    }

    if (head1) {
        node->next = head1;
	}

    if (head2) {
        node->next = head2;
    }

    return head;
}

list_node_t *merge_sort_list(list_node_t *start)
{
    list_node_t *head1, *head2, *mid;

    if (!start || !start->next)
        return start;

    mid = get_mid_node(start);
    head1 = merge_sort_list(start);
	head2 = merge_sort_list(mid);

    return merge(head1, head2);
}

int main()
{
	list_node_t *head, **iter;

	head = create_list_node(5);
	iter = &head->next;

	*iter = create_list_node(2);
	iter = &(*iter)->next;

	*iter = create_list_node(3);
	iter = &(*iter)->next;

	*iter = create_list_node(6);
	iter = &(*iter)->next;

	*iter = create_list_node(1);
	iter = &(*iter)->next;

	*iter = create_list_node(4);
	iter = &(*iter)->next;

    printf("origin list: ");
	iter = &head;
	while (*iter) {
		printf("%d ", (*iter)->key);
		iter = &(*iter)->next;
	}

	printf("\n");

	head = merge_sort_list(head);
	iter = &head;

    printf("sorted list: ");
	while (*iter) {
		printf("%d ", (*iter)->key);
		iter = &(*iter)->next;
	}

	printf("\n");

	destroy_list(head);

	return 0;
}
