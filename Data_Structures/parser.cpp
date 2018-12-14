// CPP program to check for balanced parenthesis.
#include<bits/stdc++.h>
using namespace std;
 
// function to check if paranthesis are balanced
string removeComments(string prgm) 
{ 
    int n = prgm.length(); 
    string res; 
  
    // Flags to indicate that single line and multpile line comments 
    // have started or not. 
    bool s_cmt = false; 
    bool m_cmt = false; 
  
  
    // Traverse the given program 
    for (int i=0; i<n; i++) 
    { 
        // If single line comment flag is on, then check for end of it 
        if (s_cmt == true && prgm[i] == '\n') 
            s_cmt = false; 
  
        // If multiple line comment is on, then check for end of it 
        else if  (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/') 
            m_cmt = false,  i++; 
  
        // If this character is in a comment, ignore it 
        else if (s_cmt || m_cmt) 
            continue; 
  
        // Check for beginning of comments and set the approproate flags 
        else if (prgm[i] == '/' && prgm[i+1] == '/') 
            s_cmt = true, i++; 
        else if (prgm[i] == '/' && prgm[i+1] == '*') 
            m_cmt = true,  i++; 
  
        // If current character is a non-comment character, append it to res 
        else  res += prgm[i]; 
    } 
    return res; 
} 
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;
 
    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
        if(expr[i]==','||expr[i]>='a'&&expr[i]<='z'||expr[i]>='0'&&expr[i]<='9'||expr[i]>=32&&expr[i]<=39||expr[i]=='>'||expr[i]=='<'||expr[i]=='.'||expr[i]=='\n')
            continue;
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.

        if (s.empty())
           return false;
 
        switch (expr[i])
        {
        case ')':
 
            // Store the top element in a
            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }
 
    // Check Empty Stack
    return (s.empty());
}
 
// Driver program to test above function
int main()
{   
    ifstream file("c_prog.c");
    string s,expr="";
    int i=0;
    while(getline(file,s,'\n')){
        expr+=(s+'\n');
    }
    //string expr = "{{((a+b)-(c+d)/(4/3)}[9+8]}=a";
    string s2=removeComments(expr);
    cout <<s2; 
    if (areParanthesisBalanced(s2))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}