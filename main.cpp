#include "header.h"
using namespace std;

int main(){
    cout<<"Выберите из списка:"<< endl;
    cout<<" 1 - Стек"<< endl;
    cout<<" 2 - Множество"<< endl;
    cout<<" 3 - Массив"<< endl;
    cout<<" 4 - Дерево"<< endl;
    cout<<" 5 - Хеш-таблица"<< endl;
    int what;
    cin>>what;
    while(true){
    if(what==1){
        string expression="";
        cout<<"Введите выражение"<<endl;
        getchar();
        getline(cin, expression);
        string rezult = Postfix(expression);
        cout<< expression<<" = "<<rezult<<endl;
        break;
    }else if(what==2){
        cout << "Введите кол-во черепах: ";
        int kol;
        cin >> kol;
        TrueOrFalse(kol);
        break;

    }else if(what==3){
        string message;
        cout << "Введите текст сообщения: ";
        getchar();
        getline(cin, message);
        histogram(message);
        break;

    }else if(what==4){
        Tree* root= nullptr;
        random_device rd;  
        mt19937 gen(rd());  
        uniform_int_distribution<> dist(1,20); 
    //random
    for (int i = 0; i < 7; ++i) {
        AddTree(root,dist(gen)); 
    }
    print_Tree(root, 0);
    AddQueue(root);
     break;
    }else if(what==5){
        cout<<"Введите число: ";
        int number;
        cin>>number;
        string rezult= RimNumber(number);
        cout<<rezult<<endl;
        break;
    }else{
        cout<<"Ошибка, введите правильное значение\n";
        cin>>what;
    }
    }
}
