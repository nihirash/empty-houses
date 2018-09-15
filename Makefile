all: empty.tap

src/sprites.h: gfx/sprites.gif
	tools/sprites.py gfx/sprites.gif 16 src/sprites.h

sprites: src/sprites.h

empty.tap: sprites src/*.c src/*.h
	zcc +zx -lndos -vn -create-app src/main.c -o empty.bin

format:
	astyle src/*

run: empty.tap
	zesarux empty.tap

clean:
	rm *.bin *.tap *.def src/*.orig src/sprites.h
