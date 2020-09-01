#include <bits/stdc++.h>
using namespace std;
  

class Node {
  public:	
   int data;
   Node* next;
   Node* prev;
};
  
void insert_front(Node** head)
{ 
  int new_data; 
  cout<<"Enter the data for insertion at beginning :";
  cin>>new_data;
   //allocate memory for New node
   Node* newNode = new Node();
   newNode->data = new_data;

   newNode->next = (*head);
   newNode->prev = NULL;
  
    if ((*head) != NULL)
       (*head)->prev = newNode;
  
   (*head) = newNode;
}

void insert_After(Node* prev_node)
{  
   int new_data;
   cout<<"Enter the data to insert :";
   cin>>new_data;
   
   if (prev_node == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
   }
   
   Node* newNode = new Node();

   newNode->data = new_data;
   newNode->next = prev_node->next;
   prev_node->next = newNode;
   newNode->prev = prev_node;
   if (newNode->next != NULL)
      newNode->next->prev = newNode;
}
  
void insert_end(Node** head)
{  
   int new_data;
   cout<<"Enter the data to insert :";
   cin>>new_data;
   Node* newNode = new Node();
   Node* last = *head; 
   newNode->data = new_data;
   newNode->next = NULL;
   if (*head == NULL) {
      newNode->prev = NULL;
      *head = newNode;
      return;
    }
  while (last->next != NULL)
     last = last->next;

  last->next = newNode;
  newNode->prev = last;
  return;
}
  
void displayList(Node* node)
 { 
   cout<<"The linked list: "<<endl;
   cout<<"NULL<==>";
   Node* last;
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
    cout<<"NULL";
    cout<<endl; 
   }
  
void reverseList(Node** head)
{  
   cout<<"The reversed linked list: "<<endl;
   Node* left = *head, * right = *head;
   while (right->next != NULL)
   right = right->next;
   while (left != right && left->prev != right) {
  
      
      swap(left->data, right->data);
      left = left->next;
      right = right->prev;
   }
   cout<<endl;
}

void delete_node(Node** head)
{   int ele;
	cout<<"Enter the element to be deleted :";
	cin>>ele;
	Node* ptr = *head;
	
	while(ptr != NULL){
	  	if(ptr->data == ele){
	  		ptr->prev->next = ptr->next;
	        ptr->next->prev = ptr->prev;
	        return;
		  }
	  	else
	  		ptr=ptr->next;
	}
}
int main() {
   cout<<"WELCOME TO DOUBLY LINKED LIST"<<endl;
   Node* head = NULL;
   int n;
   cout<<"Enter the number of elements in the linked list :";
   cin>>n;
   for(int i=0; i<n; i++){
   	insert_end(&head);
   }
   displayList(head);
   delete_node(&head);
   displayList(head);
   reverseList(&head);
   displayList(head);
   return 0;
}

