CC := g++
WARN := -Wall
FLAGS := -std=c++11 -pthread
OUT := out

All: CreateOut
	$(CC) $(WARN) main.cpp -o $(OUT)/main.exe $(FLAGS)

CreateOut:
	mkdir -p $(OUT)

Clean:
	rm -rf $(OUT)
