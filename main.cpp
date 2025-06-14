#include <iostream>
#include <string>
#include "src/task.h"
#include <vector>
#include <algorithm>
#include <optional>

std::vector<std::string> all_quit_statements = {"exit", "Exit", "EXIT", "quit", "Quit", "QUIT", "q", "Q", "close", "Close", "CLOSE", "e", "E", "stop", "Stop", "STOP"};
int main(){
    std::cout << "-=-=-=- Welcome to Todo App -=-=-=-\n";
    tasks myTasks;
    myTasks.get_all_task();
    while (true) {
        std::cout << "-=-=-=- Commands -=-=-=-\n"
                  << "1: Add task \n"
                  << "2: Update task \n"
                  << "3: Remove task \n"
                  << "4: Quit \n";
        std::string command;
        std::getline(std::cin, command);
        if (std::find(all_quit_statements.begin(), all_quit_statements.end(), command) != all_quit_statements.end() || command == "4") {
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
        } else if (command == "2"){
            std::cout << "-=-=-=- 1: Update task -=-=-=-\n";
            int id;
            std::string id_str;
            std::getline(std::cin, id_str);
            id = std::stoi(id_str);
            std::cout << "Choose an options:\n"
                      << "1: Change title \n"
                      << "2: Complete task \n"
                      << "3: Quit program \n";
            std::string update_task_command;
            std::getline(std::cin, update_task_command);
            if (std::find(all_quit_statements.begin(), all_quit_statements.end(), update_task_command) != all_quit_statements.end() || update_task_command == "3") {
                break;
            }
            if (update_task_command == "1"){
                std::string new_title;
                std::cout << "New title: ";
                std::getline(std::cin, new_title);
                myTasks.update_task(id , new_title);
                std::optional<task> updated_task = myTasks.get_task(id);
                if (updated_task.has_value()) {
                    std::cout << "Task " << updated_task->title << " is now completed\n";
                }

            }else if (update_task_command == "2"){
                myTasks.update_task(id , std::nullopt, true);
                std::cout << "Task " << myTasks.get_task(id)->title << " is now completed\n";
            }
            
        } else {
            std::cout << "That is not an option.\n";
        }
        
        myTasks.get_all_task();
    }
    std::cout << "-=-=- Thanks for using Todo App -=-=-\n";
    return 0;
}
