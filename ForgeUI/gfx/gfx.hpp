//
//  gfx.hpp
//  ForgeUI
//
//  Created by Chidume Nnamdi on 17/02/2026.
//

#ifndef gfx_hpp
#define gfx_hpp

#include <stdio.h>
#include <stdint.h>

#define WIDTH  800
#define HEIGHT 600

extern uint32_t framebuffer[WIDTH * HEIGHT];

void clear(uint32_t color);
void put_pixel(int x, int y, uint32_t color);
void draw_rect(int x, int y, int w, int h, uint32_t color);
void draw_line(int x0, int y0, int x1, int y1, uint32_t color);
void draw_char(int x, int y, char c, uint32_t color);

#endif /* gfx_hpp */
