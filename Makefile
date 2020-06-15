swapmc: main/main.o cpp/particles.o
	g++ -o $@ $^

%.o: %.cpp hpp/%.cuh hpp/params.hpp
	g++ -o $@ -c $<

%.o: %.cpp hpp/params.hpp
	g++ -o $@ -c $<
