#include <SDL.h>
#include <stdlib.h>

#include "global.h"

SDL_Renderer * _renderer;
SDL_Window * _window;
bool _is_running;

void Init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING))
        exit(1);
    _window = SDL_CreateWindow("Hello World!\0", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!_window)
        exit(1);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer)
        exit(1);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

void Quit_SDL() {
    SDL_RenderClear(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Event() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            _is_running = false;
        }
    }
}

int main() {
    srand(0);
    Init_SDL();
    _is_running = true;
    unsigned int _ticks = 0;
    while (_is_running) {
        Event();
        SDL_Delay(16);
        SDL_RenderPresent(_renderer);
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
        SDL_RenderClear(_renderer);
        _ticks++;
    }
    Quit_SDL();
    return 0;
}
