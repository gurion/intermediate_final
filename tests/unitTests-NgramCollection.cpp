/*
 *  Unit test cases for NgramCollection class
 */

#include "../include/catch.hpp" // simple unit-testing framework
#include "../include/NgramCollection.hpp" // header declaring the functions we want to test

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

// test getN
TEST_CASE("getN", "[getN]") {
  NgramCollection g3(3);
  CHECK(g3.getN() == 3);
  NgramCollection g4(4);
  CHECK(g4.getN() == 4);
}

// test toString on an empty collection
TEST_CASE("toString when empty", "[toString]") {
  NgramCollection g3(3);
  CHECK(g3.toString() == "");
  REQUIRE(g3.toString() == "");
  NgramCollection g4(4);
  CHECK(g4.toString() == "");
  REQUIRE(g4.toString() == "");
}

/*  test both toString and increment (since toString is the easiest way
 *  of checking whether increment worked).
 */
TEST_CASE("toString after increment", "[toString],[increment]") {
  NgramCollection g3(3);

  vector<string> v;
  v.push_back("Four");
  v.push_back("score");
  v.push_back("and");
  v.push_back("seven");
  
  g3.increment(v.begin(), v.end()-1);
  CHECK(g3.toString() == "Four score and 1\n");

  g3.increment(v.begin()+1, v.end());
  CHECK(g3.toString() == "Four score and 1\nscore and seven 1\n");

  g3.increment(v.begin(), v.end()-1);
  CHECK(g3.toString() == "Four score and 2\nscore and seven 1\n");

  g3.increment(v.begin()+1, v.end());
  g3.increment(v.begin()+1, v.end());
  CHECK(g3.toString() == "Four score and 2\nscore and seven 3\n");
}
