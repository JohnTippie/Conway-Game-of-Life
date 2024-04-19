#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::draw() {
    grid.draw();
}

void Simulation::set_cell_value(int row, int column, int value) {
    grid.set_value(row, column, value);
}

int Simulation::count_live_neighbors(int row, int column) {

    int live_neighbors = 0;
    std::vector<std::pair<int, int>> neighbor_offsets = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };

    for (const auto& offset : neighbor_offsets) {
        int neighbor_row = (row + offset.first + grid.get_rows()) % grid.get_rows();
        int neighbor_column = (column + offset.second + grid.get_columns()) % grid.get_columns();
        live_neighbors += grid.get_value(neighbor_row, neighbor_column);
    }

    return live_neighbors;
}

void Simulation::update() {

    if (is_running()) {
        for (int row = 0; row < grid.get_rows(); row++) {
            for (int col = 0; col < grid.get_columns(); col++) {
                int live_neighbors = count_live_neighbors(row, col);
                int cell_value = grid.get_value(row, col);

                if (cell_value == 1) {
                    if (live_neighbors > 3 || live_neighbors < 2) {
                        temp_grid.set_value(row, col, 0);
                    } else {
                        temp_grid.set_value(row, col, 1);
                    }
                } else {
                    if (live_neighbors == 3) {
                        temp_grid.set_value(row, col, 1);
                    } else {
                        temp_grid.set_value(row, col, 0);
                    }
                }
            }
        }
        grid = temp_grid;
    }
}

void Simulation::clear_grid() {
    if (!is_running()) {
        grid.clear();
    }
}

void Simulation::create_random_state() {
    if (!is_running()) {
        grid.fill_random();
    }
}

void Simulation::toggle_cell(int row, int column) {
    if (!is_running()) {
        grid.toggle_cell(row, column);
    }
}
