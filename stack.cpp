//стек

#include "header.h"
using namespace std;


//Добавление
void push(Stack* stack, string element){
    NodeS* new_node = new NodeS{element, nullptr};
    new_node->next = stack->head;
    stack->head = new_node;
}

//Удаление
void pop(Stack* stack){
    NodeS* new_head = new NodeS;
    new_head = stack->head->next;
    delete stack->head;
    stack->head= new_head;
}

//Отоборажение
void Show(Stack* MyList){
    NodeS* new_stack = new NodeS;
    new_stack = MyList->head;
    while ( new_stack != nullptr)
    {
        cout <<  new_stack->person << " ";
         new_stack =  new_stack->next;
    }
    cout<<endl;
}

string Postfix(string exe){
    Stack* number= new Stack;
    number->head=nullptr;
    string comand;
    istringstream Stream(exe);
    while(Stream>>comand){
        //Если число
        if(comand[0]>='0'&&comand[0]<='9'){
            push(number,comand);
        }else{
            int one = stoi(number->head->person);
            pop(number);
            int two = stoi(number->head->person);
            pop(number);
            if(comand[0]=='+'){
                one+=two;
                push(number, to_string(one));
            }else if(comand[0]=='-'){
                one-=two;
                push(number, to_string(one));
            }else if(comand[0]=='*'){
                one*=two;
                push(number, to_string(one));
            }else if(comand[0]=='/'){
                float element = (float)one/two;
                push(number, to_string(element));
            }
        }
        Show(number);
    }
    return number->head->person;
}
