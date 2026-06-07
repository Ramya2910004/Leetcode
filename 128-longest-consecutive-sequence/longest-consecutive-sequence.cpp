class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int longest=1;
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                int count=1;
                int a=i;
                while(s.find(a+1)!= s.end()){
                    a=a+1;
                    count++;
                }
                longest=max(count, longest);
            }
        }
        return longest;
    }
};