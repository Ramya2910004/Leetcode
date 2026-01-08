class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int pos=nums.size()-1;
        vector<int>res(nums.size());
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                res[pos]=nums[i]*nums[i];
                pos--;
                i++;
            }
            else{
                res[pos]=nums[j]*nums[j];
                pos--;
                j--;
            }
        }
        return res;
    }
};