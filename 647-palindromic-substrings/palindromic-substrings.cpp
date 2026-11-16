class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()==0){return 0;}
        else if(s.length()==1){return 1;}
        else if(s.length()==2 && s[0]==s[1]){return 3;}
        else if(s.length()==2 && s[0]!=s[1]){return 2;}

        int ans = s.length();

        int left = 0;
        int right = 2;
        
        for(int i=1; i<s.length()-1; i++){
            left = i-1;
            right = i+1;
            while(left>=0 && right<s.length()){
                if(s[left]==s[right]){ans++;}
                else{break;}
                left--;
                right++;
            }
        }
        left = 0;
        right = 1;
        for(int i=0; i<s.length(); i++){
            left = i;
            right = i+1;
            while(left>=0 && right<s.length()){
                if(s[left]==s[right]){ans++;}
                else{break;}
                left--;
                right++;
            }
        }
        return ans;
    }
};