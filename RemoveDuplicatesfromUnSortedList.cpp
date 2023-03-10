/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. 
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
  while(temp!=NULL)
  {
  cout<<temp->data<<" ";
  temp=temp->next;
}
}
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int> s; 
     Node * ptr = head;
     Node *prev = NULL;
     while(ptr){
         if(s.count(ptr->data)==0){
             prev = ptr;
             s.insert(ptr->data);
         }
         else{
            prev->next = ptr->next;
         }
            ptr=ptr->next;
     }
     return head;
    }
};

int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
