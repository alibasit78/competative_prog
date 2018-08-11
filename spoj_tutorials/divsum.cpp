#include <iostream>
#include <vector>
#include <math.h>
# define ll long long int
#define MOD 1000000007
using namespace std;
vector<int> temp(500001,1);
vector<int> prime;
ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
int _prime(int n)
{
	if(n<=1)
		return 0;
	if(n==2)
		return 1;
	if(n%2==0)
		return 0;
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return 0;
	return 1;
}
int preprocess_prime(int n)
{
	temp[0]=0,temp[1]=0;
	for(int i=2;i*i<=n;i++)
	{
		if(_prime(i))
			for(int k=i*i;k<n;k=k+i)
			{
				temp[k]=0;
			}
	}
}
int main()
{
	int t,n;
	cin>>t;
	preprocess_prime(500000);
	prime.push_back(2);
	for(int i=3;i<=500000;i+=2)
	{
		if(temp[i]==1)
		prime.push_back(i);
	}
	vector<int> :: iterator x;
	/*for(x=prime.begin();x!=prime.end();++x)
	{
		cout<<*x<<endl;
	}*/
	vector< pair<int,int> > v;
	pair<int,int> pp;
	while(t--)
	{
		cin>>n;
		int temp=n;
		int ind=0,f=0;
		while(1)
		{
			int count=0;
			if(temp==1)
				break;
			while(temp % prime[ind]==0)
			{
				count++;
				temp=temp/ prime[ind];
			}
			if(count!=0){
			pp.first=prime[ind];
			pp.second=count;
			v.push_back(pp);
			}
			ind++;
		}
		long long int mul=1;
		for(vector<pair<int,int> >::iterator it=v.begin();it!=v.end();it++)
		{
			//cout<<it->first<<" "<<it->second<<endl;
			mul*=(fast_exp(it->first,it->second+1)-1)/(it->first-1);
		}
		if(n==1)
			cout<<"0"<<endl;
		else
			cout<<mul-n<<endl;
		v.clear();		
	}
}