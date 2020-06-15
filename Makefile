test: testsrc/test.o cpp/particles.o cpp/cells.o cpp/conf.o
	g++ -o $@ $^

swapmc: main/main.o cpp/particles.o cpp/cells.o cpp/conf.o
	g++ -o $@ $^

%.o: %.cpp hpp/%.hpp
	g++ -o $@ -c $<
