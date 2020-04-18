SRC=tcp_server_epoll.cpp 
DES=server 
CC=g++
FLAG=-std=c++11 -lpthread

SRC1=tcp_client.cpp
DES1=client

.PHONY:
all:$(DES) $(DES1)

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

$(DES1):$(SRC1)
	$(CC) $^ -o $@ $(FLAG)

clean:
	rm -rf $(DES) $(DES1)
