class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        vector<pair<int,int>> movement;
        movement.push_back({-1,0});
        movement.push_back({1,0});
        movement.push_back({0,-1});
        movement.push_back({0,1});
        


        queue<pair<int,int>> coordinate_queue;



        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    pair<int,int> coordinate={i,j};
                    int current_index=2;
                    coordinate_queue.push(coordinate);

                    while(!coordinate_queue.empty()){
                      pair<int,int>current_coordinates=coordinate_queue.front();
                      coordinate_queue.pop();
                      current_index=grid[current_coordinates.first][current_coordinates.second];

                      for(auto x:movement){
                        if(current_coordinates.first+x.first>=0&&current_coordinates.first+x.first<grid.size()&&current_coordinates.second+x.second>=0&&current_coordinates.second+x.second<grid[current_coordinates.first].size()){
                            if(grid[current_coordinates.first+x.first][current_coordinates.second+x.second]==1||grid[current_coordinates.first+x.first][current_coordinates.second+x.second]>current_index+1){
                                grid[current_coordinates.first+x.first][current_coordinates.second+x.second]=current_index+1;
                                pair<int,int>new_coordinates={current_coordinates.first+x.first,current_coordinates.second+x.second};
                                coordinate_queue.push(new_coordinates);
                            }
                        }
                      }
                      
                    }


                }
            }


        }
        int minimum=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;

                }
                if(grid[i][j]>minimum){
                    minimum=grid[i][j];
                }

        }}
        return minimum-2;
        
    }
};
