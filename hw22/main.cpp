//
//  main.cpp
//  hw22
//
//  Created by Дима on 10.10.23.
//



#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
struct Element{
    int data;
    Element* prev;
    Element* next;
};

class Stack
{
    Element* head;
    Element* tail;
    int count;

public:
    Stack();
    void Push(int value);
    void Pop(int pos);
    void DelAll();
    int GetCount();
    void print();
    ~Stack();
};


Stack::Stack()
{
    head = tail = NULL;
    count = 0;
}


void Stack::DelAll()
{
    // Пока остаются элементы, удаляем по одному с головы
    while (count != 0)
        Pop(1);
}


void Stack::Push(int value)
{
    Element* temp = new Element;
      temp->next = 0;
      temp->data = value;
      temp->prev = tail;

      if (tail != 0)
          tail->next = temp;

      if (count == 0)
          head = tail = temp;
      else
          tail = temp;

      count++;
}

void Stack::Pop(int pos){
        // если параметр отсутствует или равен 0, то запрашиваем его
        if (pos == 0)
        {
            cout << "Input position: ";
            cin >> pos;
        }
        // Позиция от 1 до Count?
        if (pos < 1 || pos > count)
        {
            // Неверная позиция
            cout << "Incorrect position !!!\n";
        }

        // Счетчик
        int i = 1;

        Element* Del = head;

        while (i < pos)
        {
            // Доходим до элемента,
            // который удаляется
            Del = Del->next;
            i++;
        }

        // Доходим до элемента,
        // который предшествует удаляемому
        Element* PrevDel = Del->prev;
        // Доходим до элемента, который следует за удаляемым
        Element* AfterDel = Del->next;

        // Если удаляем не голову
        if (PrevDel != 0 && count != 1)
            PrevDel->next = AfterDel;
        // Если удаляем не хвост
        if (AfterDel != 0 && count != 1)
            AfterDel->prev = PrevDel;

        // Удаляются крайние?
        if (pos == 1)
            head = AfterDel;
        if (pos == count)
            tail = PrevDel;

      
        delete Del;

    count--;
    

}




void Stack:: print(){
    if (count != 0)
    {
        Element* temp = head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

Stack::~Stack()
{
    DelAll();
}

int main()
{

    Stack ST;
    ST.Push(1);
    ST.Push(2);
    ST.Push(3);
    ST.print();
    ST.Pop(2);
    ST.print();
}

