default: run

run: driver.o NgramCollection.o docList.o plagiarismAlgorithms.o
	g++ -g -std=c++11 -Wall -Wextra -pedantic -o run driver.o NgramCollection.o docList.o plagiarismAlgorithms.o

driver.o: driver.cpp ../include/NgramCollection.hpp ../include/docList.hpp ../include/plagiarismAlgorithms.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c driver.cpp

NgramCollection.o: NgramCollection.cpp ../include/NgramCollection.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c NgramCollection.cpp

docList.o: docList.cpp ../include/docList.hpp ../include/NgramCollection.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c docList.cpp

plagiarismAlgorithms.o: plagiarismAlgorithms.cpp ../include/plagiarismAlgorithms.hpp ../include/docList.hpp ../include/NgramCollection.hpp
	g++ -g -std=c++11 -Wall -Wextra -pedantic -c plagiarismAlgorithms.cpp

clean:
	rm -rf run *.o

rmother:
	rm -f *.cpp~ 
