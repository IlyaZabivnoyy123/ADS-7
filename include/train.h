// Copyright 2022 NNTU-CS
#ifndef TRAIN_H
#define TRAIN_H

class Train {
 private:
   struct Car {
      bool light;      // состояние лампочки
      Car* next;
      Car* prev;
   };
   int countOp;        // счетчик шагов (число переходов из вагона в вагон)
   Car* first;         // точка входа в поезд (первый вагон)
 public:
   Train();
   ~Train();           // деструктор для освобождения памяти
   void addCar(bool light);   // добавить вагон с начальным состоянием лампочки
   int getLength();           // вычислить длину поезда
   int getOpCount();          // вернуть число переходов
};

#endif
