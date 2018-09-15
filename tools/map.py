#!/usr/bin/env python3
import sys

def getOffset(x, y):
    return x + (y * 240)

def getMap(mapFile, output, col,row):    
    with open(mapFile, "rb") as fp:
        with open("src/" + output + ".h", "w") as w:
            w.write("static char "+output+"[] = {\n\t")
            for y in range(17):
                for x in range(30):
                    fp.seek(getOffset(x+(col*30), y+(row*17)), 0)
                    i = fp.read(1)
                    w.write(str(int.from_bytes(i, byteorder='big')) + ", ")
                w.write('\n\t')
            w.write("};")

        
if (len(sys.argv) < 4):
                        print("Usage: ./map.py <world.map> <col> <row> <outputMap>")
                        sys.exit()

getMap(
    sys.argv[1],
    sys.argv[4],
    int(sys.argv[2]),
    int(sys.argv[3])
    )
