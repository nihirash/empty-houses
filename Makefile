all: empty.tap

empty.tap: src/*.c src/*.h
	zcc +zx -lndos -vn -create-app src/main.c -o empty.bin

format:
	astyle src/*

run: empty.tap
	zesarux empty.tap

clean:
	rm *.bin *.tap *.def src/*.orig
