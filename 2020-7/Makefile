SRC=7-1.cpp
DES=server 
CC=g++
FLAG=-std=c++11 -lpthread

SRC1=7-2.cpp
DES1=client

.PHONY:
all:$(DES) $(DES1)

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

$(DES1):$(SRC1)
	$(CC) $^ -o $@ $(FLAG)

clean:
	rm -rf $(DES) $(DES1)
