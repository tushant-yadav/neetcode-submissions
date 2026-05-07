class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return 0;
        map<int,int> freq;
        for(int i:hand){
            freq[i] ++;
        }
        while(freq.size()!=0){
            auto itr = freq.begin();
            for(int i=itr->first;i<itr->first+groupSize;i++){
                cout<<itr->first<<endl;
                if(freq.find(i)==freq.end()){
                    return 0;
                }
                if(freq[i]==1) freq.erase(i);
                else freq[i]--;
            }
        }
        return 1;        
        
    }
};
