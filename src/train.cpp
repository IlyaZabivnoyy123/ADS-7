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
    int length = 1;

    while (true) {
        if (current->light == true) {
            if (current == start) {
                break;
            }
            current->light = false;
            current = start->next;
            countOp++;
            length = 1;
            continue;
        }
        current->light = false;
        current = current->next;
        countOp++;
        length++;
    }

    start->light = false;

    current = start->next;
    countOp++;
    int finalLength = 1;
    while (current != start) {
        current = current->next;
        countOp++;
        finalLength++;
    }

    return finalLength;
}

int Train::getOpCount() {
    return countOp;
}
