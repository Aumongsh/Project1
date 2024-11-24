#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

    const int WINDOW_WIDTH = 500;
    const int WINDOW_HEIGHT = 500;
    const int NUM_OF_COLUMNS = 5; 
    const int CELL_SIZE = WINDOW_WIDTH / NUM_OF_COLUMNS;

    sf::Color getRandomColor(){
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        return sf::Color(r, g, b);
    }


    int main() {
        srand(time(0));
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Project_1");
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        //Create 2D array to store 
        sf::Color cellColors[NUM_OF_COLUMNS][NUM_OF_COLUMNS];

        //Assign random colors to the grid cells once at the beginning (outside of the while loop)
        //So the colors won't keep changing while the window is open.
        for (int i = 0; i < NUM_OF_COLUMNS; ++i) {
            for (int j = 0; j < NUM_OF_COLUMNS; ++j) {
                cellColors[i][j] = getRandomColor();
            }
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            for (int i = 0; i < NUM_OF_COLUMNS; ++i) {
                for (int j = 0; j < NUM_OF_COLUMNS; ++j) {
                    cell.setPosition(i * NUM_OF_COLUMNS, j * NUM_OF_COLUMNS);
                    int randomIndex = rand() % 10;
                    cell.setFillColor(cellColors[i][j]);
                    window.draw(cell);
                }
            }
            window.display();
        }
    return 0;
}
