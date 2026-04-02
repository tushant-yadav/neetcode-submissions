class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i=0;i<n;i++){
            switch(s[i]){
                case '{':
                    stk.push(s[i]);
                    break;
                case '(':
                    stk.push(s[i]);
                    break;                    
                case '[':
                    stk.push(s[i]);
                    break;
                case '}':
                    if(stk.size()>0 &&stk.top()=='{'){
                        stk.pop();
                        break;
                    }
                    return 0;
                case ')':
                    if(stk.size()>0 && stk.top()=='('){
                        stk.pop();
                        break;
                    }
                    return 0;
                case ']':
                    if(stk.size()>0 && stk.top()=='['){
                        stk.pop();
                        break;
                    }
                    return 0;
            }
        }
        if(stk.size()!=0){
            return 0;
        }
        return 1;
    }
};
