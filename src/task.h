#include <iostream>

class task{
private:

public:
    const char* title;
    bool completed;
    task(const char* title_task){
        title = title_task;
        completed = false;
    }
    task(const char* title_task, bool completed_task){
        title = title_task;
        completed = completed_task;
    }

    void get_task(){
        if (completed){
            std::cout << " * " << title << "\n";
        } else {
            std::cout << "   " << title << "\n";
        }
    }
    
};

