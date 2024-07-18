
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long minProduct = 1;
        long long maxProduct = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(static_cast<long long>(nums[i]), maxProduct * nums[i]);
            minProduct = min(static_cast<long long>(nums[i]), minProduct * nums[i]);
            ans = max(ans, static_cast<int>(maxProduct));

            // Prevent potential overflow in subsequent iterations
            if (maxProduct > INT_MAX) maxProduct = INT_MAX;
            if (minProduct < INT_MIN) minProduct = INT_MIN;
        }

        return ans;
    }
};
