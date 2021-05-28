# Jacob Schneck
# CS 120
# Final Project 

CC := g++ -std=c++17
LIBS :=  -lglut -lGL

run: 
	$(CC) graphics.cpp BasicFlower.cpp SunFlower.cpp ElongatedFlower.cpp Flower.cpp shapes/*.cpp -o graphics ${LIBS}
	./graphics
	rm graphics

tests:
	$(CC) tests.cpp BasicFlower.cpp SunFlower.cpp ElongatedFlower.cpp Flower.cpp shapes/*.cpp -o tests ${LIBS}
	./tests
	rm tests
 