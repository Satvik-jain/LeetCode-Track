class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mpp;
    TimeMap() {
        mpp.clear();
    }
    
    void set(string key, string value, int time) {
        if (mpp.find(key) == mpp.end()) mpp[key] = {};
        mpp[key].push_back({value, time});
    }
    
    string get(string key, int time) {
        if (mpp.find(key) == mpp.end()) return "";
        auto &data = mpp[key];
        int i = 0, j = data.size()-1;
        string val = "";
        while(i <= j){
            int mid = (i+j)/2;
            if (data[mid].second <= time){
                val = data[mid].first;
                i = mid+1;
            }
            else {
                j = mid-1;
            }
        }
        return val;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */