#include <iostream>

using namespace std;

// Structure Definitions
struct node {
  int data;
  node *next;
};

struct linked {
  struct node *head;
  struct node *tail;
};

// Utility Functions
void traverse(linked* list) {
  int count;
  count = 1;

  node *curr;
  curr = new node();
  curr = list->head;

  while (curr != NULL) {
    std::cout << "Node " << count << " Data: " << curr->data << endl; 
    curr = curr->next;
    count++;
  }
};

void lastNode(linked* list) {
  node *curr;
  curr = new node();
  curr = list->head;

  while (curr->next != NULL) {
    curr = curr->next;
  }

  std::cout << "Last Node: "  << curr->data << endl;
};

void insertBeginning(linked* list, node* n) {
  n->next = list->head;
  list->head = n;
};

void insertNodeAfter(node* afterNode, node* insertNode) {
  insertNode->next = afterNode->next;
  afterNode->next = insertNode;
};

void insertLast(linked* list, node* node) {
  struct node *curr;
  curr = new struct node();
  curr = list->head;

  while(curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = node;
};

void deleteNode(linked* list, node* deleteNode) {
  struct node *temp;
  temp = list->head;

  if (temp == deleteNode) {
    list->head = list->head->next;
    delete deleteNode;
  }

  else {
    while (temp != NULL) {
      if (temp->next == deleteNode) {
        temp->next = deleteNode->next;
        delete deleteNode;
      }
      temp = temp->next;
    };
  };
};

int main() {
  // initial set
  node *a, *b, *c, *d, *e, *f, *g;
  a = new node();
  b = new node();
  c = new node();
  d = new node();
  e = new node();
  f = new node();
  g = new node();

  a->data = 10;
  b->data = 20;
  c->data = 30;
  d->data = 40;
  e->data = 50;
  f->data = 60;
  g->data = 70;


  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  g->next = NULL;

  // Linked List Definition
  linked *l;
  l = new linked();
  l->head = a;
  l->tail = g;

  // Begin Insertion Test
  node *a1;
  a1 = new node();
  a1->data = 0;
  a1->next = NULL;

  insertBeginning(l, a1);

  // Middle Insertion Test
  node *mid;
  mid = new node();
  mid->data = 1000;

  insertNodeAfter(b, mid);

  // Last Insertion Test
  node *h;
  h = new node();
  h->data = 80;
  h->next = NULL;

  insertLast(l, h);

  // Delete Node Test
  deleteNode(l, mid);

  // Traversal Test
  traverse(l);
  
  return 0;
}