#include "../include/catch.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::ifstream;
using std::cout;

TEST_CASE("checkFileList", "[checkFileList]") {
  docList doclist;
  int i = doclist.checkFileList("testfile1.txt");
  REQUIRE(i == 1);
  int j = doclist.checkFileList("testfile2.txt");
  REQUIRE(j == 1);
  int k = doclist.checkFileList("testfile3.txt");
  REQUIRE(k == 1);
}

TEST_CASE("makeList", "[makeList]") {
  docList doclist1;
  vector<string> list1 = doclist1.makeList("testfile1.txt");
  REQUIRE(doclist1.numDocs == 3);
  REQUIRE(list1 == {"test1doc1.txt", "test1doc2.txt", "test1doc3.txt"});
  docList doclist2;
  vector<string> list2 = doclist2.makeList("testfile2.txt");
  REQUIRE(doclist2.numDocs == 0);
  REQUIRE(list2 == {""});
  docList doclist3;
  vector<string> list3 = doclist3.makeList("testfile3.txt");
  REQUIRE(doclist3.numDocs == 5);
  REQUIRE(list3 == {"test3doc1.txt", "test3doc2.txt", "test3doc3.txt", "test3doc4.txt", "test3doc5.txt"});
}
