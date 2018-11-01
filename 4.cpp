class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> v;
        int cnt = 0;
        int p1 = 0,p2 = 0;
        while(cnt < (m+n)/2+1){
            if(p1 < m && p2 < n){
                if(nums1[p1] > nums2[p2])
                    v.push_back(nums2[p2++]),cnt++;
                else
                    v.push_back(nums1[p1++]),cnt++; 
            }
            else if(p1 < m)
                v.push_back(nums1[p1++]),cnt++; 
            else if(p2 < n)
                v.push_back(nums2[p2++]),cnt++;
        }
        if((m+n)&1)
            return (double)v.back();
        else{
            int tmp = v.back();
            v.pop_back();
            return (double)(tmp+v.back())/2.0;
        }
    }
};
