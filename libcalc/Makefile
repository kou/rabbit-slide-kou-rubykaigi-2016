lib/libcalc.so: include/calc.h libcalc.c
	mkdir -p lib
	gcc -Wall -fPIC -shared -o $@ -I include libcalc.c

clean:
	rm -rf lib
