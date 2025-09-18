#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    typedef pair<int, int> Task; // (priority, taskId)

    priority_queue<Task> priority_task;        // max-heap {priority, taskId}
    unordered_map<int,int> task_priority;      // taskId -> current priority
    unordered_map<int,int> task_user;          // taskId -> userId

public:
    // Initialize with tasks: [userId, taskId, priority]
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            add(t[0], t[1], t[2]);  // ✅ use add() for consistency
        }
    }
    
    // Add a new task
    void add(int userId, int taskId, int priority) {
        priority_task.push({priority, taskId});
        task_priority[taskId] = priority;
        task_user[taskId] = userId;
    }
    
    // Edit an existing task's priority
    void edit(int taskId, int newPriority) {
        priority_task.push({newPriority, taskId});
        task_priority[taskId] = newPriority;
    }
    
    // Remove a task (invalidate priority, keep user for logs)
    void rmv(int taskId) {
        task_priority[taskId] = -1; // ✅ only mark priority as invalid
    }
    
    // Execute the top-priority task and return its userId
    int execTop() {
        while (!priority_task.empty()) {
            auto [priority, taskId] = priority_task.top();
            priority_task.pop();

            if (priority == task_priority[taskId]) {
                task_priority[taskId] = -1; // ✅ mark as executed
                return task_user[taskId];
            }
        }
        return -1; // no valid tasks left
    }
};
