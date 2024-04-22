all: all_program

all_program: main.o grade_card.o student.o utility.o
	gcc main.o grade_card.o student.o utility.o -o all_program

main.o: main.c grade_card.h student.h utility.h
	gcc -c main.c -o main.o

grade_card.o: grade_card.c grade_card.h
	gcc -c grade_card.c -o grade_card.o

student.o: student.c student.h
	gcc -c student.c -o student.o

utility.o: utility.c utility.h
	gcc -c utility.c -o utility.o

clean:
	rm -f *.o all_program

	rm -f *.o all_program











	