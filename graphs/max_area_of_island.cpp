class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {


        vector<vector<int>> grid_mapped_by_island;

        int nr_of_current_island=1;

        queue<pair<int,int>> island_search;
        int max_area=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    nr_of_current_island++;
                    int current_area=1;
                    grid[i][j]=nr_of_current_island;
                    pair<int,int>coordinate={i,j};
                    island_search.push(coordinate);
                    while(!island_search.empty()){
                        coordinate=island_search.front();
                        island_search.pop();
                        pair<int,int> new_coordinates=coordinate;
                        
                        if(coordinate.first-1>=0){
                            if(grid[coordinate.first-1][coordinate.second]==1){
                                current_area++;
                                grid[coordinate.first-1][coordinate.second]=nr_of_current_island;
                                new_coordinates={coordinate.first-1,coordinate.second};

                                island_search.push(new_coordinates);
                            }
                        }

                        if(coordinate.first+1<grid.size()){
                            if(grid[coordinate.first+1][coordinate.second]==1){
                                current_area++;
                                grid[coordinate.first+1][coordinate.second]=nr_of_current_island;
                                new_coordinates={coordinate.first+1,coordinate.second};

                                island_search.push(new_coordinates);
                            }
                        }

                        if(coordinate.second-1>=0){
                            if(grid[coordinate.first][coordinate.second-1]==1){
                                current_area++;
                                grid[coordinate.first][coordinate.second-1]=nr_of_current_island;
                                new_coordinates={coordinate.first,coordinate.second-1};

                                island_search.push(new_coordinates);
                            }
                        }


                        if(coordinate.second+1<grid[i].size()){
                            if(grid[coordinate.first][coordinate.second+1]==1){
                                current_area++;
                                grid[coordinate.first][coordinate.second+1]=nr_of_current_island;
                                new_coordinates={coordinate.first,coordinate.second+1};

                                island_search.push(new_coordinates);
                            }
                        }



                        
                    }

                    if(current_area>max_area){
                        max_area=current_area;
                    }

             }
            }
        }


        for(auto x:grid){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<'\n';
        }

        return max_area;
        
    }
};
