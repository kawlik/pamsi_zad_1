#	254008 Makefile setup	#

FLAGS = -c -g -iquote inc -pedantic -Wall
FINAL = -pedantic -Wall

RELOC = obj/main.o

#	#	#	#	#	#	#	#

__start__: ./output
	./output

./output: obj ${RELOC}
	g++ ${FINAL} -o ./output ${RELOC}
	rm -r obj

#	#	#	#	#	#	#	#

obj/main.o: main.cpp
	g++ ${FLAGS} -o obj/main.o main.cpp

#	#	#	#	#	#	#	#

obj:
	mkdir -p obj