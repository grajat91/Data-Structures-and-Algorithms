/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.*/

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> course_graph;
        int indegree_course[numCourses];
        
        for (int i=0;i<numCourses;i++) {
            indegree_course[i] = 0;
        }
        
        int count=0;
        queue<int> zero_indegree_q;
        
        for (int i=0; i < prerequisites.size(); i++) {
            course_graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree_course[prerequisites[i][1]]++;
        }
        
        for (int i=0;i<numCourses;i++) {
            if (indegree_course[i] == 0) zero_indegree_q.push(i);
        }
        while (!zero_indegree_q.empty()) {
            int u = zero_indegree_q.front();
            zero_indegree_q.pop();
            count++;
            for (int i=0;i<course_graph[u].size();i++) {
                indegree_course[course_graph[u][i]]--;
                if (indegree_course[course_graph[u][i]] == 0) zero_indegree_q.push(course_graph[u][i]);
            }
        }
        return (count == numCourses);
    }
