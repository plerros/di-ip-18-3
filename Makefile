CC=gcc
CFLAGS=-Wall

main: main.o map.o flowarrec.o flowarmem.o flowardp.o common.o
	$(CC) $(CFLAGS) -o flowarrec main.o map.o common.o flowarrec.o
	$(CC) $(CFLAGS) -o flowarmem main.o map.o common.o flowarmem.o
	$(CC) $(CFLAGS) -o flowardp main.o map.o common.o flowardp.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
map.o: map.c
	$(CC) $(CFLAGS) -c map.c
flowarrec.o: flowarrec.c
	$(CC) $(CFLAGS) -c flowarrec.c
flowarmem.o: flowarmem.c
	$(CC) $(CFLAGS) -c flowarmem.c
flowardp.o: flowardp.c
	$(CC) $(CFLAGS) -c flowardp.c
common.o: common.c
	$(CC) $(CFLAGS) -c common.c
.PHONY: clean

clean:
	rm -f main.o
	rm -f map.o
	rm -f flowarrec.o
	rm -f flowarmem.o
	rm -f flowardp.o
	rm -f common.o
	rm -f flowarrec
	rm -f flowarmem
	rm -f flowardp
