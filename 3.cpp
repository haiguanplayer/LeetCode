class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            map<char,int> mp;
            mp.clear();
            int len = s.size();
            int maxn = 0,tmp = 0;
            for(int i = 0;i < len;){
                if(mp[s[i]]){
                    maxn = max(maxn,tmp);
                    i = mp[s[i]];//cout<<"DSF"<<i<<endl;
                    tmp = 0;
                    mp.clear();
                }
                else{
                    mp[s[i]] = i+1;
                    //cout<<i<<endl;
                    tmp++;
                    i++;
                }
            }
            maxn = max(maxn,tmp);
            return maxn;
    }
};
