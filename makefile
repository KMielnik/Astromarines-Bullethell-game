all:
	g++ *.cpp -o Bullethell -std=c++11 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

clean:
	$(RM) Bullethell
