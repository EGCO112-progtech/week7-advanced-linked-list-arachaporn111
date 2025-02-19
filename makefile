compile: main.c
	 gcc main.c -o a


run: a
	 ./a


clean: a
	 rm a
