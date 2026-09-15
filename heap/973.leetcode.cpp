class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , pair<int , int>>>pq;

        for(auto & point: points){
            int x = point[0];
            int y = point[1];

            int distance = x*x+y*y;

            pq.push({distance , {x,y}});

            if(pq.size() > k){
                pq.pop();
            }
        }
       vector<vector<int>> ans;

        while(!pq.empty()){
            auto point = pq.top().second;
            ans.push_back({point.first, point.second});

            pq.pop();
        }
        return ans;
    }
};
