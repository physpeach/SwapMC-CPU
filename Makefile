test: testsrc/test.o cpp/particles.o cpp/cells.o cpp/swapmc.cpp cpp/conf.o
	g++ -o $@ $^

swapmc: main/main.o cpp/particles.o cpp/cells.o cpp/swapmc.cpp cpp/conf.o
	g++ -o $@ $^

%.o: %.cpp hpp/%.hpp
	g++ -o $@ -c $<
