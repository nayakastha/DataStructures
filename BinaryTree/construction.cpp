#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
     char data;
     Node* lchild;
     Node* rchild;
};

int searchElement(char arr[], int start, int end, char value){
    int i;
    for(i = start; i<=end; i++){
        if(arr[i]==value)
         return i;
    }
    return -1;
}

Node* newNode(char data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

Node* build_in_pre(char in[], char pre[], int inStart , int inEnd){
    static int preindex = 0;
    if(inStart > inEnd) return NULL;
    Node* temp = newNode(pre[preindex++]);
    if(inStart == inEnd) return temp;
    int inIndex = searchElement(in,inStart,inEnd,temp->data);
    temp->lchild = build_in_pre(in,pre,inStart,inIndex-1);
    temp->rchild = build_in_pre(in,pre,inIndex+1,inEnd);
    return temp;
}

