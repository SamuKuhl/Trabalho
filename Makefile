CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = frota
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/arquivos.o $(OBJS)/relatorios.o $(OBJS)/utils.o $(OBJS)/menus.o $(OBJS)/cadastros.o $(OBJS)/main.o -o $(TARGET)
	
objetos:
	$(CC) -c $(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/relatorios.c -o $(OBJS)/relatorios.o
	$(CC) -c $(SRC)/utils.c -o $(OBJS)/utils.o
	$(CC) -c $(SRC)/arquivos.c -o $(OBJS)/arquivos.o
	$(CC) -c main.c -o $(OBJS)/main.o

clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)