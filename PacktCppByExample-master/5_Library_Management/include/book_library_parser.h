#pragma once
#include "book_library.h"

class book_library_parser
{
public:
    static book_library load_book_library(const std::string& path);
    static bool save_book_libray(const book_library&library, const std::string &output_path);
};