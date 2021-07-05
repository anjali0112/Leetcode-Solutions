class Solution {
public:
      map<int,int>m;
     vector<int>unique;
    int partition(int l,int r)
    {
        int pivot=unique[r];
        int start=l-1;
        for(int i=l;i<r;i++)
        {
            if(m[unique[i]] < m[pivot])
                start++,swap(unique[i],unique[start]);
        }
        swap(unique[r],unique[start+1]);
        return start+1;
        
    }
    
    int quickSelect(int l,int r,int kSmallest)
    {
        if(r>=l)
        {
         int pivot=partition(l,r);
        if(pivot==kSmallest)
        {
         return pivot;
        }
        else if(pivot>kSmallest) return quickSelect(l,pivot-1,kSmallest);
        else return quickSelect(pivot+1,r,kSmallest);
       
        }
        return r;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
           unique.push_back(i.first);
        }
        int n=unique.size();
        int ansStart=quickSelect(0,n-1,n-k);
        
        for(int i=ansStart;i<n;i++)
            ans.push_back(unique[i]);
        return ans;
    }
};
