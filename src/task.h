#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <optional>

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
        std::ifstream Readfile("tasks.txt");
        if (!Readfile.is_open()) {
            std::cerr << "Error opening tasks.txt\n";
            return;
        }
        std::string line;
        while (std::getline(Readfile, line)) {
            if (line.empty()) continue; // Skip empty lines
            task t;
            size_t pos = line.find(',');
            if (pos != std::string::npos) {
                t.id = std::stoi(line.substr(0, pos));
                size_t next_pos = line.find(',', pos + 1);
                t.title = line.substr(pos + 1, next_pos - pos - 1);
                t.completed = (next_pos != std::string::npos && line.substr(next_pos + 1) == "true");
                id_task[t.id] = t;
            }
        }
        Readfile.close();
        std::cout << "Tasks loaded successfully.\n";
    }

    void save_tasks(){
        // This function would typically save tasks to a file or database.
        // For this example, we will save it to tasks.txt.
        std::ofstream Writefile("tasks.txt");
        if (!Writefile.is_open()) {
            std::cerr << "Error opening tasks.txt for writing\n";
            return;
        }
        for (const auto& [id, t] : id_task) {
            Writefile << id << "," << t.title << "," << (t.completed ? "true" : "false") << "\n";
        }
        Writefile.close();
        std::cout << "Tasks saved successfully.\n";
    }
public:
    
    tasks(){
        load_tasks();
    }

    void get_all_task(){
        if (id_task.empty()) {
            std::cout << "-=-=-=- You have no tasks! -=-=-=-\n";
        }
        std::cout << "-=-=-=- Your Tasks -=-=-=-\n";
        for (const auto& [id, t] : id_task) {
            std::cout << "ID: " << id << ", Title: " << t.title 
                      << ", Completed: " << (t.completed ? "Yes" : "No") << "\n";
        }
        std::cout << "-=-=-=- End of Tasks -=-=-=-\n";
    }

    void add_task(std::string title, bool completed = false){
        task new_task;
        int id = id_task.size() + 1; // Generate a new id based on the current size
        new_task.id = id;
        new_task.title = title;
        new_task.completed = completed;
        id_task[id] = new_task;
        save_tasks();
    }

    std::optional<task> get_task(int id){
        if (id_task.find(id) == id_task.end()) {
            std::cerr << "Task with ID " << id << " does not exist.\n";
            return std::nullopt; // Return an empty task
        }
        return id_task[id];
    }

    void update_task(int id, std::optional<std::string> title = std::nullopt, std::optional<bool> completed = std::nullopt){
        if (id_task.find(id) == id_task.end()) {
            std::cout << "Task with ID " << id << " does not exist.\n";
        }
        if (title.has_value()) {
            id_task[id].title = title.value();
        }
        if (completed.has_value()) {
            id_task[id].completed = completed.value();
        }
        save_tasks();

    }

    void delete_task(int id){
        if (id_task.find(id) == id_task.end()) {
            std::cout << "Task with ID " << id << " does not exist.\n";
            return;
        }
        id_task.erase(id);
        save_tasks();
    }
};
