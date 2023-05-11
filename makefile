menu_map: menu_map.c
	-gcc -m32 -Wall -o menu_map menu_map.c

.PHONY: clean 
clean:
	rm -f *.o menu_map menu_map.o

	