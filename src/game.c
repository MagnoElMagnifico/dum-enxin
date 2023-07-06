#include "game.h"

#include <stdlib.h>

dum_Game dum_CreateGame(const int w, const int h) {
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogCritical(0, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    dum_Game game = { 0 };
    game.window = NULL;
    game.renderer = NULL;

    // Create window
    game.window = SDL_CreateWindow("dum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (game.window == NULL) {
        SDL_LogCritical(0, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Create renderer
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);
    if (game.renderer == NULL) {
        SDL_LogCritical(0, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }


    game.running = true;
    return game;
}

void dum_HandleEvents(dum_Game* game) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            game->running = false;
        }
    }
}

void dum_UpdateLogic(dum_Game* game) {
    // Unused parameter
    (void) game;

    // TODO
}

void dum_RenderFrame(dum_Game* game) {
    // Clear previous frame
    SDL_RenderClear(game->renderer);

    // TODO

    // Display the changes
    SDL_RenderPresent(game->renderer);
}

void dum_DestroyGame(dum_Game* game) {
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    SDL_Quit();

    // Invalidates Game struct memory
    // TODO?: use memset instead
    game->window   = NULL;
    game->renderer = NULL;
    game->running  = false;
}
