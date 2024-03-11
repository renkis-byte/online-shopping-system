#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"
#include "util.h"

class Movie : public Product {
public:
    /**
     * Constructor, which calls upon the Base constructor, and initializes genre and rating
     */
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);

    /**
     * Returns a list of keywords unique to the movie
     */
    std::set<std::string> keywords() const;

    /**
     * Returns a neatly formatted string for the movie for display
     */
    std::string displayString() const;

    /**
     * Calls upon the Base dump while adding genre and rating
     */
    void dump(std::ostream& os) const;

private:
    std::string genre_;
    std::string rating_;

};

#endif
