#pragma once

class application
{
    
public:
    enum class app_action
    {
        none, search_book, search_author, sort, save_library
    };
    bool continue_running();
    char get_action();
    app_action get_action_input(char input);
};