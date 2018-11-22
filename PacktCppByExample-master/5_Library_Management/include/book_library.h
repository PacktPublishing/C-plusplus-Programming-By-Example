#pragma once
#include <vector>
#include "book.h"

class book_library
{
    std::vector<book> books_;

public:
    book_library(const std::vector<book> &books);

    book find_book_by_title(const std::string& title);
    std::vector<book> find_books_by_author(const std::string& author);
    std::vector<book> books() const;
    std::vector<book> sort_books();
};
