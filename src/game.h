#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

/*
 * Game struct definition.
 *
 * This struct holds everything related to the game.
 *
 * Instead of this being global, a reference should be passed to any funtion
 * that requires using the Game data.
 */

typedef struct dum_Game {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    // Player square
    SDL_Rect sqr;

    // TODO: Game state
    // TODO: Game entities
} dum_Game;

/*
 * Fills the Game struct.
 * This may fail quitting the program with stdlib exit.
 *
 * \param w    window width
 * \param h    window height
 */
dum_Game dum_CreateGame(const int w, const int h);

/*
 * Handle the user input for the Game.
 */
void dum_HandleEvents(dum_Game*);

/*
 * Updates the Game logic.
 */
void dum_UpdateLogic(dum_Game*);

/*
 * Presents the new frame.
 */
void dum_RenderFrame(dum_Game*);

/*
 * Safely destroys the Game struct.
 */
void dum_DestroyGame(dum_Game*);

