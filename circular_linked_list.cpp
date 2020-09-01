#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 

void insertNode(Node** head_ref) 
{ 
    int data;
    cout<<"Enter the data to insert at the beginning :";
    cin>>data;
    
    Node* ptr = new Node(); 
    ptr->data = data; 
    ptr->next = *head_ref; 

    if (*head_ref != NULL) { 
         
        Node* temp = *head_ref; 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr; 
    } 
    else
        ptr->next = ptr; 
  
    *head_ref = ptr; 
} 

Node* searchele(Node* head , int x)
{   
	Node *current = head;
	cout<<current->data;
    do 
    {
		// Nothing to look into
		if (current == NULL)
			return NULL;
		
		if (current->data == x)
			return current;

        current = current->next;
    } while (current != head);

    
    return NULL;
}

 void addAfter(Node *head) 
{   int data,item;
    cout<<"Enter the element after which you want to insert :";
	cin>>item;
	cout<<endl;
	cout<<"Enter the data for insertion :";
	cin>> data;
   
    if (head == NULL) 
        return; 
  
    Node *temp, *p; 
    p = head -> next; 
    do
    { 
        if (p ->data == item) 
        { 
            Node* temp = new Node(); 
            temp -> data = data; 
            temp -> next = p -> next; 
            p -> next = temp; 
  
            if (p == head) 
                head = temp; 
            return ; 
        } 
        p = p -> next; 
    }  while(p != head -> next); 
  
    cout << item << " not present in the list." << endl; 
    return; 
  
} 


void printList(Node* head) 
{ 
    Node* temp = head; 
    if (head != NULL) { 
        do { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } while (temp != head); 
    } 
  
    cout << endl; 
} 
  
void deleteNode(Node** head)  
{   
    int key;
    cout<<"Enter the element to be deleted :";
    cin>>key;  
    cout<<endl;
    if (*head == NULL) 
        {
        	cout<<"Underflow:";
        	return;
		}
          
    
    if((*head)->data==key && (*head)->next==*head) 
    { 
        free(*head); 
        *head=NULL;
		cout<<"Deletion sucessful"; 
        return; 
    } 
      
    Node *last=*head,*d; 
      
    if((*head)->data==key) { 
          
        while(last->next != *head) 
            last=last->next; 
              
        last->next=(*head)->next; 
        free(*head); 
        *head=last->next; 
    } 
    
    while(last->next!=*head && last->next->data!=key) { 
        last=last->next; 
    } 
      
    if(last->next->data==key) { 
        d=last->next; 
        last->next=d->next; 
        free(d); 
    } 
    else
        cout<<"no such keyfound"<<endl;
} 




int main()
{
	Node* head = NULL;
	cout<<"Welcome to cicular linked list!!"<<endl;
	int n;
	cout<<"Enter the number of elements in your linked list:";
	cin>>n;
	cout<<endl;
	for(int i=0; i<n ;i++){
		insertNode(&head);
		cout<<endl;
		printList(head);
		cout<<endl;
	}
  addAfter(head);	
  printList(head);
  deleteNode(&head);
  printList(head);
  return 0;	
}





