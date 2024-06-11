
#include<bits/stdc++.h>
using namespace std;
struct node{
   int data;
   struct node *next;


};
void PrintList();
struct node* insertionAtBeginning();
struct node* insertionAtPosition();
struct node* insertionAtEnd();
struct node* deletionAtBeginning();
struct node* deletionAtPosition();
struct node* deletionAtEnd();

struct node* deletionAtPosition(struct node *head)
{
    int position;
    cout<<"Enter the position : ";
    cin>>position;

     struct node *nextnode,*temp;
     temp=head;
     for(int i=0;i<position-2;i++)
     {
         temp=temp->next;

     }
     nextnode=temp->next;
     temp->next=nextnode->next;
     free(nextnode);
     return head;


};
struct node* deletionAtBeginning(struct node *head)
{
   struct node *temp=head;
   head=head->next;
   free(temp);

   return head;


};
struct node* deletionAtEnd(struct node *head)
{
    struct node *prev, *temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    prev->next=NULL;
     free(temp);

     return head;

};

struct node* insertionAtEnd(struct node *head)
{
     struct node *newnode,*temp;
     newnode=(struct node*)malloc( sizeof(struct node));
     cout<<"Enter the new data: ";
     cin>>newnode->data;
     newnode->next=NULL;

     temp=head;
     while(temp->next!=NULL)
    {
         temp=temp->next;

     }
     temp->next=newnode;
    return head;

};

struct node* insertionAtPosition(struct node *head)
{
    int position;
    cout<<"Enter the position : ";
    cin>>position;

     struct node *newnode,*temp;
     newnode=(struct node*)malloc( sizeof(struct node));
     cout<<"Enter the new data: ";
     cin>>newnode->data;
     newnode->next=NULL;

     temp=head;
     for(int i=0;i<position-2;i++)
     {
         temp=temp->next;

     }
     newnode->next=temp->next;
     temp->next=newnode;
     return head;
};


void PrintList(struct node *head)
{
    cout<<"New list :"<<endl;
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    return ;
}

struct node* insertionAtBeginning(struct node *head)
{
    struct node *newnode;
     newnode=(struct node*)malloc( sizeof(struct node));
     cout<<"Enter the new data : ";
     cin>>newnode->data;
     newnode->next=NULL;
     newnode->next=head;
     head=newnode;
     return head;

};

int main()
{
    int n;
    cout<<"Enter the number of data of linked list: ";
    cin>>n;
    struct node *head, *newnode , *temp;
    head=NULL;
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc( sizeof (struct node));
        cout<<"Enter the "<<i<<" data :";
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;

        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    cout<<"Initial linked list: "<<endl;
    PrintList(head);
    cout<<"head after initial list: "<<head->data<<endl;

    head=insertionAtBeginning(head);
    cout<<"List after inserting begining :"<<endl;
    PrintList(head);
    cout<<"head after inserting begining list: "<<head->data<<endl;

    head=insertionAtBeginning(head);
    cout<<"List after inserting begining :"<<endl;
    PrintList(head);
    cout<<"head after inserting begining list: "<<head->data<<endl;


    head=insertionAtPosition(head);
     cout<<"List after inserting position :"<<endl;
    PrintList(head);
    cout<<"head after inserting at position list: "<<head->data<<endl;

     head=insertionAtEnd(head);
      cout<<"List after inserting end :"<<endl;
    PrintList(head);
    cout<<"head after inserting at end list: "<<head->data<<endl;

   head=  deletionAtBeginning(head);
   cout<<"List after deleting begining :"<<endl;
    PrintList(head);
    cout<<"head after deleting begining list: "<<head->data<<endl;

    head=deletionAtEnd(head);
    cout<<"List after deleting end :"<<endl;
    PrintList(head);
    cout<<"head after deleting end  list: "<<head->data<<endl;
     head=deletionAtPosition(head);
     cout<<"List after deleting at position :"<<endl;
    PrintList(head);
    cout<<"head after deleting end  position: "<<head->data<<endl;

    return 0;
}
