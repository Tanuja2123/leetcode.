class Router {
public:
    queue<tuple<int , int , int>> q;
    set<tuple<int , int , int>> st;
    unordered_map<int, vector<int>> destMap; 
    int memoryLimit;

    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> packet = {source, destination, timestamp};
        if (st.find(packet) != st.end()) {
            return false; 
        }
       
        if (q.size() >= memoryLimit) {
            auto old = q.front();
            q.pop();
            st.erase(old);
            int oldDst = get<1>(old);
            int oldTs  = get<2>(old);

         
            auto &vec = destMap[oldDst];
            auto it = lower_bound(vec.begin(), vec.end(), oldTs);
            if (it != vec.end() && *it == oldTs) {
                vec.erase(it);
            }
        }

        q.push(packet);
        st.insert(packet);

      
        auto &vec = destMap[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [sr, ds, ts] = q.front();
        q.pop();
        st.erase({sr, ds, ts});

        // erase exact timestamp
        auto &vec = destMap[ds];
        auto it = lower_bound(vec.begin(), vec.end(), ts);
        if (it != vec.end() && *it == ts) {
            vec.erase(it);
        }

        return {sr, ds, ts};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destMap.find(destination);
        if (it == destMap.end() || it->second.empty())
            return 0;

        auto &vec = it->second;
        int i = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin(); //lower index for the valid ans
        int j = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin(); // higher indx for valid ans
        return j - i; //ans
    }
};

