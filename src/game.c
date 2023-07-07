#include "game.h"

#include <stdlib.h> // exit

dum_Game dum_CreateGame(const int w, const int h) {
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogCritical(0, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    dum_Game game = { 0 };

    game.window = NULL;
    game.renderer = NULL;

    game.sqr.x = w / 2;
    game.sqr.y = h / 2;
    game.sqr.w = 10;
    game.sqr.h = 10;

    // Create window
    // There is no need to save the window width and height, since that can be
    // retrieved with `SDL_GetWindowSize(&game.window, &w, &h)`.
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
    // TODO: Abstract even further
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                game->running = false;
                break;

            case SDL_KEYDOWN: {
                switch(event.key.keysym.sym) {
                    case SDLK_q:     game->running = false; break;
                    case SDLK_DOWN:  game->sqr.y += 10; break;
                    case SDLK_UP:    game->sqr.y -= 10; break;
                    case SDLK_RIGHT: game->sqr.x += 10; break;
                    case SDLK_LEFT:  game->sqr.x -= 10; break;
                    default: break;
                }
            }
            default: break;
        }
    }
}

void dum_UpdateLogic(dum_Game* game) {
    int window_width = 0;
    int window_height = 0;
    SDL_GetWindowSize(game->window, &window_width, &window_height);

    if (game->sqr.y < 0) {
        game->sqr.y = window_height - game->sqr.h;
    } else if (game->sqr.y >= window_height) {
        game->sqr.y = 0;
    }

    if (game->sqr.x < 0) {
        game->sqr.x = window_width - game->sqr.w;
    } else if (game->sqr.x >= window_width) {
        game->sqr.x = 0;
    }
}

void dum_RenderFrame(dum_Game* game) {
    // Clear previous frame with black
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    // Render "player" in white
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &game->sqr);

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
