#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"
#include "util.h"

class Clothing : public Product {
public:
    /**
     * Constructor, which calls upon the Base constructor, and initializes size and brand
     */
    Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);

    /**
     * Returns a list of keywords unique to the clothing
     */
    std::set<std::string> keywords() const;

    /**
     * Returns a neatly formatted string for the clothing for display
     */
    std::string displayString() const;

    /**
     * Calls upon the Base dump while adding size and brand
     */
    void dump(std::ostream& os) const;

private:
    std::string size_;
    std::string brand_;

};

#endif