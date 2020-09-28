#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isBalanced(string s) {
  stack<char> st;
  char ch;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
      continue;
    }

    if (s.empty())
      return false;

    switch (s[i]) {
    case ')':
      ch = st.top();
      st.pop();
      if (ch == '{' || ch == '[')
        return false;
      break;
    case '}':
      ch = st.top();
      st.pop();
      if (ch == '(' || ch == '[')
        return false;
      break;
    case '[':
      ch = st.top();
      st.pop();
      if (ch == '{' || ch == '(')
        return false;
      break;
    default:
      return false; 
    }
}
return st.empty();
}

int main(){
    string str = "[{()}()]";
    if(isBalanced(str))
      cout<<"Balanced";
    else
     cout<<"Not Balanced";  
}