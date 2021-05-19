#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;
Node *head,*node2,*node3;

int main(){
    head  = new Node; 
    node2 = new Node;
    node3 = new Node;
   (*head).data = 1;
   head -> next = node2;
   node2 -> data = 2;
   node2 -> next = node3;
   node3 -> data = 3;
   node3 -> next = NULL;
   Node *cur = head;
   cout <<"duyet cac phan tu trong list: " ;
   for(cur = head; cur != NULL; cur = cur -> next)
        cout << cur -> data << " ";
   delete head; 
   delete node2;
   delete node3;
}