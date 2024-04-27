#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

// Structure to represent a cell in the maze
struct Cell {
    int x, y;
};

// Function to check if the cell is within the bounds of the maze and is not a wall
bool isValid(int x, int y, const std::vector<std::vector<int>>& maze) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0;
}

// Function to perform depth-first search to find a path through the maze
bool dfs(const std::vector<std::vector<int>>& maze, const Cell& start, const Cell& end, std::vector<Cell>& path) {
    std::stack<Cell> stack;
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<Cell> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Right, Left, Down, Up

    stack.push(start);
    visited[start.x][start.y] = true;

    while (!stack.empty()) {
        Cell current = stack.top();
        stack.pop();

        if (current.x == end.x && current.y == end.y) {
            path.push_back(current);
            return true;
        }

        for (const auto& direction : directions) {
            int next_x = current.x + direction.x;
            int next_y = current.y + direction.y;
            if (isValid(next_x, next_y, maze) && !visited[next_x][next_y]) {
                stack.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }
    }

    return false;
}

int main() {
    // Example maze represented as a 2D vector where 0 represents a path and 1 represents a wall
    std::vector<std::vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Start and end positions in the maze
    Cell start = {0, 0};
    Cell end = {4, 1};

    std::vector<Cell> path;
    if (dfs(maze, start, end, path)) {
        std::reverse(path.begin(), path.end());
        std::cout << "Path found:" << std::endl;
        for (const auto& cell : path) {
            std::cout << "(" << cell.x << ", " << cell.y << ") ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found!" << std::endl;
    }

    return 0;
}
