CC=g++
FLAGS=-c -std=c++14 -Wall -Werror
NAME = task6
MAIN = main
FILE_1 = figures

all: $(NAME)

$(NAME): $(MAIN).o $(FILE_1).o
	$(CC) $(MAIN).o $(FILE_1).o -o $(NAME)

$(MAIN).o: $(MAIN).cpp
	$(CC) $(FLAGS) $(MAIN).cpp

$(FILE_1).o: $(FILE_1).cpp
	$(CC) $(FLAGS) $(FILE_1).cpp

clean:
	rm -rf *.o $(NAME)