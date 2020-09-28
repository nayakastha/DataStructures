//Stack_Linkedlist
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node** head_ref){
	Node* ptr = new Node();
	cout<<"Enter the data to input : ";
	cin>>ptr->data;
	ptr->next = *head_ref;
	*head_ref = ptr;
	cout<<endl;
}

int pop(Node** head_ref){
	Node* ptr = *head_ref;
	*head_ref = ptr->next;
	cout<<endl;
	return ptr->data;
	
}

void printStack(Node* node){
   cout<<"The Stack is : ";
   while (node != NULL)  
    {   cout<<" "<<node->data;  
        node = node->next;  
    }  
}

int main(){
	Node* head;
	head = NULL;
	push(&head);
	push(&head);
	printStack(head);
	cout<<pop(&head);
	
	return 0;
}
