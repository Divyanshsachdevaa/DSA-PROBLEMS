/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long> pq;

        while(!q.empty()){
            int s = q.size();
            long long currSum = 0;
            for(int i = 0; i<s; i++){
                TreeNode* temp = q.front();
                q.pop();

                currSum += temp->val;
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
            pq.push(currSum);
        }

        if(pq.size() < k){
            return -1;
        }

        long long ans = 0;

        while(k--){
            ans = pq.top();
            pq.pop();
        }

        return ans;
        // TC -> O(n log n)
        // SC -> O(n)
    }
};