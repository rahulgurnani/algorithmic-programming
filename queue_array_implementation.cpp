#include <bits/stdc++.h>
using namespace std;
template <typename T>
// note that space of one element of T will be wasted as we cant tell when the element was crossed etc. you can keep check using a size variable may be
struct Queue
{
	T* x;
	int front;
	int rear;
	int capacity;
	Queue(int _capacity)
	{
		x = new T[_capacity];
		capacity = _capacity;
		front = 0;
		rear = 0;
	}
	bool is_full()
	{
		return ((rear+1)%capacity == front);
	}
	bool is_empty()
	{
		return (front == rear);
	}
	void enQueue(T k)
	{
		if(is_full())
		{
			cout << "Queue is full" << endl;
			return;
		}
		x[(rear++)%capacity] = k;
	}
	T deQueue()
	{
		if(is_empty())
		{
			cout << "Queue is_empty" << endl;
			return -1;
		}
		return x[(front++)%capacity];
	}

};
int main()
{
	Queue<int> q(10);
	for(int i=0;i<5;i++)
		q.enQueue(i);
	for(int i=0;i<5;i++)
		cout << q.deQueue() << endl;
	for(int i=0;i<7;i++)
		q.enQueue(i);
	
	return 0;
}