#include "header.h"
 string RimNumber(int number){
    //Создание хэш таблиц
        HashTab ht;
        ht.AddHash("1000","M");
        ht.AddHash("900","CM");
        ht.AddHash("500","D");
        ht.AddHash("400","CD");
        ht.AddHash("100","C");
        ht.AddHash("90","XC");
        ht.AddHash("50","L");
        ht.AddHash("40","XL");
        ht.AddHash("10","X");
        ht.AddHash("9","IX");
        ht.AddHash("5","V");
        ht.AddHash("4","IV");
        ht.AddHash("1","I");
        ht.Print();
    string result="";
    cout<<ht.tabl[0]->value<<endl;
    for (int i = 0; i < 13; i++) {
        // Вычисляем, сколько раз символ может быть добавлен
        while (number >= stoi(ht.tabl[i]->key)) {
            result += ht.tabl[i]->value; // Добавляем римский символ
            number -= stoi(ht.tabl[i]->key); // Уменьшаем число
        }
    }
    return result;
 }
 
