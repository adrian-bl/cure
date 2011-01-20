default:
	gcc -fPIC -rdynamic -c -Wunused-value -Wunused-variable -Wall dbg.c
	gcc -shared -Wl,-soname,dbg.so.0 -o dbg.so.0 dbg.o -lc -ldl
	rm *.o

