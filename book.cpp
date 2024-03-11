#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "book.h"

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn, string author) :
  Product(category, name, price, qty), isbn_(isbn), author_(author)
{

}

set<string> Book::keywords() const
{
  set<string> keywords = parseStringToWords(author_);
  /*for(set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it)
  {
    cout << *it << endl;
  }*/
  set<string> keywords2 = parseStringToWords(getName());
  /*for(set<string>::iterator it2 = keywords2.begin(); it2 != keywords2.end(); ++it2)
  {
    cout << *it2 << endl;
  }*/
  set<string> final = setUnion(keywords, keywords2);
  /*cout << "FINAL SET" << endl;
  for(set<string>::iterator it3 = final.begin(); it3 != final.end(); ++it3)
  {
    cout << *it3 << endl;
  }
  cout << "FINAL SET END" << endl;*/
  final.insert(isbn_);
  return final;
}

string Book::displayString() const
{
  stringstream ss;
  ss << "";
  ss << getName();
  ss << '\n';
  ss << "Author: ";
  ss << author_;
  ss << " ISBN: ";
  ss << isbn_;
  ss << '\n';
  ss << setw(2) << setprecision(2) << fixed << getPrice();
  ss << " ";
  ss << to_string(getQty());
  ss << " left.";

  string mystr = ss.str();
  /*string str = "";
  str += getName();
  str += "\n";
  str += "Author: ";
  str += author_;
  str += " ISBN: ";
  str += isbn_;
  str += "\n";
  str += to_string(getPrice());
  str += " ";
  str += to_string(getQty());
  str += " left.";*/
  
  return mystr;
}

void Book::dump(ostream& os) const
{
  Product::dump(os);
  os << isbn_ << "\n" << author_ << endl;
}
