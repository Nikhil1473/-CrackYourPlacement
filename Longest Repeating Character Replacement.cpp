class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        map<char, int> mp;
        int maxFreq = 0;
        int ans = 0;
        
        while (r < s.size()) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            r++;
            if (r - l - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};
