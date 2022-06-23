cc=g++
CFLAGS=
OUT=day_03
DEBUG=-g

day_03: day_03.o
	$(cc) day_*.o -o $(OUT)
day_03.o: day_03.c*
	$(cc) -c day_*.c* 
debug:	day_03.o
	$(cc) $(DEBUG) day_*.o -o $(OUT)
clean:
	rm -rf *.o *.exe
	make cleancp
cleancp:
	rm -rf *.*~
