#include "raylib.h"
#include "grid.hpp"

void Grid::draw() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            Color color = cells[row][col] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(col * cell_size, row * cell_size, cell_size - 1, cell_size - 1, color);
        }
    }   
}

void Grid::set_value(int row, int column, int value) {
    if (is_within_bounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::get_value(int row, int column) {
    if (is_within_bounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}

void Grid::fill_random() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            int random_value = GetRandomValue(0, 4);
            cells[row][col] = (random_value == 4 ? 1 : 0);
        }
    }
}

void Grid::clear() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            cells[row][col] = 0;
        }
    }
}

void Grid::toggle_cell(int row, int column) {
    if (is_within_bounds(row, column)) {
        cells[row][column] = !cells[row][column];
    } 
}

bool Grid::is_within_bounds(int row, int column) {
    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    }

    return false;
}
