class Solution {
public:
    void Comb_pair(int index, int target,vector<int>&nums, vector<int>&ans, vector<vector<int>>&comb){
        if(index==nums.size()){
            if(target==0){
                comb.push_back(ans);
            }
            return;
        }
        //picking up
        if(nums[index]<=target){
            ans.push_back(nums[index]);
            Comb_pair(index, target-nums[index],nums,ans,comb);
            ans.pop_back();
        }
        Comb_pair(index+1, target, nums, ans, comb);
    }
    vector<vector<int>> combinationSum(vector<int>&nums, int target) {
       vector<vector<int>>comb;
       vector<int>ans;
       Comb_pair(0,target,nums,ans,comb);
       return comb;
    }
};