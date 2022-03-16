#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include <stdexcept>
using namespace std;

//Taking from week 12 part2
template<typename T>
class PQueue
{
  public:
    PQueue();
    ~PQueue();
    void enqueue(const T& element, int priority);
    T dequeue();
    int getSize() const;
    
  private:
    LinkedList<T> list;
};
  
template<typename T>
PQueue<T>::PQueue()
{
}

template<typename T>
PQueue<T>::~PQueue()
{
}
  
template<typename T>
void PQueue<T>::enqueue(const T& element,int priority)
{
  list.insert(priority,element);
}
  
template<typename T>
T PQueue<T>::dequeue()
{
  return list.removeFirst();
}
  
template<typename T>
int PQueue<T>::getSize() const
{
  return list.getSize();
}
  
#endif