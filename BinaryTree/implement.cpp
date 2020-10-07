#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
     char data;
     Node* lchild;
     Node* rchild;
};

Node* create(){
    Node* newNode = new Node();
    cout<<"Enter the data for the node(Enter * to stop)";
    char ch;
    if(ch == '*'){
        return NULL;
    }
    newNode->data = ch;
    cout<<endl<<"Proceed to Children"<<endl;
    newNode->lchild = create();
    newNode->rchild = create();
    return newNode;
}

void inorder(Node* root){
    if(root == NULL)
      return;
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);  
}

void preorder(Node* root){
    if(root == NULL)
      return;
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);  
}

void postorder(Node* root){
    if(root == NULL)
      return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<" ";  
}

int main(){
  Node* root = new Node();
  root = create();
}
