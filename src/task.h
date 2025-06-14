#include <iostream>
#include <map>
#include <string>
#pragma once
struct task{
    int id;
    std::string title;
    bool completed = false;
};

class tasks{
private:
    std::map<int, task> id_task;
    void load_tasks(){
        // This function would typically load tasks from a file or database.
        // For this example, we will load it from tasks.txt.

    }
public:
    
    tasks(){
        load_tasks();
    }

    void get_all_task(){
        if (id_task.empty()) {
            std::cout << "No tasks available.\n";
        }
        for (const auto& [id, t] : id_task) {
            std::cout << "ID: " << id << ", Title: " << t.title 
                      << ", Completed: " << (t.completed ? "Yes" : "No") << "\n";
        }
    }
    void add_task(int id, std::string title, bool completed = false){
        task new_task;
        new_task.id = id;
        new_task.title = title;
        new_task.completed = completed;
        // Increment the id for the next task
        id_task[id] = new_task;
    }
};

