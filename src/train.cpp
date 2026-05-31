// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  // Освобождаем память
  if (first == nullptr) return;
  Car* cur = first;
  do {
    Car* next = cur->next;
    delete cur;
    cur = next;
  } while (cur != first);
}

void Train::addCar(bool light) {
  Car* newCar = new Car;
  newCar->light = light;
  newCar->next = nullptr;
  newCar->prev = nullptr;
  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* back = first->prev;
    back->next = newCar;
    first->prev = newCar;
    newCar->next = first;
    newCar->prev = back;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  Car* cur = first;
  cur->light = true;
  while (true) {
    int steps = 0;
    do {
      cur = cur->next;
      countOp++;
      steps++;
    } while (!cur->light);
    cur->light = false;
    for (int i = 0; i < steps; i++) {
      cur = cur->prev;
      countOp++;
    }
    if (!cur->light) {
      return steps;
    }
  }
}

int Train::getOpCount() { return countOp; }
