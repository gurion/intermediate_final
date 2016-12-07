/*
 * Unit test cases for NgramCollection class.
 *
 * TODO: some test cases have been provided, but you will need
 * to write your own for the remaining functions
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

/* test getN, should be pretty easy
 */
TEST_CASE("getN", "[getN]") {
  NgramCollection g3(3);
  NgramCollection g4(4);
  REQUIRE(g3.getN() == 3);
  REQUIRE(g4.getN() == 4);
}


/* TODO: these toString() test cases only test the "default" alphabetic-sort 
 * version of toString() so you will need to write more tests to be sure all 
 * versions work
 */

/* test toString on an empty collection
 */
TEST_CASE("toString when empty", "[toString]") {
  NgramCollection g3(3);
  REQUIRE(g3.toString() == "");

  NgramCollection g4(4);
  REQUIRE(g4.toString() == "");
}

/* test both toString and increment (since toString is the easiest way
 * of checking whether increment worked).  You may want extra
 * test-cases for each of the two separately.
 */
TEST_CASE("toString after increment", "[toString],[increment]") {
  NgramCollection g3(3);

  vector<string> v;
  v.push_back("Four");
  v.push_back("score");
  v.push_back("and");
  v.push_back("seven");
  
  g3.increment(v.begin(), v.end()-1);
  REQUIRE(g3.toString() == "Four score and 1\n");

  g3.increment(v.begin()+1, v.end());
  REQUIRE(g3.toString() == "Four score and 1\nscore and seven 1\n");

  g3.increment(v.begin(), v.end()-1);
  REQUIRE(g3.toString() == "Four score and 2\nscore and seven 1\n");

  g3.increment(v.begin()+1, v.end());
  g3.increment(v.begin()+1, v.end());
  REQUIRE(g3.toString() == "Four score and 2\nscore and seven 3\n");
}

