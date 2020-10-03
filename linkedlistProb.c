#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t *head) {
  node_t *current = head;
  int nodeNUM = 0;
  while (current != NULL) {
    printf("+--node_%d => %p\n",nodeNUM,current);
    printf("\t+--val => %d\n", current->val);
    printf("\t+--nxt => %p\n", current->next);
    current = current -> next;
    nodeNUM++;
  }

}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

/*
To remove by value
  - iterate over each node
  - check its value
    - if equal to given value, free the node and stitch the list using a temp node
*/

int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
    node_t *current = *head;
    node_t *temp = NULL;
    int retval = -1;
    if(current -> val == val){
      return pop(head);
    }

    while (current -> next -> val != val) {
      current = current -> next;
    }

    temp = current -> next;
    retval = temp -> val;
    current -> next = temp -> next;
    free(temp);

    return retval;

}

int main() {

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 2);

    print_list(test_list);
}
