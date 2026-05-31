// Copyright 2021 NNTU-CS
#include "train.h"
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car *newCar = new Car;
    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;

    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car *last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    countOp = 0;

    Car *start = first;
    start->light = true;

    Car *current = start->next;
    countOp++;
    int steps = 1;

    while (current->light != true) {
        current->light = false;
        current = current->next;
        countOp++;
        steps++;
    }

    if (current == start) {
        return steps;
    }

    for (int i = 0; i < steps; i++) {
        current = current->prev;
        countOp++;
    }

    if (current->light == true && current != start) {
        start->light = false;
        countOp = 0;
        return getLength();
    }

    start->light = false;
    current = start->next;
    countOp++;
    int length = 1;

    while (current != start) {
        current = current->next;
        countOp++;
        length++;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
