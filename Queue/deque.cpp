//Deque
#include<iostream>
using namespace std;
#define MAX_SIZE 100

class deque
{
		int  array[MAX_SIZE];
		int  front;
		int  rear;
		int  size;

	public:
		deque(int size)
		{
			front = -1;
			rear = 0;
			this->size = size;
		}

		bool  isFull()
		{
			return ((front == 0 && rear == size-1)||front == rear+1);
		}

		bool  isEmpty()
		{
			return (front == -1);
		}

		void  insertfront(int key);
		void  insertrear(int key);
		void  deletefront();
		void  deleterear();
		int  getFront();
		int  getRear();
};

void deque::insertfront(int key)
{
	if (isFull())
		{
			cout << "Overflow!!\n" << endl;
			return;
		}
	if (front == -1)
		{
			front = 0;
			rear = 0;
		}
	else if (front == 0)
		front = size - 1 ;
	else
		front = front-1;

	array[front] = key ;
}

void deque::insertrear(int key)
{
	if (isFull())
		{
			cout << " Overflow!!\n " << endl;
			return;
		}

	if (front == -1)
		{
			front = 0;
			rear = 0;
		}
	else if (rear == size-1)
		rear = 0;
	else
		rear = rear+1;

	array[rear] = key ;
}

void deque::deletefront()
{
	if (isEmpty())
		{
			cout << "Queue Underflow!!\n" << endl;
			return ;
		}

	
	if (front == rear)
		{
			front = -1;
			rear = -1;
		}
	else
		
		if (front == size -1)
			front = 0;

		else 
			front = front+1;
}

void deque::deleterear()
{
	if (isEmpty()) 
    { 
		cout << " Underflow!!\n" << endl ; 
		return ; 
    } 
   
    
   if (front == rear) 
    { 
		front = -1; 
		rear = -1; 
    } 
  else if (rear == 0) 
	rear = size-1; 
  else
    rear = rear-1; 
} 

int deque::getFront() 
{ 
if (isEmpty())   { 
cout << " Underflow!!\n" << endl; 
return -1 ; 
    } 
return array[front]; 
}

int deque::getRear()
{
	if(isEmpty() || rear < 0)  { 
		cout << " Underflow!!\n" << endl; 
		return -1 ; 
    } 
   return array[rear]; 
}

int main(){
	deque d(5);
	//carry out necessary fuctions
}
