#include <stdio.h>
#include <stdlib.h>

struct Node {
  int por, cff;
  struct Node *next;
};

struct Node *hed1 = NULL;
struct Node *tl1 = NULL;

struct Node *hed2 = NULL;
struct Node *tl2 = NULL;

struct Node *hed3 = NULL;
struct Node *tl3 = NULL;

void add_node(int por, int cff, struct Node **H, struct Node **T) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->por = por;
  node->cff = cff;
  node->next = NULL;
  if (*H == NULL) {
    *H = node;
    *T = node;
  } 
  else {
    (*T)->next = node;
    *T = node;
  }
}

void sum() {
  struct Node *temp1 = hed1;
  struct Node *temp2 = hed2;
  while (temp1 && temp2) {
    if (temp1->por == temp2->por) {
      add_node(temp1->por, temp1->cff + temp2->cff, &hed3, &tl3);
      temp1 = temp1->next;
      temp2 = temp2->next;
    } 
    else if (temp1->por < temp2->por) {
      add_node(temp2->por, temp2->cff, &hed3, &tl3);
      temp2 = temp2->next;
    } 
    else {
      add_node(temp1->por, temp1->cff, &hed3, &tl3);
      temp1 = temp1->next;
    }
  }
  while (temp1) {
    add_node(temp1->por, temp1->cff, &hed3, &tl3);
    temp1 = temp1->next;
  }
  while (temp2) {
    add_node(temp2->por, temp2->cff, &hed3, &tl3);
    temp2 = temp2->next;
  }
}

void show(struct Node **H) {
  struct Node *temp = *H;
  while (temp->next) {
    printf("%d %d\n", temp->por, temp->cff);
    temp = temp->next;
  }
  printf("%d %d \n", temp->por, temp->cff);
}

int main() {
  int n1;
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    int coff, poer;
    scanf("%d %d", &coff, &poer);
    add_node(poer, coff, &hed1, &tl1);
  }

  int m1;
  scanf("%d", &m1);
  for (int i = 0; i < m1; i++) {
    int coeficient, power;
    scanf("%d %d", &coeficient, &power);
    add_node(power, coeficient, &hed2, &tl2);
  }

  sum();

  struct Node *temp = hed3;
  while (temp) {
    if (temp->por != 0) {
      if (temp->por == 1) {
        printf("%dX+", temp->cff);
      } 
      else {
        printf("%dX^%d+", temp->cff, temp->por);
      }
    } 
    else {
      printf("%d\n", temp->cff);
    }
    temp = temp->next;
  }
  printf("\n");
}