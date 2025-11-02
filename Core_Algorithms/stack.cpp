// core implementation of stack
#include <iostream>
using namespace std;
const int MAX = 1e6; // allocating a fixed size

struct Stack {
  int arr[MAX];
  int top;

  Stack() { this->top = -1; }

  bool isFull() const { return this->top >= MAX - 1; }

  bool isEmpty() const { return this->top == -1; }

  void push(int x) {
    if (!this->isFull()) {
      this->arr[++(this->top)] = x;
    } else {
      cout << "overflow\n";
    }
  }

  void pop() {
    if (!this->isEmpty()) {
      --(this->top);
    } else {
      cout << "underflow\n";
    }
  }

  int Top() const {
    if (!this->isEmpty()) {
      return this->arr[this->top];
    } else {
      cout << "* empty stack ";
      return -1;
    }
  }

  void print() const {
    if (this->isEmpty()) {
      cout << "empty Stack\n";
      return;
    }
    for (int i = this->top; i >= 0; --i) {
      cout << this->arr[i] << "\n";
    }
  }
};

int main() {
  Stack s;
  cout << (s.isEmpty() ? "Stack is empty\n" : "Not empty\n");
  cout << "Top: " << s.Top() << "\n";
  s.push(4);
  s.push(5);
  s.push(6);
  s.push(7);
  cout << "Top: " << s.Top() << "\n";
  s.pop();
  cout << "After pop, stack:\n";
  s.print();
}
