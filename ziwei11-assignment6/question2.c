#define _POSIX_C_SOURCE 200809L // <-- needed for strndup
#define ASSIGNMENT_VERSION 1.1
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *value;
  struct node *next;
  struct node *prev;
};
typedef struct node Node;

struct squeue {
   struct node* first;
   struct node* last;
};
typedef struct squeue * Squeue;
typedef const struct squeue * ConstSqueue;

enum direction {
    FORWARD,
    BACKWARD
};
typedef enum direction Direction;


/* initSqueue: initialize the given squeue to an empty squeue by allocating memory
 * using malloc. The squeue may not hold any data at this point. The function basically
 * prepares the squeue for the next operations i.e., adding and printing elements etc.
 * @returns the new malloc'd Squeue
 */
Squeue initSqueue() {
    Squeue squeue = malloc(sizeof(*squeue));
    squeue->first = NULL;
    squeue->last = NULL;
    return squeue;
}


/* freeSqueue: frees the squeue, its nodes, and the strings contained by the nodes.
 *
 * @param squeue -- the squeue to free. All nodes and all of their values will be free'd as well.
 */
void freeSqueue(Squeue squeue) {
    while(squeue->first != NULL){
        Node * node_for_free = squeue->first;
        squeue->first = squeue->first->next;
        free(node_for_free->value);
        free(node_for_free);
    }
    free(squeue);
}


/* isEmptyQueue: is an squeue empty
 *
 * @param squeue - an squeue to check for emptiness
 */
bool isEmptySqueue( const struct squeue * squeue) {
    return squeue->first == NULL;
}


/* addFrontSqueue: adds a node with a value to the front of squeue. The
 * pointer to the squeue where value will be added and the value
 * itself are provided by the caller function. The function adds the
 * node with the copied value to the front of given squeue and adjusts
 * all the pointers accordingly. If the given value is the first value
 * to be added then *first* and *last* pointer in squeue shall point
 * to this newly added value after the function completes its
 * execution. If this value is not the first value update the pointers
 * appropriately so that the every element in the squeue is linked.
 * This means you will have to update the *next* pointer of this newly
 * added node and the *prev* pointer of the node that was at the front
 * of squeue before this. You will also update *first* pointer so that
 * it points to this new node now.
 *
 *
 * value will be copied and malloc'd (you can strndup)
 *
 * @param squeue, a pointer to the struct Squeue
 * @param val, a pointer to a char
 * @returns void
 */
void addFrontSqueue(Squeue squeue, char * value) {
    Node * new_node = malloc(sizeof(*new_node));
    new_node->value = strdup(value);
    new_node->next = NULL;
    new_node->prev = NULL;
    if(squeue->first == NULL){
        squeue->first = new_node;
        squeue->last = new_node;
        return;
    }
    if(squeue->first != NULL){
        new_node->next = squeue->first;
        squeue->first->prev = new_node;
        squeue->first = new_node;
        return;
    }
}


/* addBackSqueue: adds a value to the back(or end) of squeue. The pointer to the squeue in
 * which the value will be added and the value itself are provided by the caller
 * function. The function adds the value to the end of the given squeue and adjusts
 * all the pointers accordingly. If the given value is the first value to be added
 * to the squeue then *first* and *last* pointer in squeue shall point to this newly
 * added value  after the function completes its execution. If this value is not the
 * first value then update the pointers appropriately so that the every element in the
 * squeue is linked. This means you will have to update the *prev* pointer of this newly
 * added node and the *next* pointer of the node that was at the end of the squeue before
 * this. You will also update *last* pointer so that it points to this new node now.
 *
 * value will be copied and malloc'd (you can strndup)
 *
 * @param squeue, a pointer to the struct Squeue
 * @param val, a pointer to a char
 * @return void
 */
void addBackSqueue(Squeue squeue, char* value) {
    Node * new_node = malloc(sizeof(*new_node));
    new_node->value = strdup(value);
    new_node->next = NULL;
    new_node->prev = NULL;
    if(squeue->first == NULL){
        squeue->first = new_node;
        squeue->last = new_node;
        return;
    }
    if(squeue->first != NULL){
        new_node->prev = squeue->last;
        squeue->last->next = new_node;
        squeue->last = new_node;
        return;
    }
}


/* printSqueue: prints the squeue in either forward or backward direction as indicated by
 * the argument passed to the function. If the direction passed is FORWARD print the values
 * of each node traversing squeue from the *first* node to the *last* node. If the direction
 * passed is BACKWARD then start traversal and printing from the *last* element of squeue until
 * you reach *first* node.
 *
 * @param squeue, a pointer to the struct squeue
 * @param direction, an enum representing either the FORWARD or the BACKWARD direction
 * @return void
 */
void printSqueue( const struct squeue * squeue, Direction dir) {
  if(dir == FORWARD){
      if(isEmptySqueue(squeue) == true){
          printf("Squeue Empty!\n");
          return;
      }
      printf("Printing Forward\n");
      Node * node_for_print = squeue->first;
      printf("%s\n", node_for_print->value);
      while(node_for_print->next != NULL){
          node_for_print = node_for_print->next;
          printf("%s\n", node_for_print->value);
      }
      return;
  }
  if(dir == BACKWARD){
      if(isEmptySqueue(squeue) == true){
          printf("Squeue Empty!\n");
          return;
      }
      printf("Printing Backward\n");
      Node * node_for_print = squeue->last;
      printf("%s\n", node_for_print->value);
      while(node_for_print->prev != NULL){
          node_for_print = node_for_print->prev;
          printf("%s\n", node_for_print->value);
      }
      return;
  }
}


/* reverseSqueue: reverses the nodes in the squeue such that the *last* pointer now points
 * to the *first* node and *first* points to the *last* node. For example, if the squeue
 * was a->b->c->d , where *first* points to 'a' and *last* points to 'd' , calling reverse
 * would change the squeue contents to d->c->b->a , and make the first point to 'd' and
 * last point to 'a' . The *next* and *prev* of all nodes will also be changed accordingly.
 *
 * @param squeue, a pointer to the struct squeue
 * @return void
 */
void reverseSqueue(Squeue squeue) {
    Node * current = squeue->first;
    squeue->last = squeue->first;
    Node * temporary = NULL;
    while(current != NULL){
        temporary = current->prev;
        current->prev = current->next;
        current->next = temporary;
        current = current->prev;
    }
    if(temporary != NULL){
        temporary = temporary->prev;
        squeue->first = temporary;
    }
    if(temporary == NULL){
        squeue->first = squeue->last;
    }
}


#define BUFFSIZE 1024

/* checkInput: given the result of scanf check if it
 * 0 elements read or EOF. If so exit(1) with a warning.
 *
 */
void checkInput(int err) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}

/* testAddFront: ask the user for input to add to the front of squeue
 */
void testAddFront(Squeue sq1) {
  char value[BUFFSIZE] = { 0 };
  printf("Enter value\n");
  checkInput(scanf(" %1023[^\n]%*c", value));
  addFrontSqueue(sq1, value);
}

/* testAddBack: ask the user for input to add to the back of squeue
 */
void testAddBack(Squeue sq1) {
  char value[BUFFSIZE] = { 0 };
  printf("Enter value\n");
  checkInput(scanf(" %1023[^\n]%*c", value));
  addBackSqueue(sq1, value);
}

/* testAddFront: print the queue forward or back
 */
void testPrint( const struct squeue * sq1, Direction dir ) {
  if(dir ==FORWARD) {
    printSqueue(sq1, FORWARD);
  } else if (dir == BACKWARD) {
    printSqueue(sq1, BACKWARD);
  }
}
/* testReverse: exercise reverse sqeue
 */
void testReverse( Squeue sq1 ) {
  if (isEmptySqueue(sq1)) {
    puts("Squeue Empty!");
  } else {
    reverseSqueue(sq1);
    puts("Squeue Reversed!");
  }
}



enum menuOptions {
  QUIT,
  ADDFRONT,
  ADDBACK,
  PRINTFORWARD,
  PRINTBACKWARD,
  REVERSEQ,
  NMENUOPTIONS
};

void evalMenuOption(enum menuOptions option, Squeue sq1) {
  switch (option) {
  case ADDFRONT:
    testAddFront(sq1);
    break;
  case ADDBACK:
    testAddBack(sq1);
    break;
  case PRINTFORWARD:
    testPrint(sq1,FORWARD);
    break;
  case PRINTBACKWARD:
    testPrint(sq1,BACKWARD);
    break;
  case REVERSEQ:
    testReverse(sq1);
    break;
  default:
    break;
  }
}

#define HEAVY 10000
// Heavily excercise your data structure to tease out problems with
// memory management.
void heavilyExerciseSqueue() {
  Squeue sq1 = initSqueue();
  Squeue sq2 = initSqueue();
  char buffer[BUFFSIZE];
  for (int i = 0; i < HEAVY; i++) {
    // generate  a new string every run
    sprintf(buffer, "STR: %18d\t\t%p\n", i, (void*)&buffer[i%BUFFSIZE]);
    addFrontSqueue( sq1, buffer );
    assert(sq1->first->value != buffer);
    assert(strcmp(sq1->first->value,buffer) == 0);
    char * sq1last = sq1->last->value;
    addBackSqueue( sq2, buffer );
    reverseSqueue( sq1 );
    assert(sq1->first->value == sq1last); // last is now first!
    reverseSqueue( sq2 );
  }
  freeSqueue(sq2);
  freeSqueue(sq1);
}

int main() {
  Squeue sq1 = initSqueue();
  int option=-1;
  printf("Enter the number to call a function\n1-addFront\n2-addBack\n");
  printf("3-printSqueue forward\n");
  printf("4-printSqueue backward\n5-reverseSqueue\n0-quit\n");
  do {
    printf("Enter option\n");
    checkInput(scanf("%d",&option));
    if(option >= 0 && option < NMENUOPTIONS) {
      evalMenuOption( option, sq1 );
    } else {
      printf("Invalid option!");
      exit(1);
    }
  } while ( option > 0 );
  freeSqueue(sq1);
  // Run some tests
  heavilyExerciseSqueue();
  return 0;
}
