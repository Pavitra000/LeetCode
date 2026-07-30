class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> stack;

        for (int i=n-1; i>=0; i--) {
            while (!stack.empty() && stack.top() < heights[i]) {
                ans[i]++;
                stack.pop();
            }
            if (!stack.empty())
                ans[i]++;
            stack.push(heights[i]);
        }
        return ans;
    }
};