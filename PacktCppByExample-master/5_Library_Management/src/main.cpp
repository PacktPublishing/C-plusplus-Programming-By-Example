
#include <iostream>
#include <iterator>

#include "application.h"
#include "book_library_parser.h"

void print_books(const std::vector<book> &books)
{
    std::copy(books.begin(), books.end(), 
        std::ostream_iterator<book>(std::cout, "\n"));
}

int main()
{
    std::cout << "---------- Book Library ----------" << std::endl;
    application app;
    book_library_parser parser;
    const auto path = std::string(DATA_DIRECTORY) + "//books.csv";
    auto library = parser.load_book_library(path);
    do
    {
        // get user input
        auto input = app.get_action();
        auto action = app.get_action_input(input);

        switch(action)
        {
        case application::app_action::none:
            if(input == '1')
            {
                print_books(library.books());
            }
            break;
        case application::app_action::sort:
            {
                auto sorted_books = library.sort_books();
                print_books(sorted_books);
            }
            break;
        case application::app_action::search_book:
            {
                std::cin.get();
                std::cout << "Enter book title: ";
                std::string book_title;
                std::getline(std::cin, book_title);
                auto book = library.find_book_by_title(book_title);
                if(book.title == book_title)
                {
                    std::cout << "Found book: " << book << std::endl;
                }
                else
                {
                    std::cout << "No book found with title: " << book_title << std::endl;
                }
            }
            break;
        case application::app_action::search_author:
            {
            std::cin.get();
            std::cout << "Enter author name: ";
            std::string author_name;
            std::getline(std::cin, author_name);
            auto books = library.find_books_by_author(author_name);
                if(!books.empty())
                {
                    std::cout << "Found " + std::to_string(books.size()) << " books by "
                        << author_name << std::endl;
                    print_books(books);
                }
                else
                {
                    std::cout << "No books found by: " << author_name << std::endl;
                }
            }
            break;
        case application::app_action::save_library:
            {
                parser.save_book_libray(library, "books.csv");
            }
            break;
        default:
            break;
        }

        // do something with user input
    } while (app.continue_running());

    return 0;
}