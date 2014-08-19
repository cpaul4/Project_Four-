CC = g++
CFLAGS = -c -g

all: clean project4

project4: 	project4.o Scale.o Price_list.o Product.o Cart.o Deli.o 
		$(CC) -o project4 project4.o Scale.o Price_list.o Product.o Cart.o Deli.o
clean:
		rm -f *.o

%.o:	%.cpp
		$(CC) $(CFLAGS) $*.cpp
