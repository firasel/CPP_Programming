#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

int precisionCal(char c)
{
    if(c == '^') return 3;
    else if(c=='/' || c=='*') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixToPrefix(string chk)
{
    reverse(chk.begin(), chk.end());
    Stack<char> st;
    string result;

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i] >= '0' && chk[i] <= '9') result+=chk[i];
        else if(chk[i]==')') st.push(chk[i]);
        else if(chk[i]=='(')
        {
            while(!st.empty() && st.Top()!=')') result+=st.pop();
            if(!st.empty()) st.pop();
        }
        else
        {
            while(!st.empty() && precisionCal(st.Top())>=precisionCal(chk[i])) result+=st.pop();
            st.push(chk[i]);
        }
    }

    while(!st.empty()) result+=st.pop();

    reverse(result.begin(), result.end());
    return result;
}

int prefixEvaluation(string prefixStr)
{
    Stack<int> st;
    for(int i=prefixStr.length()-1; i>=0; i--)
    {
        switch(prefixStr[i])
        {
        case '+':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a+b);
            break;
        }
        case '-':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a-b);
            break;
        }
        case '*':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a*b);
            break;
        }
        case '/':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a/b);
            break;
        }
        case '^':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(pow(a,b));
            break;
        }
        default :
        {
            st.push(prefixStr[i]-'0');
            break;
        }
        }
    }
    return st.Top();
}

int main()
{
    cout<<prefixEvaluation("-+7*45+20")<<endl;
    cout<<prefixEvaluation("+*423")<<endl;
    string prefix = infixToPrefix("(7+(4*5))-(2+0)");
    cout<<prefix<<endl<<prefixEvaluation(prefix)<<endl;

    return 0;
}

