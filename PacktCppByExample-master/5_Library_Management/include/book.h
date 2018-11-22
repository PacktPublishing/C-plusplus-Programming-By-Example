#pragma once
#include <string>
#include <tuple>

struct book
{
    std::string title;
    std::string author;
    std::string genre;
};

inline std::ostream& operator<<(std::ostream& output, const book &book)
{
    output << "Title: " << book.title << " By: " << book.author << " Genre: " << book.genre;
    return output;
}

inline bool operator<(const book& left, const book& right)
{
    return std::tie(left.title, left.author, left.genre) < std::tie(right.title, right.author, right.genre);
}