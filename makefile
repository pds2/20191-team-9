edit: usuario.o arquivo.o
        cc -o edit usuario.o \
        arquivo.o

usuario.o: src/usuario/usuario.cpp include/usuario/usuario.h include/arquivo/arquivo.h
        g++ -g -Wall -O3 -std=c++11 -c -o src/usuario/usuario.cpp

arquivo.o: src/arquivo/arquivo.cpp include/arquivo/arquivo.h
				 g++ -g -Wall -O3 -std=c++11 -c -o src/arquivo/arquivo.cpp

clean:
        rm edit usuario.o arquivo.o

run: edit
        ./edit
