#include <graphics.h>
#include <games.h>

static void put_tile(int x, int y, uchar *tileset, uchar number) {
    tileset += number * 8;
    uchar* addr = zx_cyx2saddr(y,x);
    for (int i=0; i<8; i++) {
        *addr = *(tileset++);
        addr += 256;
    }
}

static int tile(uchar *map, int x, int y) {
    return *(map + x + y * 30);
}

static void hide_map() {
#asm
    ld hl, 0x5800
    ld (hl), 0
    ld de, 0x5801
    ld bc, 768
    ldir
#endasm
}

static void show_map() {
#asm
    ld hl, 0x5800
    ld (hl), 0x46
    ld de, 0x5801
    ld bc, 767
    ldir
#endasm
}

static void draw_map(uchar *map, uchar *tileset) {
#asm
    di
#endasm
    hide_map();
    for (int r=0; r<17; r++)
        for(int c=0; c<30; c++)
            put_tile(1 + c, r, tileset, *(map++));
    show_map();
#asm
    ei
#endasm
}
