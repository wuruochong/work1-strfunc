strfunc: strfunc.c
	gcc strfunc.c -o strfunc

run: strfunc
	./strfunc

clean:
	rm *~
