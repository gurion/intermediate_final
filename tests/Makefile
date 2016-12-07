default: tests

tests: unitTestDriver.o unitTests-docList.o unitTests-NgramCollection.o unitTests-plagiarismAlgorithms.o
	g++ -std=c++11 -Wall -Wextra -pedantic -o tests unitTestDriver.o unitTests-docList.o unitTests-NgramCollection.o unitTests-plagiarismAlgorithms.o

unitTestDriver.o: ../include/catch.hpp unitTestDriver.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTestDriver.cpp 

unitTests-docList.o: ../include/catch.hpp ../include/docList.hpp ../include/NgramCollection.hpp unitTests-docList.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTests-docList.cpp

unitTests-NgramCollection.o: ../include/catch.hpp ../include/NgramCollection.hpp unitTests-plagiarismAlgorithms.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTests-NgramCollection.cpp

unitTests-plagiarismAlgorithms.o: ../include/catch.hpp ../include/plagiarismAlgorithms.hpp ../include/docList.hpp ../include/NgramCollection.hpp unitTests-plagiarismAlgorithms.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTests-plagiarismAlgorithms.cpp

clean:
	rm -rf *.o test

rmother:
	rm *.cpp~
