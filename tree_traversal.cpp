#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
struct node_s
{
	struct node* t_node;
	struct node_s* next;
};
static struct node* create_node(int data)
{
	struct node* new_node=new node;
	new_node->data=data;
	new_node->left=new_node->right=NULL;
	return new_node;
}

class _Stack_
{
public:
	struct node_s *top;
	_Stack_()
	{
		top=NULL;
	}
	void push(struct node *temp)
	{
		struct node_s *new_node=new node_s;
		new_node->t_node=temp;
		new_node->next=top;
		top=new_node;
	}
	struct node* pop()
	{
		if(top==NULL)
		{
			return NULL; 
		}
		else
		{
			struct node* temp=top->t_node;
			struct node_s *t=top;
			top=top->next;
			free(t);
			return temp;
		}
	}
	void display()
	{
		struct node_s *temp=top;
		while(temp!=NULL)
		{
			cout<<temp->t_node->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	struct node* _top_()
	{
		return top->t_node;
	}
	bool isEmpty()
	{
		if(top==NULL)
			return true;
		return false;				
	}
};
static void inorder(struct node* temp)
{
	if(temp==NULL)
		return;
	_Stack_ s;
	struct node *cur=temp;
	while(cur!=NULL||!s.isEmpty())
	{
		while(cur!=NULL)
		{
			s.push(cur);
			cur=cur->left;
		}
		cur=s._top_();
		s.pop();
		cout<<cur->data<<" ";
		cur=cur->right;
	}
}
static void preorder(struct node *temp)
{
	_Stack_ s;
	if(temp==NULL)
		return;
	s.push(temp);
	while(!s.isEmpty())
	{
		struct node *t=s._top_();
		s.pop();
		cout<<t->data<<" ";
		if(t->right)
			s.push(t->right);
		if(t->left)
			s.push(t->left);		
	}
}
static void postorder(struct node *temp)
{
	_Stack_ s1,s2;
	if(temp==NULL)
		return;
	s1.push(temp);
	while(!s1.isEmpty())
	{
		struct node *t=s1._top_();
		s1.pop();
		s2.push(t);
		if(t->left)
			s1.push(t->left);
		if(t->right)
			s1.push(t->right);	
	}
	while(!s2.isEmpty())
	{
		struct node *t=s2.pop();
		cout<<t->data<<" ";			
	}
}
class _Tree_
{
	public:
	struct node *root;
	_Tree_()
	{
		root=NULL;
	}
	void insert(int data)
	{
		struct node* temp;
		struct node* par;
		temp=root;
		par=NULL;
		if(temp==NULL)
		{
			root=create_node(data);	
		}
		else 
		{
			while(temp!=NULL)
			{
				par=temp;
				if(temp->data>data)
				{
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
				}					
			}
			if(par->data>data)
				par->left=create_node(data);
			else
				par->right=create_node(data);			
		}	
	}
	
	void display()
	{
		preorder(root);
		cout<<endl;
		inorder(root);
		cout<<endl;
		postorder(root);
		cout<<endl;		
	}
};

int main()
{
	_Tree_ T;
	do
	{
		cout<<"press 1 to insert"<<endl;
		cout<<"press 2 to display all order"<<endl;
		cout<<"press 6 to exit"<<endl;
		int n;
		cin>>n;
		switch(n)
		{
			int data;
			case 1:cout<<"enter the data"<<endl;
				cin>>data;
				T.insert(data);
				break;
			case 2:T.display();				
				break;
			case 6:exit(0);
		}
	}while(1);
}
