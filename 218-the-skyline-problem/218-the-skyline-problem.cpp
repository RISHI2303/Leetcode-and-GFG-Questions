class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>> skyPoints; 
        for (int i=0; i<buildings.size(); i++){    
            int x=buildings[i][0];
            int y=buildings[i][1];
            int h=buildings[i][2];
            
            skyPoints.push_back( make_pair(x,-1*h) );  //-ve height for start of building
            skyPoints.push_back( make_pair(y,h) );     //+ve height for end of building
        }
        sort(skyPoints.begin(), skyPoints.end(), sortFunc); // start and end points of buildings in asc order
        
        map<int,int> heights; // used as maxheap or priority queue  and implemented using map  
                              //bcoz its keys are sorted & direct deletion of any key possible
        
        heights[0]=1; // at begin height is zero and also end height is zero
        int maxHeight=0;
        vector<vector<int>> ans;
        
        for (int i=0;i<skyPoints.size();i++){
            
            int h=skyPoints[i].second;
            int x=skyPoints[i].first;
            
            if (skyPoints[i].second < 0){ // handling start of buidling case
                
                heights[-1* h]++;
                if (maxHeight!=heights.rbegin()->first){ //change in height
                    maxHeight=heights.rbegin()->first; //last key in map will have max height 
                    ans.push_back(vector<int>{x,maxHeight}); 
                }
            }else{ // handling end of buidling case
                
                heights[h]--;
                if (heights[h]==0){
                    heights.erase(skyPoints[i].second);
                }
                if (maxHeight!=heights.rbegin()->first){ //change in height
                    maxHeight=heights.rbegin()->first;
                    ans.push_back(vector<int>{x,maxHeight});
                }
            }
            
        }
        return ans;
    }
    

    static bool sortFunc( pair<int,int>& a, pair<int,int>& b){
        if (a.first==b.first){
            return (a.second<b.second);
        }else{
            return (a.first<b.first);
        }
    }
};