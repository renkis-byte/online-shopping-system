#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "movie.h"

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating) :
  Product(category, name, price, qty), genre_(genre), rating_(rating)
{

}

set<string> Movie::keywords() const
{
  set<string> keywords = parseStringToWords(getName());
  keywords.insert(convToLower(genre_));
  return keywords;

}

string Movie::displayString() const
{
  stringstream ss;
  ss << "";
  ss << getName();
  ss << '\n';
  ss << "Genre: ";
  ss << genre_;
  ss << " Rating: ";
  ss << rating_;
  ss << '\n';
  ss << setw(2) << setprecision(2) << fixed << getPrice();
  ss << " ";
  ss << to_string(getQty());
  ss << " left.";

  string mystr = ss.str();
  /*string str = "";
  str += getName();
  str += "\n";
  str += "Genre: ";
  str += genre_;
  str += " Rating: ";
  str += rating_;
  str += "\n";
  str += to_string(getPrice());
  str += " ";
  str += to_string(getQty());
  str += " left.";*/
  
  return mystr;
}

void Movie::dump(ostream& os) const
{
  Product::dump(os);
  os << genre_ << "\n" << rating_ << endl;
}
