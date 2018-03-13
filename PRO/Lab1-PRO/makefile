.PHONY: clean

Lab1: Main.o Find.o Out.o Write.o Menu.o
	gcc -o lab1 Main.o Find.o Out.o Write.o Menu.o

Main.o: Main.c 
	gcc -c Main.c -o Main.o

Find.o:  Find.c
	gcc -c Find.c -o Find.o

Out.o: Out.c
	gcc -c Out.c -o Out.o

Write.o: Write.c
	gcc -c Write.c -o Write.o

Menu.o: Menu.c
	gcc -c Menu.c -o Menu.o

clean:
	rm -rvf *.o lab1
