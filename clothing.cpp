#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand) :
  Product(category, name, price, qty), size_(size), brand_(brand)
{

}

set<string> Clothing::keywords() const
{
  set<string> keywords = parseStringToWords(brand_);
  set<string> keywords2 = parseStringToWords(getName());
  set<string> final = setUnion(keywords, keywords2);
  return final;
}

string Clothing::displayString() const
{
  stringstream ss;
  ss << "";
  ss << getName();
  ss << '\n';
  ss << "Size: ";
  ss << size_;
  ss << " Brand: ";
  ss << brand_;
  ss << '\n';
  ss << setw(2) << setprecision(2) << fixed << getPrice();
  ss << " ";
  ss << to_string(getQty());
  ss << " left.";

  string mystr = ss.str();

  /*
  string str = "";
  str += getName();
  str += "\n";
  str += "Size: ";
  str += size_;
  str += " Brand: ";
  str += brand_;
  str += "\n";
  str += to_string(getPrice());
  str += " ";
  str += to_string(getQty());
  str += " left.";*/
  
  return mystr;
}

void Clothing::dump(ostream& os) const
{
  Product::dump(os);
  os << size_ << "\n" << brand_ << endl;
}
