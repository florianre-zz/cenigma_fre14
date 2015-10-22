# edit this makefile so that running make compiles your enigma program

enigma: Main.o Enigma.o Mapper.o Rotor.o Plugboard.o Reflector.o Utils.o
	g++ -o enigma $^

Main.o: Main.cpp Enigma.cpp Utils.cpp
	g++ -c $^

Enigma.o: Enigma.cpp Rotor.cpp Plugboard.cpp Reflector.cpp
	g++ -c $<

Mapper.o: Mapper.cpp
	g++ -c $<

Rotor.o: Rotor.cpp Mapper.cpp
	g++ -c $^

Plugboard.o: Plugboard.cpp Mapper.cpp
	g++ -c $^

Reflector.o: Reflector.cpp Mapper.cpp
	g++ -c $^

Utils.o: Utils.cpp
	g++ -c $<

clean:
	rm -rf enigma *.o

.PHONY: clean
