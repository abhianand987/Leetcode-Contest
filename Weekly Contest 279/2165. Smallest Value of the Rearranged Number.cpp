class Solution {
public:
    long long smallestNumber(long long num){
        bool isneg = false;
        if(num < 0){ 
            isneg = true;
            num=abs(num);
        }
        string s = to_string(num);
        
        if(num == 0) return num;
        //This corner case caused your rank to drop to 7k from 3k.
        
        sort(s.begin(),s.end());
        if(!isneg){
           
            if(s[0] == '0'){
                for(int i = 1 ; ;i++){
                    if(s[i] != '0'){
                        swap(s[i],s[0]);
                        break;
                    }
                }
            }
        }
        else{
           reverse(s.begin(),s.end());
        }
       
        long long int res = stoll(s);
        if(isneg) res = -res;
        
        return res;
        
    }
};
