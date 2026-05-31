// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (first == nullptr) return;
    
    Car* current = first;
    Car* nextCar = nullptr;
    
    // Освобождаем память циклического списка
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}

void Train::addCar(bool light) {
    Car* newWagon = new Car;
    newWagon->light = light;
    newWagon->next = nullptr;
    newWagon->prev = nullptr;
    
    if (first == nullptr) {
        first = newWagon;
        first->next = first;
        first->prev = first;
    } else {
        Car* tail = first->prev;
        tail->next = newWagon;
        newWagon->prev = tail;
        newWagon->next = first;
        first->prev = newWagon;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;
    
    Car* current = first;
    current->light = true;      // маркируем стартовый вагон включенным светом
    
    while (true) {
        int forwardSteps = 0;
        
        // Движение вперед до встречи с включенной лампочкой
        do {
            current = current->next;
            countOp++;
            forwardSteps++;
        } while (!current->light);
        
        // Выключаем найденную лампочку
        current->light = false;
        
        // Возвращаемся на пройденное количество шагов назад
        for (int step = 0; step < forwardSteps; step++) {
            current = current->prev;
            countOp++;
        }
        
        // Если текущий вагон имеет выключенный свет - мы нашли начало
        if (!current->light) {
            return forwardSteps;
        }
        
        // Иначе переходим к следующему вагону и продолжаем
        current = current->next;
        countOp++;
    }
}

int Train::getOpCount() {
    return countOp;
}
