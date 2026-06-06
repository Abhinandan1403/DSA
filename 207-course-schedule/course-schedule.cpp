class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        for(int i = 0 ; i<prerequisites.size() ; i++ ){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int>q ;
        for(int i = 0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int topo = 0 ;
        vector<int>topov;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo++;
            topov.push_back(node);

            for(auto nbr : adj[node]){
                indegree[nbr]--;

                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        for(auto it : topov){
            cout << it << " " ;
        }

        return topo == numCourses ;
    }
};