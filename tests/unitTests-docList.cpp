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
  CHECK(i == 1);
  int j = doclist.checkFileList("testfile2.txt");
  CHECK(j == 1);
  int k = doclist.checkFileList("testfile3.txt");
  CHECK(k == 1);
}

TEST_CASE("makeList", "[makeList]") {
  docList doclist1;
  vector<string> list1 = doclist1.makeList("testfile1.txt");
  CHECK(doclist1.getNumDocs() == 3);
  CHECK(list1 == {"test1doc1.txt", "test1doc2.txt", "test1doc3.txt"});
  docList doclist2;
  vector<string> list2 = doclist2.makeList("testfile2.txt");
  CHECK(doclist2.getNumDocs() == 0);
  CHECK(list2 == {""});
  docList doclist3;
  vector<string> list3 = doclist3.makeList("testfile3.txt");
  CHECK(doclist3.getNumDocs() == 5);
  CHECK(list3 == {"test3doc1.txt", "test3doc2.txt", "test3doc3.txt", "test3doc4.txt", "test3doc5.txt"});
}
