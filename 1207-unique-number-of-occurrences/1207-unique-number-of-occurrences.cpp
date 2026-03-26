class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // saare elments ko map me daal diya 
        int n=arr.size(); 
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }

        //now ek new set bana kar usme map ka second vlue daal diya 

        unordered_set<int>s;
        for(auto x : m){
            int frequency =x.second;
            if(s.find(frequency)!=s.end()) return false; //agar set me pehle se wo elements hain then return false ;
            else s.insert(frequency); // agar wo elements nahi hain then usko set me insert kar do;

        }

        return true;
        
    }
};