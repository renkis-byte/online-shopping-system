#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::~MyDataStore()
{

}

void MyDataStore::addProduct(Product* p)
{
  products_.push(p);
  //cout << "1" << endl;
  set<string> keywords = p->keywords();
  set<string>::iterator it;
  for(it = keywords.begin(); it != keywords.end(); ++it)
  {
    //cout << "2" << endl;
    //cout << "IT: " << *it << endl;
    map<string, vector<Product*>>::iterator it2 = keymap.find(*it);
    if( it2 == keymap.end() )
    {
      //cout << "3" << endl;
      vector<Product*> myvec;
      myvec.push_back(p);
      keymap[*it] = myvec;
      //cout << "4" << endl;
    }else{
      it2->second.push_back(p);
    }
  }
}

void MyDataStore::addUser(User* u)
{
  users_.push(u);
  vector<Product*> blank;
  cart[u] = blank;
  nameconversion[convToLower(u->getName())] = u;
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
  set<Product*> hitset;
  vector<Product*> hits;
  if(terms.empty()) return hits;
  set<string> termset;

  for(size_t i = 0; i < terms.size(); i++)
  {
    termset.insert(convToLower(terms[i]));
  }

  for(size_t i = 0; i < terms.size(); i++)
  {
    string word = convToLower(terms[i]);
    if( type == 1 )
    {
      map<string, vector<Product*>>::iterator it = keymap.find(word);
      if( it != keymap.end() )
      {
        for(size_t i=0; i < it->second.size(); i++)
        {
          hitset.insert(it->second[i]);
        }
      }
    }else{
      map<string, vector<Product*>>::iterator it = keymap.find(word);
      if( it == keymap.end() )
      {
        vector<Product*> emptylist;
        return emptylist;
      }else{
        for(size_t i=0; i < it->second.size(); i++)
        {
          if(hitset.find(it->second[i]) != hitset.end()) continue;
          set<string> somekeywords = it->second[i]->keywords();
          set<string> myset = setIntersection(termset, somekeywords);
          if( myset == termset)
          {
            hitset.insert(it->second[i]);
          }
          
        }
      }
    }
  }
  set<Product*>::iterator it2;
  for(it2 = hitset.begin(); it2 != hitset.end(); ++it2)
  {
    hits.push_back(*it2);
  }
  return hits;
}

void MyDataStore::dump(ostream& ofile)
{
  ofile << "<products>" << endl;
  while(!products_.empty())
  {
    Product* temp = products_.front();
    temp->dump(ofile);
    products_.pop();
    delete temp;
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  while(!users_.empty())
  {
    User* temp2 = users_.front();
    temp2->dump(ofile);
    users_.pop();
    delete temp2;
  } 
  ofile << "</users>" << endl;
}

void MyDataStore::addToCart(string username, Product* product)
{
  map<string, User*>::iterator it = nameconversion.find(convToLower(username));
  if( it == nameconversion.end() )
  {
    cout << "Invalid Request" << endl;
    return;
  }
  User* curr = it->second;
  map<User*, vector<Product*>>::iterator it2 = cart.find(curr);
  (it2->second).push_back(product);
}

vector<Product*> MyDataStore::viewCart(string username)
{
  map<string, User*>::iterator it = nameconversion.find(convToLower(username));
  if( it == nameconversion.end() )
  {
    cout << "Invalid username" << endl;
    vector<Product*> blank;
    return blank;
  }
  User* curr = it->second;
  map<User*, vector<Product*>>::iterator it2 = cart.find(curr);
  return it2->second;
}

void MyDataStore::buyCart(string username)
{
  map<string, User*>::iterator it = nameconversion.find(convToLower(username));
  if( it == nameconversion.end() )
  {
    cout << "Invalid username" << endl;
    return;
  }
  User* curr = it->second;
  map<User*, vector<Product*>>::iterator it2 = cart.find(curr);
  vector<Product*> myvec = it2->second;
  vector<Product*> newCart;
  for(size_t i = 0; i < myvec.size(); i++)
  {
    if((myvec[i]->getQty() > 0) && (curr->getBalance() >= myvec[i]->getPrice()))
    {
      myvec[i]->subtractQty(1);
      curr->deductAmount(myvec[i]->getPrice());
    }else{
      newCart.push_back(myvec[i]);
    }
  }
  it2->second = newCart;

}
