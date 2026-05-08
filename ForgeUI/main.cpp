//
//  main.cpp
//  ForgeUI
//
//  Created by Chidume Nnamdi on 17/02/2026.
//

#include <iostream>
#include "gfx/gfx.hpp"
#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "GUI Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture *texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH, HEIGHT
    );

    clear(0xFF202020);

    draw_rect(50, 50, 300, 200, 0xFF4040FF);
    draw_line(0, 0, WIDTH - 1, HEIGHT - 1, 0xFFFFFFFF);
    draw_char(70, 70, 'A', 0xFFFFFFFF);

    int running = 1;
    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if (e.type == SDL_QUIT)
                running = 0;

        SDL_UpdateTexture(texture, NULL, framebuffer, WIDTH * 4);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}
