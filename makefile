# ----------------------------
# Makefile Options
# ----------------------------
bin/MenuBuilder: obj/main.o
	gcc $^ -o bin/Split

obj/main.o: src/main.c
	gcc -c $< -o "$@" 

# ----------------------------