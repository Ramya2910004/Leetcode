class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int s=0,c=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s==k){
              c++;
            }
            int d=s-k;
            if(mp.find(d)!=mp.end()){
                c+=mp[d];
            }
            mp[s]++;
        }
        return c;
    }
};