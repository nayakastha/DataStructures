
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void insert_start(Node** head_ref , int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/*void insert_after(Node* prev_node, int new_data){
	if(prev_node == NULL){
		cout<<"The given previous node can't be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}*/

void insert_end(Node** head_ref, int new_data){
	Node* new_node = new Node();
	Node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL)
	 {
	 	*head_ref = new_node;
	 	return;
	 }
	while (last->next != NULL)  
        last = last->next;  
    last->next = new_node;  
    return;  
	
}
void deleteNode(Node **head_ref, int key) {

    struct Node* temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;  
        free(temp);               
        return; 
    } 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL){
    cout<<"element not found"<<endl; 	
	return; }
    prev->next = temp->next; 
    free(temp);  
} 
void printList(Node *node)  
{  cout<<"The linked list is : ";
   while (node != NULL)  
    {   cout<<" "<<node->data;  
        node = node->next;  
    }  
}  

int main(){
	Node* head = NULL;
	int a;
	cout<<"Enter the first element :";
	cin>>a;
	insert_start(&head,a);
	int n;
	cout<<"Enter the number of elements for the list :";
	cin>>n;
	for(int i=1; i<n; i++){
		int b;
		cout<<"Enter the "<<i+1<< " element :";
    	cin>>b;
    	insert_end(&head,b);
	}
	printList(head);
	cout<<endl;
	char ch;
	cout<<"Do you want to delete an element?(Y/N) "<<endl;
	cin>>ch;
	switch(ch){
		case 'Y':{
			int m;
			cout<<"enter the element to be deleted : ";
			cin>>m;
			deleteNode(&head,m);
			printList(head);
			break;
		}
	}
}











