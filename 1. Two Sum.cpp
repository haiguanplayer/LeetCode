vector<int> a;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        for(int i = 0;i < nums.size();i++)
            a.push_back(nums[i]);
        sort(a.begin(),a.end());*/
        vector<int> a;
        bool flag = false;
        for(int i = 0;i < nums.size()-1;i++)
        {
            for(int j = i+1;j < nums.size();j++)
                if(nums[i] + nums[j] == target)
                {
                    a.push_back(i);
                    a.push_back(j);
                    flag = true;
                    break;
                }
            if(flag)
                break;
        }
        return a;
    }
};
