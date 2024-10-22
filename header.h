#include<iostream>
#include<string>
#include<locale>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;


//Стек


struct NodeS{
    string person;
    NodeS* next;
};

struct Stack{
    NodeS* head;
};
void push(Stack* stack, string element);
void pop(Stack* stack);
void Show(Stack* MyList);
string Postfix (string exe);

struct Tree{
    int value;
    Tree* left;
    Tree* right;
    //1 знач, конструктор
    Tree(int val) : value(val), left(nullptr), right(nullptr){}
};
//Очередь
struct NodeQ{
    Tree* tree;
    NodeQ* next;
    NodeQ(Tree* node) : tree(node), next(nullptr){}
};

struct Queue{
    NodeQ* head;
    NodeQ* tail;
    Queue() : head(nullptr), tail(nullptr) {}
};
void pushQ(Queue* queues, string element);
void pushTree(Queue* q, Tree* node);
void popQ(Queue* queues);
//Дерево
void AddTree(Tree*& root, int value);
void print_Tree(Tree* root, int level);
void AddQueue(Tree* root);
bool isEmpty(Queue* queues);
Tree* peek(Queue* queues);
//arr
template <typename T>
struct Arr {
     // Указатель на массив
    T* number;
     // Текущий размер массива
    int sizes;
    // Вместимость массива
    int capacity;
    // Выделяемая память под массив
    Arr(int cap) : sizes(0), capacity(cap) {
        number = new  T[capacity];
    }
    // Освобождаем память
    ~Arr() {
        delete[] number;
    }

    void reSize() {
        // Увеличиваем вместимость вдвое
        capacity *= 2;
         T* new_node = new  T[capacity];
        for (int i = 0; i < sizes; ++i) {
            // Копируем старые данные
            new_node[i] = number[i];
        }
        // Освобождаем старую память
        delete[] number;
        number = new_node;
    }

    void AddArr(T value) {
        if (sizes >= capacity) {
            //меняем размер
            reSize();
        }
        // Добавляем элемент в конец
        number[sizes++] = value;
    }
    //Добавляем по индексу
    void AddAtIndex(int index,  T value) {
        if (index < 0 || index > sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        if (sizes >= capacity) {
            reSize();
        }
        for (int i = sizes; i > index; --i) {
            number[i] = number[i - 1];
        }
        number[index] = value;
        sizes++;
    }
    //Элемент по индексу
    T returnItemByIndex(int index) {
        if (index < 0 || index >= sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return -1;
        }
        return number[index];
    }
    //Удаление по индексу
    void removeItemByIndex(int index) {
        if (index < 0 || index >= sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        for (int i = index; i < sizes - 1; ++i) {
            number[i] = number[i + 1];
        }
        sizes--;
    }
    //Замена по индексу
    void replaceItemByIndex(int index,  T value) {
        if (index < 0 || index >= sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        number[index] = value;
    }
    //Текущий размер
    int Size() {
        return sizes;
    }
    void Print(){
        for (int i = 0; i < sizes; ++i) {
           cout << number[i]<<" ";
        }
    }
    void Remerse(){
        for (int i = 0; i < sizes/2; ++i) {
            T temp =number[i];
            number[i]=number[sizes-i-1];
            number[sizes-i-1]=temp;
        }
    }

};
//hash
struct Item{
    string key;
    string value;
    Item* next;
};
struct HashTab{
    int sizeArr=13;
    Item** tabl;
    HashTab() {
        tabl = new Item*[sizeArr];
        for (int i = 0; i < sizeArr; i++) {
            tabl[i] = nullptr;
        }
    }

    ~HashTab() {
        for (int i = 0; i < sizeArr; i++) {
            delete tabl[i];
        }
        delete[] tabl;
    }

    //хэш функция
    int Hash(string itemKey){
        for(int i=0; i<sizeArr; i++){
            if(tabl[i]->key==itemKey){
                return i;
            }
        }
        return -1;
    }
    bool isFull() {
        int count = 0;
        for (int i = 0; i < sizeArr; i++) {
            if(tabl[i]!=nullptr){
                count++;
            }


        }
        // Проверка на количество элементов
        return count >= sizeArr;
    }

    //Добавление
     void AddHash(string key, string value){
        //Проверка на есть ли место
        if (isFull()) {
            cout << "Хэш-таблица переполнена. Невозможно добавить новый элемент." << endl;
            return;
        }
        for(int i=0; i<sizeArr;i++){
            if(tabl[i]==nullptr){
                Item* new_node= new Item{key, value, tabl[i]};
                tabl[i] = new_node;
                break;
            }
        }
    }

    //Получение значения по ключу
    void KeyItem(string key){
          int index= Hash(key);
         if(tabl[index]->key==key){
            cout << "key: "<<key<<" value: "<< tabl[index]->value << endl;
            return;
         }
        cout<<"Такого ключа нет."<<endl;
    }

    //Вывод
    void Print() {
        for (int i = 0; i < sizeArr; i++) {
                cout << " key: " << tabl[i]->key << " value: " << tabl[i]->value;
                cout<<endl;

        }

    }
};

string RimNumber(int number);
void histogram(string str);
//hash
struct Set{
    string value;
};
struct SetNode {
    int sizes;
    Set** much;
    SetNode(int cap) : sizes(cap) {
        much = new Set*[sizes];
        for (int i = 0; i < sizes; ++i) {
            much[i] = nullptr;
        }
    }

    ~SetNode() {
        for (int i = 0; i < sizes; ++i) {
            delete much[i];
        }
        delete[] much;
    }

    // Чтобы без повторов
    int HashSet(string itemKey) {
        int result = 0;
        for (char i : itemKey) {
            result += static_cast<int>(i);
        }
        return abs(result) % sizes;
    }

    bool isFull() {
        int count = 0;
        for (int i = 0; i < sizes; i++) {
            if (much[i] != nullptr) {
                count++;
            }
        }
        // Проверка на количество элементов
        return count >= sizes;
    }
    bool ReturnZnach(string value, int& znach){
        // Поиск элемента для удаления
        int index= HashSet(value);
        for (int i = 0; i < sizes; i++) {
            if (much[i] == nullptr) {
                return false; // элемент не найден
            }
            if (much[i]->value == value) {
                znach=i;
                return true;
            }
        }
        return false;
    }

    // Добавление
    void AddSet(string value) {
        int index = HashSet(value);
        // Наличие уже такого ключа
        if (much[index] != nullptr && much[index]->value == value) {
            return;
        }
        // Наличие уже такого ключа, если колизия его передвинула
        int rezult=0;
        bool znach=ReturnZnach(value, rezult);
        if(znach){
            return;
        }
        // Проверка на есть ли место
        if (isFull()) {
            cout << "Множество переполнено. Невозможно добавить новый элемент." << endl;
            return;
        }
        // Занят ли индекс
        if (much[index] == nullptr) {
            much[index] = new Set{value}; // Создание нового элемента без передачи предыдущего значения
        } else {
            // Поиск первого свободного места
            for (int i = 0; i < sizes; i++) {
                if (much[i] == nullptr) {
                    much[i] = new Set{value}; // Создание нового элемента
                    break;
                }
            }
        }
    }


    //удаление
    void DelSet(string value){
         //Если было без колизий
         int index= HashSet(value);
         if(much[index]->value==value){
            delete much[index];
            much[index]=nullptr;
            return;
         }

        bool znach = ReturnZnach(value, index);
        if(znach){
            delete much[index];
            much[index]=nullptr;
            return;
        }
    }
    //Есть ли такой элемент
    void SetAt(string value){
        int index= HashSet(value);
         //Если было без колизий
         if(much[index]->value==value){
            cout <<" value: "<< much[index]->value<< endl;
            return;
         }
          bool znach = ReturnZnach(value, index);
        if(znach){
            cout <<" value: "<< much[index]->value<< endl;
            return;
        }
        cout<<"Такого значения нет."<<endl;
    }
     //Вывод
    void Print() {

        for (int i = 0; i < sizes; i++) {
            if (much[i] != nullptr) {
                cout << much[i]->value<<" ";
            }
            cout<<endl;
    }
    }

};


void TrueOrFalse(int kol);
