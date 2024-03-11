#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"
#include "util.h"

class Book : public Product {
public:
    /**
     * Constructor, which calls upon the Base constructor, and initializes isbn and author
     */
    Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);

    /**
     * Returns a list of keywords unique to the book
     */
    std::set<std::string> keywords() const;

    /**
     * Returns a neatly formatted string for the book for display
     */
    std::string displayString() const;

    /**
     * Calls upon the Base dump while adding isbn and autho
     */
    void dump(std::ostream& os) const;

private:
    std::string isbn_;
    std::string author_;

};

#endif
