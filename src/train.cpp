// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

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
    Car* backCar = first->prev;
    backCar->next = newCar;
    first->prev = newCar;
    newCar->next = first;
    newCar->prev = backCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  Car* current = first;
  current->light = true;
  while (true) {
    int forward = 0;
    do {
      current = current->next;
      countOp++;
      forward++;
      } while (!current->light);
    current->light = false;
    for (int j = 0; j < forward; j++) {
      current = current->prev;
      countOp++;
      }
    if (!current->light) {
      return forward;
      }
    }
}

int Train::getOpCount() { return countOp; }
