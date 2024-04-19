#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() {

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    // Simulation Loop
    while (WindowShouldClose() == false) {

        // Event Handling
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_position = GetMousePosition();
            int row = mouse_position.y / CELL_SIZE;
            int col = mouse_position.x / CELL_SIZE;
            simulation.toggle_cell(row, col);
        }

        int key = GetKeyPressed();
        switch (key) {
            case KEY_ENTER:
                simulation.start();
                SetWindowTitle("Game of Life is running...");
                break;

            case KEY_SPACE:
                simulation.stop();
                SetWindowTitle("Game of Life has stopped...");
                break;
            
            case KEY_F:
                if (FPS < 118) {
                    FPS += 2;
                    SetTargetFPS(FPS);
                }
                break;

            case KEY_S:
                if (FPS > 5) {
                    FPS -= 2;
                    SetTargetFPS(FPS);
                }
                break;

            case KEY_R:
                simulation.create_random_state();
                break;
            
            case KEY_C:
                simulation.clear_grid();
                break;
        }

        // Updating State
        simulation.update();

        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.draw();
        EndDrawing();
    }

    CloseWindow();
}