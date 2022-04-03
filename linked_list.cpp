#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* head;
node* MakeNode(int item)
{
    node* temp = new node();
    temp->data = item;
    temp->next = NULL;
    return temp;
}
void InsertAtFirst(int item)
{
    node* temp = MakeNode(item);
    if(head!=NULL)
    {
        temp->next = head;
    }
    head = temp;
}
void InsertAtLast(int item)
{
    node* temp = MakeNode(item);
    node* index = head;
    while (index->next!=NULL)
    {
        index = index->next;
    }
    index->next = temp;


}
void Print()
{
    node* temp = head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void InsertPosition(int item, int pos)
{
    // node* temp = new node();
    // temp->data = item;
    // temp->next = NULL;
    node* temp = MakeNode(item);
    node* index = head;
    for(int i= 1; i<pos-1;i++)
    {
        index = index->next;
    }
    temp->next = index->next;
    index->next = temp;
}

void DeletePosition(int pos)
{
    node* index = head;
    for(int i=1;i<pos-1;i++)
    {
        index = index->next;
    }
    node* temp = index->next;
    index->next = temp->next;
    delete temp;

}

void DeleteAtFirst(){
 
    node* temp = head  ;
    head = temp->next;
    delete temp;
}

bool isFound(int x){

  node* temp= head;

  while (temp != NULL)
  {
      if (temp->data == x)
      {
          return true;
          break;
      }

      temp = temp->next;
      
  }
  

}

void PrintHighestElement(){
 
 
    int highest = 0;
 
    int sum = 0;
    node* temp = head;
 
    while(temp != NULL){
 
            sum = sum + temp->data;
            if(temp->data > highest){
                highest = temp->data;
            }
           // cout<<temp->data<< " ";
            temp = temp->next;
 
 
 
    }
    cout<<highest<<endl;
}

void DeleteLast(){
    
    node* index = head;

    while (index->next->next != NULL)
    {
        index=index->next;
    }
    
    delete index->next;

    index->next = NULL;
 

}
 

int main()
{
    head = NULL;
    InsertAtFirst(3);
    InsertAtFirst(4);
    InsertAtLast(7);
    InsertAtFirst(11);
    InsertPosition(99,5);
   // DeleteAtFirst();
    Print();
    DeletePosition(5);
    Print();
     DeleteAtFirst();
     Print();
    DeleteLast();
     Print();
    PrintHighestElement();
   
     if( isFound(4)){
       
       cout<<"Found!!!"<<endl;

     }
     else{
         cout<<"Not FOund  :("<<endl;
     }

    return 0;
}
