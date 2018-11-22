#include "book_library_parser.h"

#include <fstream>
#include <sstream>
inline std::vector<std::string> split_string(const std::string &str)
{
    std::istringstream input(str);
    std::string part;
    std::vector<std::string> parts;
    while (std::getline(input, part, ','))
    {
        parts.emplace_back(part);
    }

    return parts;
}
book_library book_library_parser::load_book_library(const std::string &path)
{
    std::vector<book> books;
  
    std::ifstream input(path);
    if(input.is_open() && input.good())
    {
        std::string line;
        while(std::getline(input, line))
        {
            book book;
            auto parts = split_string(line);
            book.title = parts[0];
            book.author = parts[1];
            book.genre = parts[2];
            books.emplace_back(book);
        }
        return book_library(books);
    }
    return book_library({});
}

bool book_library_parser::save_book_libray(const book_library& library, const std::string& output_path)
{
    std::ofstream output(output_path);
    if(output.is_open() && output.good())
    {
        const auto books = library.books();
        for (const auto &book : books)
        {
            output << book.title << "," << book.author << ","
                << book.genre << std::endl;
        }

        output.close();
        return true;
    }
    return false;
}
