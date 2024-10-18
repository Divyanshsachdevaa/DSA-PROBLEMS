//----------------------------APPROACH 1----------------------------

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, int temp, int i, int maxOR, int& count){
        // base case
        if(i >= nums.size()){
            return ;
        }

        // include
        int include = (temp | nums[i]);
        if(include == maxOR){
            count++;
        }
        solve(nums, include, i+1, maxOR, count);
            
        // exclude
        solve(nums, temp, i+1, maxOR, count);
    }    

public:
    int countMaxOrSubsets(vector<int>& nums) {
        // WHAT DOES OR MEANS ?
        // once a bit is set to 1 it stays 1 so in order to calc max OR we have to OR max possible numbers
        int maxOR = 0;
        for(int i: nums){
            maxOR |= i;
        }

        // now whichever subset matches this or increase its count
        int count = 0;
        
        solve(nums, 0, 0, maxOR, count);
        return count;
        // TC -> O(2^n)
        // SC -> O(n) recurssion stack space
    }
};


//----------------------------APPROACH 2----------------------------

class Solution {
private:
    int solve(vector<int>& nums, int temp, int i, int maxOR, vector<vector<int>>& dp){
        // base case
        if(i >= nums.size()){
            return temp == maxOR ? 1 : 0;
        }

        if(dp[temp][i] != -1){
            return dp[temp][i];
        }

        // include
        int include = solve(nums, temp | nums[i], i+1, maxOR, dp);
            
        // exclude
        int exclude = solve(nums, temp, i+1, maxOR, dp);

        return dp[temp][i] = include + exclude;
    }    

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int i: nums){
            maxOR |= i;
        }
        vector<vector<int>> dp(maxOR+1, vector<int> (nums.size()+1, -1));

        int count = 0;
        
        return solve(nums, 0, 0, maxOR, dp);
        // TC -> O(n * maxOR)
        // SC -> O(n * maxOR)
    }
};