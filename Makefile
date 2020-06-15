test: testsrc/test.o cpp/particles.o cpp/cells.o cpp/conf.cpp
	g++ -o $@ $^

swapmc: main/main.o cpp/particles.o cpp/cells.o cpp/conf.cpp
	g++ -o $@ $^

%.o: %.cpp hpp/%.hpp
	g++ -o $@ -c $<
