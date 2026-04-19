class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            string token = tokens[i];
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                switch(tokens[i][0]) {
                    case '+':
                        stk.push(a+b);
                        break;
                    case '-':
                        stk.push(a-b);
                        break;
                    case '*':
                        stk.push(a*b);
                        break;
                    case '/':
                        stk.push(a/b);
                        break;        
                }
                continue;
            }
            stk.push(stoi(token));
        }
        return stk.top();
    }
};
