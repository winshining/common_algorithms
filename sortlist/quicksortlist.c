#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s list_node_t;

struct list_node_s
{
    int           key;
    list_node_t  *next;
};

void swap(list_node_t *p, list_node_t *q)
{
    int key = p->key;
    p->key = q->key;
    q->key = key;
}

list_node_t *partition(list_node_t *start, list_node_t *end)
{
    int           key;
    list_node_t  *p, *q;

    if (start == end || start->next == end)
        return start;

    key = start->key;
    p = start;
    q = p;

    while (q != end) {
        if (q->key < key) {
            p = p->next;
            swap(p, q);
        }
        
        q = q->next;
    }

    swap(p, start);

    return p;
}

void quick_sort(list_node_t *start, list_node_t *end)
{
    list_node_t *mid;

    if (start == end || start->next == end)
        return;

    mid = partition(start, end);
    quick_sort(start, mid);
    quick_sort(mid->next, end);
}

list_node_t *sort_list(list_node_t *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    quick_sort(head, NULL);
    return head;
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
    list_node_t *iter = head;

    while (iter) {
        head = iter->next;
        free(iter);
        iter = head;
    }
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

    head = sort_list(head);
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
