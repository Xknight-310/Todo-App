#include <iostream>
#include <string>
#include "task.h"
int main(){
    std::cout << "-=-=-=- Welcome to Todo App -=-=-=-\n";
    task myTask("first task", true);
    myTask.get_task();
    return 0;
}
