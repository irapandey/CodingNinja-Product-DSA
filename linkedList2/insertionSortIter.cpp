// Sort a given linked list using Insertion Sort (iteratively).
// You don't need to print the elements, just sort the elements and return the head of updated LL.
// Input format : Linked list elements (separated by space and terminated by -1)`

// Sample Input 1 :
// 1 4 5 2 -1
// Sample Output 1 :
// 1 2 4 5

//insertion sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

node* insertion_sort_LinkedList_itr(node* head)
{
    if(head == NULL){
        return head;
    }
    node* curr = head -> next;
    node* prev = head;
    while(curr != NULL){
        int k = 0;
        node* temp = head, *p = head;

        while(temp != curr){
            if(curr -> data < temp -> data){
                node* t = curr -> next;
                if(temp == head){
                    head = curr;
                    prev -> next = t;
                    curr -> next = temp;
                    curr = t;
                }
                else{
                    p -> next = curr;
                    curr -> next = temp;
                    prev -> next = t;
                    curr = t;
                }
                k = 1;
                break;
            }
            else{
                p = temp; 
                temp = temp -> next;
            }
        }
        if(k == 0){
            prev = curr;
            curr = curr -> next;
        }
    }
    return head;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    head=insertion_sort_LinkedList_itr(head);
    print(head);
}
