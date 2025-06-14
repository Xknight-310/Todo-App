#include <iostream>
#include <string>
#include "src/task.h"
int main(){
    std::cout << "-=-=-=- Welcome to Todo App -=-=-=-\n";
    tasks myTasks;
    myTasks.add_task(1, "Complete C++ project");
    myTasks.add_task(2, "Review pull requests");
    myTasks.get_all_task();
    std::cout << "Thank you for using Todo App!\n";
    return 0;
}
