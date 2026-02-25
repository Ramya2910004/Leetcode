class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1;
        if(n==1 && nums[0]==target){
            return {0,0};
        }
        while(i<=j){
            if(nums[i]==target && nums[j]==target){
                return {i,j};
            }
            else if(nums[i]!=target){
                i++;
            }
            else if(nums[j]!=target){
                j--;
            }
        }
        return {-1,-1};
    }
};