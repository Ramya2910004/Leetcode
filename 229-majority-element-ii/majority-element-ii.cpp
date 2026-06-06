class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1 =0, count2=0;
        int ele1, ele2;
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=ele2){
               count1=1;
               ele1=nums[i];
            }
             else if(count2==0 && nums[i]!=ele1){
               count2=1;
               ele2=nums[i];
            }
            else if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int c1=0, c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                c1++;
            }
            else if(nums[i]==ele2){
                c2++;
            }
        }
        int a = n/3+1;
        vector<int> result; 
        if (c1 >= a) {
            result.push_back(ele1);
        }
        if (c2 >= a && ele1 != ele2) {
            result.push_back(ele2); 
        }
        return result;
    }
};