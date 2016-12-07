#ifndef _NGRAM_COLLECTION_HPP
#define _NGRAM_COLLECTION_HPP

#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <tuple>
#include <utility>

class NgramCollection {

public:
    NgramCollection(unsigned num) : n(num) {}

    int getInput(std::string filename);

    void increment(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end);

    std::string toString() const;

    unsigned getN() const { return n; }

    int getNumWords() const {return numWords;}

    int getNumGrams() const {return numGrams;}

    friend std::string algs(std::string filename, char sense);

private:
    std::map<std::vector<std::string>, std::map<std::string, unsigned>> counts;
    int numWords = 0;
    int numGrams = 0;
    unsigned n;
};

#endif
