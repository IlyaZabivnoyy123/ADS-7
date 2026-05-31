// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
}

void Train::addCar(bool light) {
  Car* anotherCar = new Car;
  anotherCar->light = light;
  anotherCar->next = nullptr;
  anotherCar->prev = nullptr;
  if (first == nullptr) {
    first = anotherCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* lastCar = first->prev;
    lastCar->next = anotherCar;
    first->prev = anotherCar;
    anotherCar->next = first;
    anotherCar->prev = lastCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  Car* now = first;
  now->light = true;
  while (true) {
    int steps = 0;
    do {
      now = now->next;
      countOp++;
      steps++;
      } while (!now->light);
    now->light = false;
    for (int i = 0; i < steps; i++) {
      now = now->prev;
      countOp++;
      }
    if (!now->light) {
      return steps;
      }
    }
}

int Train::getOpCount() { return countOp; }
