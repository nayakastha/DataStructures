//Infix to Postfix

#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
};

void push(Node** head_ref, char ch)
{
	Node* ptr = new Node();
	ptr->data = ch;
	ptr->next = *head_ref;
	*head_ref = ptr;
}

void pop(Node** head_ref)
{
	Node* ptr = *head_ref;
	*head_ref = ptr->next;

}

char top(Node* head)
{
	return head->data;
}

int prec(char ch)
{
	if(ch == '^')
		return 3;
	else if (ch == '*'||ch =='/')
		return 2;
	else if (ch == '+'|| ch == '-')
		return 1;
	else
		return 0;
}

void infix_to_postfix(string str)
{
	Node* head = new Node();
	int len = str.length();
	string res;
	for(int i = 0; i < len; i++)
		{
			if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z'))
				res += str[i];
			else if(str[i] == '(')
				push(&head,str[i]);
			else if(str[i] == ')')
				{
					while(top(head) != '(')
						{
							char c = top(head);
							pop(&head);
							res += c;
						}
					if(top(head) == '(')
						{
							char c = top(head);
							pop(&head);
						}
				}
			else
				{
					while(prec(str[i]) <= prec(top(head)))
						{
							char c = top(head);
							pop(&head);
							res += c;
						}
					push(&head,str[i]);
				}
		}
	while(head != NULL)
		{
			char c = top(head);
			pop(&head);
			res += c;
		}

	cout<<res;
}

int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infix_to_postfix(exp);
	return 0;
}






