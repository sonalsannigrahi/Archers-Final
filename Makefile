CXX = g++
Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

fichier1.o: path_vers_fichier1.cpp path_vers_fichier1.hpp 
	$(CXX) -c path_vers_fichier1.cpp $(Dependencies)

fichier2.o: path_vers_fichier2.cpp path_vers_fichier2.hpp 
	$(CXX) -c path_vers_fichier2.cpp $(Dependencies)

fichier_out: fichier1.o fichier2o 
	$(CXX) fichier1.o fichier2o -o fichier_out

clean:
	rm -f fichier_out
	rm -f *.o
