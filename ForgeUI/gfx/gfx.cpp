//
//  gfx.cpp
//  ForgeUI
//
//  Created by Chidume Nnamdi on 17/02/2026.
//

#include "gfx.hpp"
#include "../font/font8x8.hpp"

uint32_t framebuffer[WIDTH * HEIGHT];

void clear(uint32_t color)
{
    for (int i = 0; i < WIDTH * HEIGHT; i++)
        framebuffer[i] = color;
}

//void put_pixel(int x, int y, uint32_t color)
//{
//    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
//        return;
//
//    framebuffer[y * WIDTH + x] = color;
//}
//
//void draw_rect(int x, int y, int w, int h, uint32_t color)
//{
//    for (int i = 0; i < w; i++)
//        for (int j = 0; j < h; j++)
//            put_pixel(x + i, y + j, color);
//}

void put_pixel(int x, int y, uint32_t pixel) {
    framebuffer[y * WIDTH + x] = pixel;
}

void draw_rect(int x, int y, int width, int height, uint32_t pixel) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            put_pixel(x + j, i + y, pixel);
        }
    }
}

void draw_line(int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        put_pixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 <  dx) { err += dx; y0 += sy; }
    }
}

void draw_char(int x, int y, char c, uint32_t color)
{
    uint8_t *glyph = font8x8_basic[(int)c];

    for (int row = 0; row < 8; row++)
        for (int col = 0; col < 8; col++)
            if (glyph[row] & (1 << col))
                put_pixel(x + col, y + row, color);
}
