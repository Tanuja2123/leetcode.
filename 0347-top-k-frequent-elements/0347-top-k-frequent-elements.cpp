class Solution {
public:
    using p = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        priority_queue<p, vector<p>, greater<p> >pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }

        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }

};