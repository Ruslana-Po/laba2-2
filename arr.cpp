#include "header.h"
void histogram(string str){
    // Создаем массив для подсчета частоты символов
    const int ASCII_SIZE = 128;

    Arr<int> arr(ASCII_SIZE);
    //Заполним нулями
    for(int i=0; i<ASCII_SIZE; i++){
        arr.AddAtIndex(i, 0);
    }
    //Заполнила массив элементами
    for (char ch : str) {
        if (ch != ' ' && ch != '\n') { // Игнорируем пробелы и переводы строк
           
            int r = arr.returnItemByIndex(static_cast<int>(ch));
            r++;
            arr.replaceItemByIndex(static_cast<int>(ch),r);
        }
    }
    // Создаем массив для хранения символов и их частот
    Arr<string> characters(ASCII_SIZE);
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (arr.returnItemByIndex(i) > 0) {
            characters.AddArr(string(1, static_cast<char>(i)) + " " + to_string(arr.returnItemByIndex(i)));
        }
    }
    //characters.Print();
    // Сортируем символы по возрастанию их кодов
    for (int i = 0; i < characters.Size() - 1; ++i) {
        for (int j = 0; j < characters.Size() - i - 1; ++j) {
            char char1 = characters.number[j][0];
            char char2 = characters.number[j + 1][0];
            if (char1 > char2) {
                swap(characters.number[j], characters.number[j + 1]);
            }
        }
    }
     // Находим максимальную частоту для определения высоты гистограммы
    int max_frequency = 0;
    for (int i = 0; i < characters.Size(); ++i) {
        //Берем 2 символ тк там хранится кол-во буквы
        int freq = stoi(characters.number[i].substr(2));
        if (freq > max_frequency) {
            max_frequency = freq;
        }
    }
    // Выводим гистограмму
    for (int i = max_frequency; i > 0; --i) {
        for (int j = 0; j < characters.Size(); ++j) {
            int freq = stoi(characters.number[j].substr(2));
            if (freq >= i) {
                cout << "# ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    // Выводим символы под гистограммой
    for (int i = 0; i < characters.Size(); ++i) {
        cout << characters.number[i][0] << " ";
    }
    cout << endl;
}
