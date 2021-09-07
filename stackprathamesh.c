#include <stdio.h>

int MAXSIZE = 10;       
int stack[10];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Stack is empty. \n");
      return -1;
   }
}

int push(int x) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = x;
      return x;
   } else {
      printf("Stack is full.\n");
      return -1;
   }
}

int main() {
   push(4);
   push(7);
   push(9);
   push(11);
   push(12);
   push(14);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
    }
}