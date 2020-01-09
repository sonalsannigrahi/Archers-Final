CXX = g++

Encryption.o: Encryption.cpp Encryption.hpp
	$(CXX) -c Encryption.cpp 

main_test_encryption.o: Encryption.o main_test_encryption.cpp 
	$(CXX) -c main_test_encryption.cpp

test: main_test_encryption.o 
	$(CXX) main_test_encryption.o Encryption.o -o test  

clean: 
	rm -f test
	rm -f *.o