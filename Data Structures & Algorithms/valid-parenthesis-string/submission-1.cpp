class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if(n==0) return 1;

        stack<int> left;
        stack<int> star;
        for(int i=0;i<n;i++){
            if(s[i] == '(') {
                left.push(i);
            }
            else if(s[i]=='*') {
                star.push(i);
            }
            else{
                if(left.size()>0) left.pop();
                else if(star.size()>0) star.pop();
                else return 0;
            }
            cout<<left.size()<<":"<<star.size()<<endl;
        }
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) {
                return false; // Star is behind the '('
            }
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
