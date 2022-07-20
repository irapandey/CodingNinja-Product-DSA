#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *reverse_linked_list_rec(Node *head)
{
    //write your recursive code here
  if(head==NULL || head ->next ==NULL)
      return head;
    
    Node* smallans=reverse_linked_list_rec(head->next);
    Node*tail= head->next;
    tail->next=head;
    head ->next =NULL;
    
    return smallans;
                                         
}

Node *kReverse(Node *head, int n)
{
    if(head==NULL)
        return NULL;
    
    Node * h1=head,*t1=head;
    int count=1;
    //move to kth node
    while(count<n && t1->next)
    {
        t1=t1->next;
        count++;
    }
    Node*h2=t1->next;
    t1->next=NULL;
    //break this part from LL 
    // and reverse it
    h1=reverse_linked_list_rec(h1);
    t1=h1;
    
    // iterate till next k nodes
    while(count>1)
    {
        t1=t1->next;
        count--;
    }
    
    // now call recuursion to kreverse remainng LL
    h2=kReverse(h2,n);
    
    //connect the LL
    t1->next=h2;
    
    return h1;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}