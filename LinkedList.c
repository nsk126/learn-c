#include <stdio.h>
#include <stdlib.h>

#define NL printf("\n")

// the linked list
typedef struct node {
  int val;
  struct node *next;
} node_t;

// to iterate over a linked list
void print_lst(node_t *head) {
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

//pushing an item to end of list
void push(node_t *head, int val) {

  //give head loc to current pointer
  node_t *current = head;

  //simple loop to check if next node is last i.e contains a NULL
  //if next addr is not a NULL, then we advance to the next node
  //i.e the current addr is set to the addr of the next node
  while (current -> next != NULL) {
    current = current -> next;
  }

  // now we know the next addr is a NULL i.e the current addr is the last node
  current -> next = (node_t *) malloc(sizeof(node_t));
  current -> next -> val = val;
  current -> next -> next = NULL;

}

//pushing item to top of list
void push_T(node_t **head, int val) {

    node_t *nNode;
    nNode = (node_t *) malloc(sizeof(node_t));

    nNode -> val = val;
    nNode -> next = *head;
    *head = nNode;

}

//poping an item from top of LIST
int pop_T(node_t **head) {
  int retval = -1;
  node_t *next_node = NULL;

  if(*head == NULL){
    return retval;
  }

  next_node = (*head) -> next;
  retval = (*head) -> val;

  free(*head);

  *head = next_node;

  return retval;
}

//poping item from end of list
int pop(node_t *head){
  int retval = 0;

  if(head -> next == NULL){
    retval = head -> val;
    free(head);
    return retval;
  }

  node_t *current = head;
  while (current -> next -> next != NULL) {
    current = current -> next;
  }

  retval = current -> next -> val;
  free(current -> next);
  current -> next = NULL;
  return retval;
}

int remove_by_index(node_t ** head, int n) {
  int i = 0;
  int retval = -1;
  node_t * current = *head;
  node_t * temp_node = NULL;

  if (n == 0) {
      return pop_T(head);
  }

  for (i = 0; i < n-1; i++) {
      if (current->next == NULL) {
          return -1;
      }
      current = current->next;
  }

  temp_node = current->next;
  retval = temp_node->val;
  current->next = temp_node->next;
  free(temp_node);

  return retval;

}


int main(int argc, char const *argv[]) {


  node_t *head = NULL;
  printf("head ADDR => %p\n",head);

  head = (node_t *) malloc(sizeof(node_t));
  if (head == NULL) {
    return 1;
  }
  NL;
  printf("===After Malloc===\n");
  NL;
  printf("head ADDR => %p\n",head);
  NL;
  printf("===Before Struct INIT===\n");
  NL;
  printf("%d\n", head -> val);
  printf("%p\n", head -> next);

  head -> val = 1;
  head -> next = NULL;

  NL;
  printf("===After Struct INIT===\n");
  NL;
  printf("%d\n", head -> val);
  printf("%p\n", head -> next);

  head -> next = (node_t *) malloc(sizeof(node_t));

  head -> next -> val = 2;
  head -> next -> next = NULL;

  NL;
  printf("===After new node in Linked List===\n");
  NL;

  printf("+--head => %p\n",head);
  printf("\t+--val => %d\n",head -> val);
  printf("\t+--nxt => %p\n",head -> next);

  printf("+--node_1 => %p\n",head -> next);
  printf("\t+--val => %d\n",head -> next -> val);
  printf("\t+--nxt => %p\n",head -> next -> next);

  // using the function instead
  NL;
  printf("===USING PRIN FUNC INSTEAD===\n");
  NL;
  print_lst(head);

  // use func to add item to end of List
  NL;
  printf("===ADDING A NEW ITEM TO THE END OF LIST===\n");
  NL;

  push(head,3);
  print_lst(head);
  NL;
  printf("===ADDING A NEW ITEM TO THE TOP OF LIST===\n");
  NL;

  push_T(&head,0);
  print_lst(head);

  NL;
  printf("===REMOVING AN ITEM FROM THE TOP OF LIST===\n");
  NL;
  int pop_v = pop_T(&head);
  print_lst(head);
  printf("Removed value = %d\n",pop_v);

  NL;
  printf("===REMOVING AN ITEM FROM THE END OF LIST===\n");
  NL;

  int pop_b = pop(head);
  print_lst(head);
  printf("Removed value = %d\n",pop_b);

  NL;
  printf("===REMOVING INDEX 1 ===\n");
  NL;

  remove_by_index(&head,1);
  print_lst(head);



  return 0;
}
