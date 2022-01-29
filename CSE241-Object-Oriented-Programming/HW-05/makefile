target:	hw5

main:	boardgame2d.h eightpuzzle.h klotski.h pegsolitaire.h hw5_main.cpp
		g++ -std=c++11 -c hw5_main.cpp boardgame2d.cpp eightpuzzle.cpp klotski.cpp pegsolitaire.cpp

hw5:	main
		g++ -std=c++11 hw5_main.cpp boardgame2d.cpp eightpuzzle.cpp klotski.cpp pegsolitaire.cpp -o hw5
clean:
		rm hw5 *.o