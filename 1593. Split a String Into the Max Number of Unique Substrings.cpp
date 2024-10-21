class Solution {
public:
    // TC -> O(2^n)
    // SC -> O(n)
    int solve(string s, unordered_set<string> &st, int i){
        // base case
        if(i >= s.length()){
            return 0;
        }

        int ans = -1;
        for(int x = i; x < s.length(); x++){
            int local = 0;
            int len = x-i+1;
            string temp = s.substr(i, len);

            if(!st.count(temp)){
                st.insert(temp);
                local = 1 + solve(s, st, x+1);
                st.erase(temp);
            }
            ans = max(ans, local);
        }
        return ans;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(s, st, 0);
    }
};