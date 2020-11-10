//Code based on  https://www.youtube.com/watch?v=mDt53JLj8sM

#include<iostream>
using namespace std;

class Node{
  public:
    int key;
    int data;
    Node* next;

   //Constructor
    Node(){
      key  = 0;
      data = 0;
      next = NULL;
    }

   //Constructor:parameterised
    Node(int k, int d, Node* n=NULL){
      key  = k;
      data = d;
      next = n;
    }
};


class SinglyLinkedList{
  public:
    Node* head;
    Node* tail;
    int   num_nodes;

    //Constructor
    SinglyLinkedList(){
        //cout<<"constructor1"<<"\n";
        head      = NULL;
        tail      = NULL;
        num_nodes = 0;
    }

    //parameterised constructor using a single head node as input
    //Note: that the head node can point to a chain of linked nodes
    SinglyLinkedList(Node* n_hd){
        this->head       = n_hd;

        Node *curr = head;
        this->num_nodes = 0;
        while(curr !=NULL){
          num_nodes ++;
          tail = curr;
          curr = curr->next;
        }
    }


    //parameterised constructor using an array of values
    //Here we create Nodes , assign 1 value per Node and link them
    SinglyLinkedList(int arr[], int array_size){
        this->num_nodes = array_size;
        unsigned int count = 0;
        Node* curr   = new Node(count,arr[count]);
        this->head  = curr;

        count++;
        Node* prev = curr;

        while(count < this->num_nodes){
            curr       = new Node(count,arr[count]);
            //Create a link to the previous node
            prev->next = curr;

            count++;
            prev = curr;
        }
        tail       = curr;
        tail->next = NULL;
    }



    void print_list(){
        //cout<<"Linked List Values : ";
        Node* ptr= this->head;
        //cout<<ptr->key<<":"<<ptr->data<<" ";

        while(ptr !=NULL){
          cout<<ptr->key<<":"<<ptr->data<<" ";
          ptr = ptr->next;
        }
        cout<<"\n";
    }


};//EOF class SinglyLinkedList{





int main()
{
  int arr[11]    = {101,6,854, 987, 723,323, 91, 12,13,17,19};
  int array_size = sizeof(arr)/sizeof(arr[0]);
  SinglyLinkedList my_list(arr, array_size);
  my_list.print_list();
  return 0;
}
