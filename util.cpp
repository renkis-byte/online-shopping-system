#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> keywords;
    if(rawWords.size() < 2) return keywords; // empty list if size is < 2

    int startingindex = 0;
    for(size_t i = 0; i < rawWords.size(); i++) // for loop to iterate through each character in the string
    {
        rawWords[i] = tolower(rawWords[i]); // convert each character to lower for synchronized storage
        if(ispunct(rawWords[i]) || isspace(rawWords[i])) // if the character is a space or punct, we analyze to see if the past characters are...
        {
            if( i - startingindex >= 2) // greater than 1
            {
                string mysubstr = rawWords.substr(startingindex, i - startingindex);
                keywords.insert(mysubstr); // this is thus a valid substring, which we insert into the list
            }
            startingindex = i+1; // we increase our starting index, which is used for analyzing the rest of the list from this new subpoint
        }
        else if(i == rawWords.size() - 1) // if this is the last iteration/character in the string AND a valid character...
        {
            if(i - startingindex >= 1) // if the substr is greater than 1, add it to the keywords set
            {
                string mysubstr = rawWords.substr(startingindex, i - startingindex + 1);
                keywords.insert(mysubstr);
            }
        }
    }

    return keywords;









}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

/*
int main()
{
    string str = "Men's Fitted Shirt''''";
    set<string> myset = parseStringToWords(str);

    set<string>::iterator it;
    for(it = myset.begin(); it != myset.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << endl;
    set<int> s1;
    set<int> s2;
    s1.insert(0);
    s1.insert(1);
    s1.insert(2);
    s2.insert(0);
    s2.insert(3);
    set<int> iset = setUnion(s1, s2);
    set<int>::iterator it2;
    cout << "GOT TO HERE!" << endl;
    for(it2 = iset.begin(); it2 != iset.end(); ++it2)
    {
        cout << *it2 << endl;
    }

}
*/
