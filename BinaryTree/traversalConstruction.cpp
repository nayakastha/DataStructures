#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* lchild;
		Node* rchild;
		Node(int value)
		{

			data = value;
			lchild = NULL;
			rchild = NULL;
		}
};

int search(int arr[], int start, int end, int value)
{
	int i=0;
	for(i = start; i < end; i++ )
		{
			if (arr[i] == value)
				return i;
		}
	return -1;
}

Node* buildTree_inpre(int in[], int pre[], int start, int end )
{
	int preIndex = 0;
	if(start > end)
		return NULL;
	Node* temp = new Node(pre[preIndex++]);
	if(start == end)
		return temp;
	int inIndex = search(in, start, end, temp->data);
	temp->lchild = buildTree_inpre(in,pre,instart,inIndex-1);
	temp->rchild = buildTree_inpre(in,pre,inIndex+1,end);
	return temp;
}

Node* buildTree_inpost(int in[], int post[], int start, int end){
	int postIndex = end-1;
	if(start > end)
	  return NULL;
	Node* temp = new Node(post[postIndex--]);
	if(start == end)
	  return temp;
	int inIndex = search(in,start,end,temp->data);
	temp->rchild =  buildTree_inpost(in, post, inIndex+1, end);
	temp->lchild = buildTree_inpost(in, post, start, inIndex-1);
	return temp;   
}
//Given only pre-order and post-order you can't construct a Unique Binary tree.
//But, you can construct a unique full binary tree.
Node* buildTreeUtil(inr pre[], int post[], int* preIndex, int l, int h, int size){
        if (*preIndex >= size || l > h)  
         return NULL; 
        Node* temp = new Node( pre[*preIndex] );  
        ++(*preIndex); 
	if(l == h)
         return temp;
	int i;  
        for (i = l; i <= h; ++i)  {
	  if (pre[*preIndex] == post[i])  
            break; 
	}
	if (i <= h)  
       {  
        temp->left = constructTreeUtil (pre, post, preIndex, 
                                                l, i, size);  
        temp->right = constructTreeUtil (pre, post, preIndex,  
                                                 i + 1, h, size);  
       }  
  
    return temp;  
        
}
Node* buildTree_prepost(int pre[], int post[], int size){
	int preIndex = 0;
	return buildTreeUtil(pre, post, &preIndex, 0, size-1, size);
	
}

