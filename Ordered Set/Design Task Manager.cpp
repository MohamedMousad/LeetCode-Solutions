class TaskManager {
private:
    priority_queue<tuple<int, int ,int>> todo;
    unordered_map<int ,pair<int, int>> task_data;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++)
            add(tasks[i][0], tasks[i][1], tasks[i][2]);
    }
    void add(int userId, int taskId, int priority) {
        task_data[taskId] = { priority , userId};
        todo.push({ priority , taskId , userId });
    }

    void edit(int taskId, int newPriority) {
        task_data[taskId].first = newPriority;
        todo.push({ newPriority , taskId , task_data[taskId].second });
    }
    void rmv(int taskId) {
        task_data[taskId].first = -1;
    }
    int execTop() {
        while (!todo.empty()) {
            auto[priority , taskId , userId] = todo.top();
            pair<int,int> curr = { priority , userId} ;
            todo.pop();
            if ( task_data[taskId] == curr ){
                task_data[taskId].first = -1;
                return userId;
            }
        }
        return -1;
    }
};
/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */