SwapMC: main.o
	g++ -o $@ $^

%.o: %.cpp
	g++ -o $@ -c $<
