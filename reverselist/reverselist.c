#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s list_node_t;

struct list_node_s {
    int           key;
    list_node_t  *next;
};

list_node_t *reverse_list(list_node_t *head)
{
    list_node_t  *iter, *p1, *p2; 

    if (!head) {
        return head;
    }

    iter = NULL;
    p1 = head;
    p2 = head->next;

    while (p2) {
        iter = p2->next;

        p2->next = p1;
        p1 = p2;
        p2 = iter;
    }

    head->next = NULL;

    return p1;
}

list_node_t *create_list_node(int key)
{
    list_node_t *p = malloc(sizeof(list_node_t));
    p->key = key;
    p->next = NULL;

    return p;
}

void destroy_list_node(list_node_t *head)
{
    list_node_t *iter;

    if (!head) {
        return;
    }

    iter = head;

    while (iter) {
        head = iter->next;
        free(iter);
        iter = head;
    }
}

int main()
{
    list_node_t *head, **iter;

    head = create_list_node(1);
    iter = &head->next;

    *iter = create_list_node(2);
    iter = &(*iter)->next;

    *iter = create_list_node(3);
    iter = &(*iter)->next;

    *iter = create_list_node(4);
    iter = &(*iter)->next;

    *iter = create_list_node(5);
    iter = &(*iter)->next;

    iter = &head;
    printf("origin list: ");
    while (*iter) {
        printf("%d ", (*iter)->key);
        iter = &(*iter)->next;
    }

    printf("\n");

    head = reverse_list(head);
    iter = &head;
    printf("reversed list: ");
    while (*iter) {
        printf("%d ", (*iter)->key);
        iter = &(*iter)->next;
    }

    printf("\n");

    destroy_list_node(head);

    return 0;
}

