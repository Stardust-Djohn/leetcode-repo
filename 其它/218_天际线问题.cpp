class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<pair<int, int>> all_points;
        //get all corner points
        for(auto& r : buildings){
            //use negative num to distinguish left and right
            all_points.insert(make_pair(r[0],-r[2]));
            all_points.insert(make_pair(r[1],r[2]));
        }
        multiset<int> heights = {0}; //a multiset to keep all heights at that moment
        vector<int> last_height = {0, 0}; //to keep last height       
        for(auto& e : all_points){
            if(e.second < 0) heights.insert(-e.second); //put left point
            else heights.erase(heights.find(e.second)); //remove right point
            
            //check if the current height is diffrent from the highest one at that moment
            auto max_height = *heights.rbegin(); //逆序迭代器
            if(last_height[1] != max_height){
                //the profile of skyline
                last_height[0] = e.first;
                last_height[1] = max_height;
                ans.push_back(last_height);
            }
        }
        return ans;
    }
};