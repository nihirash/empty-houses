#include <stdio.h>
#include <spectrum.h>
#include "mapengine.c"
#include "data.h"

static void pause(char frames) {
    for (; frames>0; frames--) {
#asm
        halt
#endasm
    }
}

uchar *map = first;

static void move_player(x, y) {
    put_tile(1 + p.x, p.y, sprites, tile(map, p.x, p.y));
    p.x += x;
    p.y += y;
    put_tile(1 + p.x, p.y, hero, p.state);
}

static void gamekeys() {
    switch(toupper(getk())) {
    case K_LEFT:
        if (tile(map, p.x - 1, p.y) != 1) move_player(-1, 0);
        return;
    case K_RIGHT:
        if (tile(map, p.x + 1, p.y) != 1) move_player(1, 0);
        return;
    case K_UP:
        if (tile(map, p.x, p.y - 1) != 1) move_player(0, -1);
        return;
    case K_DOWN:
        if (tile(map, p.x, p.y + 1) != 1) move_player(0, 1);
        return;
    }
}

void main() {
    clg();
    zx_border(0);
    p.x = 3;
    p.y = 3;
    p.state = 0;
    draw_map(map, sprites);
    move_player(0, 0);
    for (;;) {
        gamekeys();
        p.state = (p.state + 1) % 2;
        put_tile(1 + p.x, p.y, hero, p.state);
        pause(5);
    }
}
