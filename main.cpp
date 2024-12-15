#include "cmath"
#include "iostream"
#include "unistd.h"

const double pi = 3.14159265358979323846;

double sinFunc(int x, int time, int height, int width) {
  double amp = height / 2.0;
  double stretch = 4.0 / width;

  return (amp * std::sin(stretch * (x + time))) + amp;
}

void setHeight(char **grid, int height, int width, int t) {
  for (int c = 0; c < width; c++) {
    int r = sinFunc(c, t, height, width);
    if (r >= 0 && r < height) {
      grid[r][c] = '+';
    }
  }
}

void clearGrid(char **grid, int height, int width) {
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      grid[r][c] = ' ';
    }
  }
}

void displayGrid(char **grid, int height, int width) {
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      std::cout << grid[r][c];
    }
    std::cout << "\n";
  }
}

int main() {
  int height = 50;
  int width = 100;
  int t = 0;

  std::cout << "test\n";

  int FPS = 60;
  char **grid = new char *[height];

  for (int i = 0; i < height; i++) {
    grid[i] = new char[width];
  }

  while (true) {
    system("clear");

    clearGrid(grid, height, width);
    setHeight(grid, height, width, t);

    setHeight(grid, height, width, t + ((width / 4.0) * pi));
    displayGrid(grid, height, width);

    t++;
    usleep((1.0 / FPS) * pow(10, 6));
  }

  for (int i = 0; i < height; i++) {
    delete[] grid[i];
  }

  delete[] grid;

  return 0;
}
