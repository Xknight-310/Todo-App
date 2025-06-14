#include <iostream>
#include <string>
#include "src/task.h"
int main(){
    std::cout << "-=-=-=- Welcome to Todo App -=-=-=-\n";
    tasks myTasks;
    myTasks.get_all_task();
    std::cout << "-=-=- Thanks for using Todo App -=-=-\n";
    return 0;
}
