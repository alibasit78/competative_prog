#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b,int m,int n,int dp[][1000]) {
    //cout<<m<<" "<<n<<endl;
     string s1="";
     string s2="";
    if(dp[m][n]!=-1)
    {
        if(dp[m][n]==1)
            return "YES";
        else
            return "NO";
    }
        
if(n==0)
{
    dp[m][n]=1;
    return "YES";
}
if(m==0)
{
    dp[m][n]=0;
    return "NO";
}
if(islower(a.at(m-1))&&toupper(a.at(m-1))==b.at(n-1)||a.at(m-1)==b.at(n-1))
{
    //cout<<a.at(m-1)<<endl;
    string s3=abbreviation(a,b,m-1,n-1,dp);
    if(s3.compare("YES")==0)
    {   
        dp[m][n]=1;
        return "YES";
    }
    else
    {
        s3=abbreviation(a,b,m-1,n,dp);
        if(s3.compare("YES")==0)
        {
            dp[m][n]=1;
            return "YES";
        }
        else{
            dp[m][n]=0;
            return "NO";
        }
    }
}
else if(isupper(a.at(m-1)) && a.at(m-1)!=b.at(n-1))
{
    dp[m][n]=0;
    return "NO";
}
else
{
    s1= abbreviation(a,b,m-1,n,dp);
    //cout<<s1<<endl;
    if(s1.compare("YES")==0){
        //cout<<"hello"<<endl;
        dp[m][n]=1;
        return "YES";
    }
    else
    {
        dp[m][n]=0;
        return "NO";
    }
} 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int dp[1000][1000]={0};
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);
        for(int i=0;i<=a.length();i++)
        {
            for(int j=0;j<=b.length();j++)
            {
                dp[i][j]=-1;
            }
        }    
        string result = abbreviation(a, b,a.length(),b.length(),dp);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
