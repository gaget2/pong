all: basicRun

basicRun: main.cpp
		g++ -std=c++11 -c main.cpp PongApplication.hpp PongApplication.cpp CRconstants.hpp States.hpp StateManager.cpp GameState.cpp SplashState.cpp
		g++ main.o PongApplication.o GameState.o SplashState.o StateManager.o -o pong -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
clean:
	rm -rf *.o basicRun