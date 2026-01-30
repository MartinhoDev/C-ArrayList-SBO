all: build

build:
	@echo "Compiling..."
	@mkdir -p bin
	@gcc -O3 -Wall -Wextra src/*.c -o bin/arrayList.bin

clear:
	@echo "Cleaning..."
	@rm bin/arrayList.bin

run: all
	@echo "Running..."
	@./bin/arrayList.bin $(Mode)