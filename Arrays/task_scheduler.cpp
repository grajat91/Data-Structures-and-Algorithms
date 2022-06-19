/*Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A*/

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> frequency_of_elements;
        int size = tasks.size();
        
        for (int i=0;i< size;i++) {
            frequency_of_elements[tasks[i]]++;
        }
        
        int maxim = 0;
        int num_of_max = 0;
        for (auto it : frequency_of_elements) {
            if (it.second == maxim) {
                num_of_max++;
            } else if (it.second > maxim) {
                maxim = it.second;
                num_of_max=1;
            }
        }
    
        int partcount = maxim - 1;
        int empty_slots = max(0, (n - num_of_max + 1) * partcount);
        int final_empty_slots = max((empty_slots - (size - (num_of_max*maxim))), 0);
        int total_cycles = tasks.size() + final_empty_slots;
        return total_cycles;
    }
