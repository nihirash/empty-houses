all: empty.tap

empty.tap: src/main.c
	zcc +zx -lndos -vn -create-app src/main.c -o empty.bin

run: empty.tap
	zesarux empty.tap

clean:
	rm *.bin *.tap *.def
