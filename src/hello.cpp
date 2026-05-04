#include <string>
#include <iostream>
#include "hello.hpp"

#include <stack>
using namespace std;

DishStack::DishStack() {
    top = -1;
}
void DishStack::push(Dish& dish) {
    if (top == MAX_SIZE-1) {
        cout<<"Stack is full"<<endl;
        return;
    }
    top++;
    dishes[top] = &dish;
}
Dish DishStack::pop() {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
        return Dish("Empty dish");
    }
    Dish temporary = *dishes[top];
    top--;
    return temporary;
}
Dish DishStack::peek() {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
        return Dish("Empty dish");
    }
    return *dishes[top];
}

int DishStack::size() {
    return top+1;
}