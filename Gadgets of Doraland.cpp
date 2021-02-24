class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<array.size();i++){
            mp[array[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        vector<int>ans;
        while(k--){
            pair<int,int>p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};