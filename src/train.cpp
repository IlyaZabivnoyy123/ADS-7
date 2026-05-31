// Copyright 2021 NNTU-CS
#include "train.h"
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Train::Cage *newCar = new Train::Cage;
    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;

    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Train::Cage *last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    countOp = 0;

    first->light = true;

    Train::Cage *current = first->next;
    countOp++;
    int length = 1;

    while (current->light != true) {
        current->light = false;
        current = current->next;
        countOp++;
        length++;
    }

    if (current == first) {
        return length;
    }

    Train::Cage *backup = current;
    current = first->next;
    countOp++;
    int backupLength = 1;

    while (current != backup) {
        current->light = false;
        current = current->next;
        countOp++;
        backupLength++;
    }

    current = backup->next;
    countOp++;
    int secondLength = 1;

    while (current != first) {
        current = current->next;
        countOp++;
        secondLength++;
    }

    if (backupLength == secondLength) {
        return backupLength;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
