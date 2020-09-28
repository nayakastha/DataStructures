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

void insert_after(Node* prev_node, int new_data){
	if(prev_node == NULL){
		cout<<"The given previous node can't be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

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

Node* search_element(Node* head, int data)
{
Node* temp;
temp = head;
while(temp != NULL) 
{if(temp -> data == data)
   return temp;
else
  temp = temp -> next;
}
return NULL;
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
	cout<<"Do you want to enter another element? "<<endl;
	int p;
	cout<<"Enter ->"<<endl;
	cout<<"0-> NO \t 1-> inserting at beginning \t 2-> inserting after an element \t 3-> inserting at end"<<endl;
	cin>>p;
	switch(p){
		case 1: {
			int m;
	        cout<<"Enter the element :";
	        cin>>m;
	        insert_start(&head,m);
	        printList(head);
			break;
		}
		
		case 3: {
			int m;
	        cout<<"Enter the element :";
	        cin>>m;
	        insert_end(&head,m);
	        printList(head);
			break;
		}
		
		case 0:{
			printList(head);
			break;
		}
		
		case 2:{
			cout<<"enter the element after which you want to insert :"<<endl;
			int d;
			cin>>d;
			cout<<"enter the element to insert :";
			int e;
			cin>>e;
			insert_after(search_element(head,d),e);
			printList(head);
			
			break;
		}
		default :
			printList(head);
	}
	
	return 0;
}





