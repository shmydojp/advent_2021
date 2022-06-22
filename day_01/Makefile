cc=g++
CFLAGS=
OUT=day_01
DEBUG=-g

day_01: day_01.o
	$(cc) day_*.o -o $(OUT)
day_01.o: day_01.c*
	$(cc) -c day_*.c* 
debug:	day_01.o
	$(cc) $(DEBUG) day_*.o -o $(OUT)
clean:
	rm -rf *.o *.exe
	make cleancp
cleancp:
	rm -rf *.*~
