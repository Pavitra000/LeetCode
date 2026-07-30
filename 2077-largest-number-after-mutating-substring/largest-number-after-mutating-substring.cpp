class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string current = num;
        string maxi = num;
        int i=0;
        bool flag=0;
        while(i<num.length()){
            if(change[num[i]-48]>=num[i]-48){
                current[i]=change[num[i]-48]+'0';
                i++;
                if(current==num){flag=0;}
                else{flag=1;}
            }
            else{if(flag == 1){maxi = current;break;} else{i++;}}
        }
        maxi= current;
        return maxi;
    }
};