
#include "application.h"
#include <iostream>


bool application::continue_running()
{
    std::cout << "Anything else? (Y/N): ";
    char response;
    std::cin >> response;
    return response == 'Y' || response == 'y';
}

char application::get_action()
{
    std::cout << "What would you like to do next? (Choose one): " << std::endl;
    std::cout << "1 (show books) " << std::endl;
    std::cout << "2 (sort books) " << std::endl;
    std::cout << "3 (search for book by title) " << std::endl;
    std::cout << "4 (search for books by author) " << std::endl;
    std::cout << "5 (save current library)" << std::endl;
    char action;
    std::cin >> action;
    return action;
}

application::app_action application::get_action_input(char input)
{
    switch(input)
    {
    case '1':
        return app_action::none;
    case '2':
        return app_action::sort;
    case '3':
        return app_action::search_book;
    case '4':
        return app_action::search_author;
    case '5':
        return app_action::save_library;
    default:
        return app_action::none;
    }
}
