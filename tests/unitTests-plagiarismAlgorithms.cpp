#include "../include/catch.hpp"
#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::ifstream;

TEST_CASE("testfile1", "[algs],[compare]") {
  CHECK(algs("testfile1.txt", 'l') == "test1doc1.txt test1doc2.txt\n");
  CHECK(algs("testfile1.txt", 'm') == "test1doc1.txt test1doc2.txt\n");
  CHECK(algs("testfile1.txt", 'h') == "test1doc1.txt test1doc2.txt\ntest1doc1.txt test1doc3.txt\n");
}


TEST_CASE("testfile3", "[algs],[compare]") {
  CHECK(algs("testfile1.txt", 'l') == "test1doc1.txt test1doc2.txt\n");
  CHECK(algs("testfile1.txt", 'm') == "test1doc1.txt test1doc2.txt\n");
  CHECK(algs("testfile1.txt", 'h') == "test1doc1.txt test1doc2.txt\ntest1doc1.txt test1doc3.txt\n");
}
