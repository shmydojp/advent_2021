cc=g++
CFLAGS=
OUT=day_04
DEBUG=-g

day_04: day_04.o
	$(cc) day_*.o -o $(OUT)
day_04.o: day_04.c*
	$(cc) -c day_*.c* 
debug:	day_04.o
	$(cc) $(DEBUG) day_*.o -o $(OUT)
clean:
	rm -rf *.o *.exe
	make cleancp
cleancp:
	rm -rf *.*~
