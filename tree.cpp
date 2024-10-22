//Tree
#include "header.h"

void AddTree(Tree*& root, int value){
     if (root == nullptr) {
     // Создаем новый узел, если дерево пустое
        Tree* new_root= new Tree(value);
        root=new_root;
        return;
    }

    if (value <= root->value) {
        // Рекурсивно добавляем в левое поддерево
        AddTree(root->left, value);
    } else {
        // Рекурсивно добавляем в правое поддерево
        AddTree(root->right, value);
    }
}

void AddQueue(Tree* root){
    cout<<endl;
    if (!root) return;
    // Переменная для отслеживания направления
    bool leftToRight = true; 
    //Временная очередь
    Queue q;
    Queue newQ;
    pushTree(&q,root);

    while (!isEmpty(&q))
    {
        int sizes = 0;
         // Подсчитываем количество узлов на текущем уровне
        NodeQ* temp = q.head;
        while (temp) {
            sizes++;
            temp = temp->next;
        }
        //Временное хранилище элементов из массива
        Arr<string> arr(sizes);
        for (int i = 0; i < sizes; ++i) {
            Tree* node = peek(&q);
            popQ(&q);
            arr.AddArr(to_string(node->value));
            // Добавляем дочерние узлы в следующем уровне
            if (node->left){
                pushTree(&newQ, node->left);
            } 
            if (node->right){
                pushTree(&newQ,node->right);
            } 
        }
        //Нечетный уровень
        if(!leftToRight){
            arr.Remerse();
        }
        arr.Print();
        // Меняем очередность для следующего уровня
        leftToRight = !leftToRight;
        swap(q,newQ);
        
    }
}

void print_Tree(Tree* root, int level){
    if (root != NULL)
    {
        print_Tree(root->left, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << root->value << endl;
        print_Tree(root->right, level + 1);
    }
}

