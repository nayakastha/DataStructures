//Priority Queue LinkedList
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		int priority;
		Node* next;
};

Node* newNode(int key, int rank)
{
	Node* temp = new Node();
	temp->data = key;
	temp->priority = rank;
	temp->next = NULL;
	return temp;
}

int Top(Node** head)
{
	return (*head)->data;
}

//Removes the Most priority element
void Pop(Node** head)
{
	Node* temp = *head;
	*head = (*head)->next;
	
}

void Push(Node** head, int key, int rank)
{
	Node* start = *head;
	Node* temp = newNode(key,rank);

	if ((*head)->priority > rank)
		{
			temp->next = *head;
			(*head) = temp;
		}
	else
		{
			while (start->next != NULL && start->next->priority < rank)
				{
					start = start->next;
				}
			temp->next = start->next;
			start->next = temp;
		}
}

bool isEmpty(Node** head)
{
	return (*head)==NULL ;
}

int main()
{
	Node* pq = newNode(4, 1); 
    Push(&pq, 5, 2); 
    Push(&pq, 6, 3); 
    Push(&pq, 7, 0); 
  
    while (!isEmpty(&pq))  
    { 
        cout << " " << Top(&pq); 
        Pop(&pq); 
    } 
	return 0;
}












