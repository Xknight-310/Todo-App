#include <iostream>
#include <string>
#include "src/task.h"
#include <vector>
#include <algorithm>

std::vector<std::string> all_quit_statements = {"exit", "Exit", "EXIT", "quit", "Quit", "QUIT", "q", "Q", "close", "Close", "CLOSE", "e", "E", "stop", "Stop", "STOP"};
int main(){
    std::cout << "-=-=-=- Welcome to Todo App -=-=-=-\n";
    tasks myTasks;
    myTasks.get_all_task();
    while (true) {
        std::cout << "-=-=-=- Commands -=-=-=-\n"
                  << "1: Add task \n"
                  << "2: Quit \n";
        std::string command;
        std::getline(std::cin, command);
        if (std::find(all_quit_statements.begin(), all_quit_statements.end(), command) != all_quit_statements.end() || command == "2") {
            break;
        } 
        if (command == "1") {
            std::cout << "-=-=-=- 1: Add task -=-=-=-\n"
                      << "Type the title of your next task\n";
            std::string title;
            std::getline(std::cin, title);
            if (std::find(all_quit_statements.begin(), all_quit_statements.end(), title) != all_quit_statements.end()) {
                break;
            }
            myTasks.add_task(title);
            std::cout << "Task added\n";
        } else {
            std::cout << "That is not an option.\n";
        }
        
        myTasks.get_all_task();
    }
    std::cout << "-=-=- Thanks for using Todo App -=-=-\n";
    return 0;
}
