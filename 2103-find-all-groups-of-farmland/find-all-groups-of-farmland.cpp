class Solution {
public:
   void dfs(vector<vector<int>>& land,int i,int j,  int &r,int &c){
     int m=land.size();
     int n=land[0].size();
     r=max(r,i);
     c=max(c,j);
     land[i][j] = 0;
      int dr[] = {-1, 0, 1, 0};
       int dc[] = {0, 1, 0, -1};
     for(int k=0;k<4;k++){
          int nr = i + dr[k];
         int nc = j + dc[k];
         if(nr >= 0 && nr < m && nc >= 0 && nc < n && land[nr][nc]==1 ){
            dfs(land,nr,nc,r,c);
            
         }

     }
   }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> ans;
        

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(land[i][j] == 1 ) {

                    int r2 = i;
                    int c2 = j;

                    dfs(land, i, j, r2, c2);

                    ans.push_back({i, j, r2, c2});
                }
            }
        }

        return ans;

    }
};