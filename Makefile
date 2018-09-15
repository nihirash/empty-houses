all: empty.tap

src/sprites.h: resources/sprites.gif
	tools/sprites.py resources/sprites.gif 16 src/sprites.h

sprites: src/sprites.h

src/first.h: resources/world.map
	tools/map.py resources/world.map 0 0 first

maps: src/first.h

empty.tap: sprites maps src/*.c src/*.h
	zcc +zx -lndos -vn -create-app src/main.c -o empty.bin

format:
	astyle src/*

run: empty.tap
	zesarux empty.tap

clean:
	rm *.bin *.tap *.def src/*.orig src/sprites.h src/first.h
