#ifndef QUEUE
#define QUEUE
#include<iostream>

using namespace std;

template <class T>
class Queue{
    T* queue;
    int* priority;
    int size;
    int front, rear;

    void resize(){
        T* tempQ = new T[size*2];
        int* tempP = new int[size*2];
        for(int i=0; i<size; i++) {
            tempQ[i] = queue[i];
            tempP[i] = priority[i];
        }
        delete[] priority;
        delete[] queue;
        priority = tempP;
        queue = tempQ;
        size = size*2;
    }
public:
    Queue(int s=50)
    {
        this->size = s;
        queue = new T[size];
        priority = new int[size];
        front = 0;
        rear = 0;
    }

    bool isFull()
    {
        return (rear == size - 1);
    }

    bool isEmpty()
    {
        return (front == 0 && rear == 0);
    }

    void enqueue( T element, int p )
    {
        if( isFull() )
            resize();

        int i;
        for(i=front; i != rear && p >= priority[i]; i++ );

        for(int j = rear; j > i; j--) {
            queue[j] = queue[j - 1];
            priority[j] = priority[j-1];
        }

        queue[i] = element;
        priority[i] = p;
        rear++;
    }

    void addWaitTime(){
        int i;
        for(i=front; i<rear; i++) {
            queue[i]->incrementWaiting();
        }
    }

    void printQ(){
        for(int i = front; i < rear; i++)
            cout << *queue[i];
        system("pause");
    }

    T dequeue()
    {
        if( !isEmpty() )
        {
            T e = queue[front];
            front++;
            if( front == rear )
            {
                front = 0;
                rear = 0;
            }
            return e;
        }
        return NULL;
    }

    T See_First()
    {
        if( !isEmpty() )
        {
            T e = queue[front];
            return e;
        }
        return nullptr;
    }
    ~Queue(){
        delete[] priority;
        delete[] queue;
    }
};
#endif
