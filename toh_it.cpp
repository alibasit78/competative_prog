#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
class _Stack_
{
public:
	struct node *top;
	_Stack_()
	{
		top=NULL;
	}
	void push(int data)
	{
		struct node *new_node=new node;
		new_node->data=data;
		new_node->next=top;
		top=new_node;
	}
	int pop()
	{
		if(top==NULL)
		{
			return INT_MIN; 
		}
		else
		{
			int temp=top->data;
			struct node *t=top;
			top=top->next;
			free(t);
			return temp;
		}
	}
	void display()
	{
		struct node *temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

};
void tower_display(_Stack_ &src,_Stack_ &dest,_Stack_ &aux)
{
	cout<<"A: ";
	src.display();
	cout<<"B: ";
	dest.display();
	cout<<"C: ";
	aux.display();
}
void movedisplay(int disk,char s,char d)
{
	
	if(disk%2==1)
	cout<<"move the disk "<<disk<<" Clockwise "<<" from "<<s<<" to "<<d<<endl;
	else
	cout<<"move the disk "<<disk<<" AntiClockwise "<<" from "<<s<<" to "<<d<<endl;
}
void moveDisk(_Stack_ &src,_Stack_ &dest,char s,char d)
{
	int topsrc=src.pop();
	int topdest=dest.pop();
	if(topsrc==INT_MIN)
	{
		src.push(topdest);
		movedisplay(topdest,d,s);		
	}
	else if(topdest==INT_MIN)
	{
		dest.push(topsrc);
		movedisplay(topsrc,s,d);
	}
	else if(topsrc>topdest)
	{
		src.push(topsrc);
		src.push(topdest);
		movedisplay(topdest,d,s);
	}
	else
	{
		dest.push(topdest);
		dest.push(topsrc);
		movedisplay(topsrc,s,d);
	}
}
void toh(_Stack_ &src1,_Stack_ &aux1,_Stack_ &dest1,int no_of_disk)
{
	int moves=(1<<no_of_disk)-1;
	char src='A',dest='B',aux='C';
	for(int i=no_of_disk;i>=1;i--)
		src1.push(i);
	if(no_of_disk%2==0)
	{
		char t;
		t=dest;
		dest=aux;
		aux=t;
	}
	/*for(int i=no_of_disk;i>=1;i--)
		dest1.push(i);*/
	for(int i=1;i<=moves;i++)
	{
		if(i%3==1)
		{
			tower_display(src1,dest1,aux1);
			moveDisk(src1,dest1,src,dest);
		}
		else if(i%3==2)
		{
			tower_display(src1,dest1,aux1);
			moveDisk(src1,aux1,src,aux);
		}
		else if(i%3==0)
		{
			tower_display(src1,dest1,aux1);
			moveDisk(dest1,aux1,dest,aux);
		}
	}
	tower_display(src1,dest1,aux1);
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int no_of_disk;
		cin>>no_of_disk;
		_Stack_ src,aux,dest;
		toh(src,aux,dest,no_of_disk);
		cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
	}
}
