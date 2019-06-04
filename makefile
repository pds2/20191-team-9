edit: algordenacao.o randomvetores.o
	cc -o edit algordenacao.o \
	randomvetores.o

algordenacao.o: algordenacao.c algordenacao.h
	cc -c algordenacao.c

randomvetores.o: randomvetores.c randomvetores.h
	cc -c randomvetores.c

clean:
	rm edit algordenacao.o randomvetores.o

run: edit
	./edit
