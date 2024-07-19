    int prefixSum = 0;
        int len = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            
            if (arr[i] == 0 && len == 0) {
                len = 1;
            } else if (prefixSum == 0) {
                len = i + 1;
            } else if (mp.find(prefixSum) != mp.end()) {
                len = max(len, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i;
            }
        }

        return len;
    }
