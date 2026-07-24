class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]==0){arr.push_back(1);}
        }
        int ind = n-1;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[ind]!=0){arr[i]=arr[ind]; ind--;}
            else if(arr[ind]==0){arr[i]=0; arr[i-1]=0; i--; ind--;}
        }
        arr.erase(arr.begin()+n,arr.begin()+arr.size());
    }
};