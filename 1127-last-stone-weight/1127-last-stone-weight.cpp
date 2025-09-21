class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(), stones.end()); //max-heap
        while(!pq.empty()){
            int fl=pq.top(); pq.pop();
            if(pq.empty()){
                return fl;
            } else{
                int sl= pq.top(); pq.pop();
                int diff= abs(fl-sl);
                if(diff !=0) pq.push(diff);  
            }
        }
        return 0;
    }
};