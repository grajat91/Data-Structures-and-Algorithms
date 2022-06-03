/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].*/

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> course_graph;
        int indegree_course[numCourses];
        vector<int> result;
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
            result.push_back(u);
            count++;
            for (int i=0;i<course_graph[u].size();i++) {
                indegree_course[course_graph[u][i]]--;
                if (indegree_course[course_graph[u][i]] == 0) zero_indegree_q.push(course_graph[u][i]);
            }
        }
        reverse(result.begin(), result.end());
        if (count == numCourses) return result;
        else {
            result.clear();
            return result;
        }
    }

