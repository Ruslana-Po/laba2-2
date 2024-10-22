//Очередь
#include "header.h"
//Проверка на пустоту
bool isEmpty(Queue* queues){
    return queues->head == nullptr;
}
//Достаем 1 элемент
Tree* peek(Queue* queues) {
    return  queues->head? queues->head->tree : nullptr;
}

// Функция добавления узла в очередь
void pushTree(Queue* q, Tree* node) {
    NodeQ* newNode = new NodeQ(node);
    if (!q->tail) {
        q->head = q->tail = newNode;
        return;
    }
    q->tail->next = newNode;
    q->tail = newNode;
}

//Удаление
void popQ(Queue* queues){
    if (!queues->head)  return; 
     NodeQ* new_head;
    new_head=queues->head;
    queues->head=queues->head->next;
    if (!queues->head) queues->tail = nullptr;
    delete new_head;
}
