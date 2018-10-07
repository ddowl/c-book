/*
  Add commands to print the top element of the stack without popping,
  to duplicate it, and to swap the top two elements. Add a command to
  clear the stack.
*/

#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

// STACK OPS

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, con't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop() {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek() {
  double top = pop();
  sp++;
  return top;
}

void dupTop() {
  push(peek());
}

void swapTop() {
  double top = pop();
  double next = pop();
  push(top);
  push(next);
}

void clearStack() {
  sp = 0;
}

// Test Helpers

void printStackAndSP() {
  printf("stack:");
  for (int i = 0; i < sp; i++) {
    printf(" %.1f", val[i]);
  }
  printf(", sp: %d\n", sp);
}

void pushSomeNums() {
  push(0.0);
  push(1.0);
  push(2.0);
}

void resetStack() {
  clearStack();
  pushSomeNums();
}

int main(void) {
  pushSomeNums();
  printStackAndSP();

  clearStack();
  printStackAndSP();

  resetStack();
  printf("peek: %f\n", peek());

  resetStack();
  dupTop();
  printStackAndSP();

  resetStack();
  swapTop();
  printStackAndSP();

  return 0;
}