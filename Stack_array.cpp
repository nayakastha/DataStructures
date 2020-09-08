//STACK AS ARRAY
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
		int top;
	public:
		int myStack[100];

		Stack()
		{
			top = -1;
		}
		void push(int x);
		int pop();
		bool isEmpty();
};

void Stack::push(int item)
{
	if (top >= (MAX-1))
		{
			cout << "Stack Overflow!!!";
			return;
		}
	else
		{
			myStack[++top] = item;
			cout<<item<<endl;
			
		}
}


int Stack::pop()
{
	if (top < 0)
		{
			cout << "Stack Underflow!!";
			return 0;
		}
	else
		{
			int item = myStack[top--];
			return item;
		}
}


bool Stack::isEmpty()
{
	return (top == -1);
}


int main()
{
	class Stack stack;
	cout<<"The Stack Push "<<endl;
	stack.push(2);
	stack.push(4);
	stack.push(6);
	cout<<"The Stack Pop : "<<endl;
	while(!stack.isEmpty())
		{
			cout<<stack.pop()<<endl;
		}
	return 0;
}

