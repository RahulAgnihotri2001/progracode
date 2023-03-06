class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0;
        int index=0;
        int count=0;
        while(index!=nums.size()){
            if(nums[index]==val){
                index++;
                count++;
                //cout<<"index "<<index<<" count "<<count<<endl;
            }
            else{
                nums[start]=nums[index];
                start++;
                index++;
                //count++;
            }
        }
        int x=nums.size()-count;
        //cout<<x;
        return x;
    }
};