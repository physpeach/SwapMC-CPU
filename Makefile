test: testsrc/test.o cpp/conf.o cpp/MT.o cpp/particles.o cpp/cells.o cpp/swapmc.o
	g++ -o $@ $^

swapmc: main/main.o cpp/conf.o cpp/MT.o cpp/particles.o cpp/cells.o cpp/swapmc.o
	g++ -o $@ $^

%.o: %.cpp hpp/%.hpp
	g++ -o $@ -c $<
