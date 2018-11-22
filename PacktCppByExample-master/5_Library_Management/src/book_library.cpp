#include "book_library.h"

#include <algorithm>
book_library::book_library(const std::vector<book>& books)
    :books_(books)
{
    
}

book book_library::find_book_by_title(const std::string& title)
{
    auto book_iterator = std::find_if(books_.begin(), books_.end(), [&](const book& book)
    {
        return book.title == title;
    });

    if(book_iterator != std::end(books_))
    {
        return *book_iterator;
    }

    return book{};
}

std::vector<book> book_library::find_books_by_author(const std::string& author)
{
    std::vector<book> results;
    std::copy_if(books_.begin(), books_.end(), std::back_inserter(results), [&](const book &book)
    {
        return book.author == author;
    });
    return results;
}

std::vector<book> book_library::books() const
{
    return books_;
}

std::vector<book> book_library::sort_books()
{
    std::sort(books_.begin(), books_.end());
    return books_;
}




