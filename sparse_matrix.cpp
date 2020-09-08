// Sparse Matrix
#include<bits/stdc++.h>
using namespace std;


void rep_array(int sparseMatrix[][5] ,int m, int n)
{
	int size = 0;
	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (sparseMatrix[i][j] != 0)
						{
							size++;
							
						}
				}
		}
	int compactMatrix[3][size];
	int k = 0;
	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				if (sparseMatrix[i][j] != 0)
					{
						compactMatrix[0][k] = i;
						compactMatrix[1][k] = j;
						compactMatrix[2][k] = sparseMatrix[i][j];
						k++;
					}
		}
	cout<<"The Array representation is :"<<endl;

	for(int i=0; i<size; i++)
		{
			cout<<compactMatrix[0][i]<<" "<<compactMatrix[1][i]<<" "<<compactMatrix[2][i]<<endl;
		}
}

class Node
{
	public:
		int value;
		int row_position;
		int column_position;
		Node *next;
};

void create_new_node(Node** start, int non_zero_element,
                     int row_index, int column_index )
{
	Node *temp, *r;
	temp = *start;
	if (temp == NULL)
		{

			temp = new Node();
			temp->value = non_zero_element;
			temp->row_position = row_index;
			temp->column_position = column_index;
			temp->next = NULL;
			*start = temp;

		}
	else
		{
			while (temp->next != NULL)
				temp = temp->next;

			r = new Node();
			r->value = non_zero_element;
			r->row_position = row_index;
			r->column_position = column_index;
			r->next = NULL;
			temp->next = r;

		}
}

void PrintList(Node* start)
{
	Node *temp1;
	temp1 = start;
    cout<<"The Linked List representation :"<<endl;
	
	while(temp1 != NULL)
		{
            cout<<"( ";
			cout<<temp1->row_position<<" "<<temp1->column_position<<" "<<temp1->value<<" )";
			temp1 = temp1->next;
		}
	cout<<endl;

	
	}

void rep_linkedlist(int sparseMatrix[][5], int m, int n)
{
	Node* start = NULL;

	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)

				{
					if (sparseMatrix[i][j] != 0)
						create_new_node(&start, sparseMatrix[i][j], i, j);
				}
		}

	PrintList(start);
}

int main()
{
	int sparseMatrix[4][5] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};
	rep_array(sparseMatrix,4,5);
	rep_linkedlist(sparseMatrix,4,5);
	return 0;
}
