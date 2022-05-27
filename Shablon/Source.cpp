#include<iostream>
using namespace std;

template <typename T> struct Element
{
    T data;
    int priority;
};

template <typename T> class Queue
{
public:
    Queue();
    ~Queue();
    void Add(const Element<T>& element);
    Element<T> Remove();
    int GetCount();
    void Print();
    void PrintWithPriority();
    bool IsFull();
    bool IsEmpty();
    void Clear();
private:
    enum { empty = -1, full = 999 };
    Element<T> q[full + 1];
    int first;
};

template <typename T> Queue<T>::Queue()
{
    first = empty;
}

template <typename T> Queue<T>::~Queue()
{
    delete[] q;
}

template <typename T> void Queue<T>::Clear()
{
    first = empty;
}

template <typename T> bool Queue<T>::IsFull()
{
    return first == full;
}

template <typename T> bool Queue<T>::IsEmpty()
{
    return first == empty;
}

template <typename T> int Queue<T>::GetCount()
{
    return first + 1;
}

template <typename T> void Queue<T>::Add(const Element<T>& element)
{
    int i;
    for (i = first; i >= 0; i--)
        if (q[i].priority > element.priority)
            break;
    if (IsFull())
    {
        if (i != -1)
        {
            for (int j = 0; j < i; j++)
                q[j] = q[j + 1];
            q[i] = element;
        }
    }
    else
    {
        for (int j = first; j > i; j--)
            q[j + 1] = q[j];
        q[i + 1] = element;
        first++;
    }
}

template <typename T> Element<T> Queue<T>::Remove()
{
    if (IsEmpty())
        return Element();
    return q[first--];
}

template <typename T> void Queue<T>::Print()
{
    if (IsEmpty())
        return;
    for (int i = first; i >= 0; i--)
        cout << q[i].data << "t";
    cout << endl;
}

template <typename T> void Queue<T>::PrintWithPriority()
{
    if (IsEmpty())
        return;
    for (int i = first; i >= 0; i--)
        cout << q[i].data << ", pr: " << q[i].priority << "\t";
    cout << endl;
}

int main()
{
    Queue<char> Q;
    Element<char> Array[] = { {'A',3},{'B',2},{'C',12},{'D',0},{'E',2} };
    int length = sizeof(Array) / sizeof(Element<char>);
    for (int i = 0; i < length; i++)
    {
        Q.Add(Array[i]);
    }
    Q.PrintWithPriority();
    Element<char> exempl;
    exempl.data = 'F';
    exempl.priority = 11;
    Q.Add(exempl);
    Q.PrintWithPriority();
    system("pause");
    return 0;
}