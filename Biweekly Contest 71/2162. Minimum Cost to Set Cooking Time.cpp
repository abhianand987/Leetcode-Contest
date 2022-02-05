//Observation of question only two options and also 2nd option only under special case i.e, when we can subtract 40.
class Solution {
public:
    #define trace2(x,y) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
    int push,move;
    int util(int sec,int start){
        int ans = 0;
        string s = to_string(sec);
        
        for(auto x : s){
            int dig = x-'0';
            //trace2(ans,start);
            if(dig != start){
                    ans += (move+push);
                    start = dig;
               }
                else ans += push;
              }
        return ans;
     }
    int minCostSetTime(int start, int moveCost, int pushCost, int sec){
       
        move=moveCost,push=pushCost;
        int op1 = (sec/60)*100 + (sec % 60);
        int op2 = 10000;
        if(sec % 60 <= 39) op2 = op1 - 40;
        //cout<<op1<<" "<<op2<<endl;
        int ans = INT_MAX;
        //trace2(op1,op2);
        if(op1 <= 9999) ans = min(ans,util(op1,start));
        if(op2 <= 9999) ans = min(ans,util(op2,start));
        
        return ans;
        
        
        
    }
};
