class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>indices;
        for(int i=0;i<nums.size();i++){
            indices.push_back({nums[i],i});
        }
        sort(indices.begin(), indices.end());
        int left=0, right=nums.size()-1;
        while(left<right){
            int sum=indices[left].first + indices[right].first;
            if(sum==target){
                return {indices[left].second, indices[right].second};
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {-1, -1};
    }
};