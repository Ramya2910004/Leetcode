class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int max_len=0;
        int l=0,r=0;
        while(r<n){
            if(nums[r]==0){
                count++;
            }
            if(count>k){
                if(nums[l]==0)
                {
                  count--;
                }
                l++;
            }
            max_len=max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};