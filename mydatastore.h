#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include "datastore.h"
#include "product.h"
#include "user.h"

/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 * DO NOT EDIT
 */


class MyDataStore : public DataStore {
public:
    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    /**
     * Adds a product to a user's cart
     */
    void addToCart(std::string username, Product* product);

    /**
     * Returns a vector of current cart contents for a specific user
     */
    std::vector<Product*> viewCart(std::string username);

    /**
     * Initiates purchasing process for a specific user
     */
    void buyCart(std::string username);





private:
    std::queue<Product*> products_; // list of all products
    std::queue<User*> users_; // list of all users
    std::map<User*, std::vector<Product*>> cart; // map between Users and a vector containing all products in their cart
    std::map<std::string, User*> nameconversion; // map between username and its User
    std::map<std::string, std::vector<Product*>> keymap; // map between each keyword and its product(s)


};

#endif
