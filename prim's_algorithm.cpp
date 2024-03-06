class Solution{
    private:
        int findMinNode(vector<int>& key, vector<bool>& mst){
            int mini = INT_MAX;
            int index = -1; // represents actual node having min. value
            for(int i=0; i<key.size(); i++){
                if(!mst[i] && key[i] < mini){
                    mini = key[i];
                    index = i;
                }
            }
            return index;
        }
        
        public:
        //Function to find sum of weights of edges of the Minimum Spanning Tree.
        int spanningTree(int V, vector<vector<int>> adj[])
        {
            // PRIM'S ALGORITHM
            
            vector<int> key(V, INT_MAX);
            vector<bool> mst(V, false); // keeps track of nodes added in mst
            vector<int> parent(V, -1); // stores final mst relations
            
            key[0]=0;
            
            while(true){
                // step 1 -> find Min value node
                int u = findMinNode(key, mst);
                
                if(u == -1){
                    // means all nodes are added successfully that's why function retured -1
                    break;
                }
                
                //step2 -> mark node in mst as true
                mst[u] = true;
                
                for(auto edge: adj[u]){
                    int v = edge[0];
                    int w = edge[1];
                    
                    if(!mst[v] && w < key[v]){
                        key[v] = w;
                        parent[v] = u;
                    }
                }
            }
            int sum = 0;
            for(int i: key){
                sum+=i;
            }
            return sum;
        }
};        