all:clean
	gcc student.c -o student

clean:
	rm -rf student
