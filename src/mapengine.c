#include <graphics.h>
#include <games.h>

void put_tile(int x, int y, uchar *tileset, int number) {
	tileset += number * 8;
	uchar* addr = zx_cyx2saddr(y,x);
	for (int i=0;i<8;i++) {
		*addr = *(tileset++);
		addr+=256;
	}
}

int tile(uchar *map, int x, int y) {
	return *(map + x + y * 30);
}

void draw_map(uchar *map, uchar *tileset) {
	#asm
	di
	#endasm
	for (int r=0;r<20;r++)
			for(int c=0;c<30;c++)
				put_tile(1 + c, r, tileset, *(map++));
	#asm
	ei
	#endasm
}