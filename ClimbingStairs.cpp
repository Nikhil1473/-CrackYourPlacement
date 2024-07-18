class Solution {
public:
int helper(int n,int i,vector<int>& memo){
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    if(memo[i]!=-1){
        return memo[i];
    }
    int onestep=helper(n,i+1,memo);
    int twostep=helper(n,i+2,memo);

    return memo[i]=onestep+twostep;

}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,0,dp);
    }
};