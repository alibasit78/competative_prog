#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
struct q_node
{
	int data;
	struct q_node *next;
};
static struct node* create_node(int data)
{
	struct node* new_node=new node;
	new_node->data=data;
	new_node->left=new_node->right=NULL;
	return new_node;
}
/*static struct q_node* create_q_node(int data)
{
	struct q_node* new_node=new q_node;
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}*/
static void preorder(struct node *temp)
{
	if(temp==NULL)
		return;
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}
static struct node* min_node(struct node *temp)
{
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;	

}
/*class _Queue_
{
	public:
	struct q_node *front,*rear;
	_Queue_()
	{
		front=rear=NULL;		
	}
	void enque(int data)
	{
		if(rear==NULL)
			front=rear=create_q_node(data);
		else
		{
			rear->next=create_q_node(data);
			rear=rear->next;
		}	
	}
	int deque()
	{
		if(front==NULL)
		{
			cout<<"underflow"<<endl;
			return -1;
		}	
		else
		{
			int x=front->data;
			struct q_node* temp;
			temp=front;
			front=front->next;
			return x;			
		}	
	}
	int size()
	{
		int n=0;
		struct q_node* temp;
		temp=front;
		while(temp!=NULL)
		{
			n++;
			temp=temp->next;	
		}
		return n;			
	}
	int front()
	{
		return front->data;
	}	
};*/
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
	void del(int data)
	{
		struct node* temp;
		struct node* par;
		par=NULL;temp=root;
		LOOP:while(temp!=NULL&&temp->data!=data)
		{
			par=temp;
			if(temp->data>data)
				temp=temp->left;
			else
				temp=temp->right;				
		}
		if(temp==NULL)
		{
			cout<<"element is not present"<<endl;		
		}
		else if(temp->left==NULL&&temp->right==NULL&&par==NULL)
		{
			root=NULL;
			free(temp);		
		}
		else if(temp->right==NULL&&par==NULL)
		{
			root=temp->left;
			free(temp);
		}
		else if(temp->left==NULL&& par==NULL)
		{
			root=temp->right;
			free(temp);
		}
		else if(temp->left==NULL)
		{
			if(par->data>data)
			{
				par->left=temp->right;
			}
			else
				par->right=temp->right;
			free(temp);
		}
		else if(temp->right==NULL)
		{
			if(par->data>data)
			{
				par->left=temp->left;
			}
			else
				par->right=temp->left;
			free(temp);
		}
		else
		{
			int t2;
			struct node *t;
			t=min_node(temp->right);	
			t2=temp->data;
			temp->data=t->data;
			t->data=t2;
			par=temp;
			temp=temp->right;
			if(temp->left==NULL&&temp->right==NULL&&par!=NULL)
				par->right=NULL;
			else
			{
				par=NULL;
				goto LOOP;
			}			
		}			
	}
	void display()
	{
		preorder(root);
		cout<<endl;		
	}
	void search(int data)
	{
		struct node* temp;
		temp=root;
		while(temp!=NULL&&temp->data!=data)
		{
			if(temp->data>data)
				temp=temp->left;
			else
				temp=temp->right;				
		}
		if(temp==NULL)
			cout<<"element is not present"<<endl;
		else
			cout<<"element is present"<<endl;				
	}
};
int height(struct node* temp)
{
	int n,ht=0;
	if(temp==NULL)
		return 0;
	list<struct node*> q;
	q.push_back(temp);
	while(1)
	{
		
		n=q.size();
		//cout<<n<<endl;
		if(n==0)
			break;
		ht++;
		while(n>0)
		{	
			struct node* x=q.front();
			//cout<<x->data<<" "<<x->left->data<<" "<<x->right->data<<endl;
			q.pop_front();
			//cout<<"node content "<<x->data<<endl;
			if(x->left!=NULL)
				q.push_back(x->left);
			if(x->right!=NULL)
				q.push_back(x->right);
			n--;
		}
	}
	return ht;
}
int main()
{
	_Tree_ T;
	do
	{
		cout<<"press 1 to insert"<<endl;
		cout<<"press 2 to display"<<endl;
		cout<<"press 3 to delete"<<endl;
		cout<<"press 4 to search"<<endl;
		cout<<"press 5 to find height"<<endl;
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
			case 3:cout<<"enter the element to delete"<<endl;	
				cin>>data;
				T.del(data);
				break;
			case 4:cout<<"enter the element to search"<<endl;
				  cin>>data;
				T.search(data);
				break;
			case 5:cout<<height(T.root)-1<<endl;
				break;
			case 6:exit(0);
		}
	}while(1);
}
