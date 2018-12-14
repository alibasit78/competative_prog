#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* create_node(int data)
{
	struct node* temp=new node;
	temp->data=data;
	temp->next=NULL;
	return temp;
}
struct node* create_CLL(int n)
{
	if(n==0)
		return NULL;
	struct node *head=create_node(1);
	struct node *prev=head;
	for(int i=2;i<=n;i++)
	{
		prev->next=create_node(i);
		prev=prev->next;
	}
	prev->next=head;
	return head;
}
int joseph(int n,int k)
{
	struct node *head=create_CLL(n);
	struct node* curr;struct node * prev;
	curr=prev=head;
	while(curr->next!=curr)
	{
		int c=1;
		while(c!=k)
		{
			prev=curr;
			curr=curr->next;
			c++;
		}
		prev->next=curr->next;
		curr=prev->next;		
	}
	return curr->data;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<joseph(n,k)<<endl;
	}
}
