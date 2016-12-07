default: tests

tests: unitTestDriver.o unitTests-docList.o unitTests-NgramCollection.o unitTests-plagiarismAlgorithms.o NgramCollection.o docList.o plagiarismAlgorithms.o
	g++ -std=c++11 -Wall -Wextra -pedantic -o tests unitTestDriver.o unitTests-docList.o unitTests-NgramCollection.o unitTests-plagiarismAlgorithms.o NgramCollection.o docList.o plagiarismAlgorithms.o

unitTestDriver.o: ../include/catch.hpp unitTestDriver.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTestDriver.cpp 

unitTests-docList.o: ../include/catch.hpp ../include/docList.hpp ../include/NgramCollection.hpp unitTests-docList.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTests-docList.cpp

unitTests-NgramCollection.o: ../include/catch.hpp ../include/NgramCollection.hpp unitTests-NgramCollection.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTests-NgramCollection.cpp

unitTests-plagiarismAlgorithms.o: ../include/catch.hpp ../include/plagiarismAlgorithms.hpp ../include/docList.hpp ../include/NgramCollection.hpp unitTests-plagiarismAlgorithms.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -c unitTests-plagiarismAlgorithms.cpp

NgramCollection.o: ../src/NgramCollection.cpp ../include/NgramCollection.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c ../src/NgramCollection.cpp

docList.o: ../src/docList.cpp ../include/docList.hpp ../include/NgramCollection.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c ../src/docList.cpp

plagiarismAlgorithms.o: ../src/plagiarismAlgorithms.cpp ../include/plagiarismAlgorithms.hpp ../include/docList.hpp ../include/NgramCollection.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c ../src/plagiarismAlgorithms.cpp

clean:
	rm -rf *.o tests

rmother:
	rm -f *.cpp~
