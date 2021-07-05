class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>maximums;
        for(int i=0;i<nums.size();i++)
        {
            if(!q.empty() && q.front()<=i-k)
              q.pop_front();
            while(!q.empty() &&nums[q.back()] <=nums[i])
             q.pop_back();
            q.push_back(i);
            if((i+1)>=k)
            maximums.push_back(nums[q.front()]);
        }
        return maximums;
    }
};
