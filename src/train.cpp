// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (first == nullptr) return;
    
    Car* current = first;
    do {
        Car* toDelete = current;
        current = current->next;
        delete toDelete;
    } while (current != first);
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
        Car* lastCar = first->prev;
        lastCar->next = newCar;
        newCar->prev = lastCar;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;
    
    Car* current = first;
    current->light = true;      // включаем свет в текущем вагоне
    
    while (true) {
        int stepsForward = 0;
        
        // Движение вперед до нахождения включенного света
        do {
            current = current->next;
            countOp++;
            stepsForward++;
        } while (!current->light);
        
        // Выключаем найденный вагон
        current->light = false;
        
        // Возвращаемся назад на пройденное количество шагов
        for (int i = 0; i < stepsForward; i++) {
            current = current->prev;
            countOp++;
        }
        
        // Если свет выключен - нашли начальный вагон
        if (!current->light) {
            return stepsForward;
        }
        
        // Иначе продолжаем алгоритм
        current = current->next;
        countOp++;
    }
}

int Train::getOpCount() {
    return countOp;
}
