lib/libhello.so: include/hello.h libhello.c
	mkdir -p lib
	gcc -Wall -fPIC -shared -o $@ -I include libhello.c

clean:
	rm -rf lib
