#include <SFML/Graphics.hpp>
#include <cstdlib>

    const int WINDOW_WIDTH = 500;
    const int WINDOW_HEIGHT = 500;
    const int GRID_SIZE = 5; 
    const int CELL_SIZE = WINDOW_WIDTH / GRID_SIZE;

    sf::Color getRandomColor(){

        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;

        return sf::Color(r, g, b);
    }

    int main() {
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Project_1");

        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));

        sf::Color colors[10];
        for (int i = 0; i < 10; ++i) 
        {
            colors[i] = getRandomColor();
        }

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    cell.setPosition(i * GRID_SIZE, j * GRID_SIZE);
                    int randomIndex = rand() % 10;
                    cell.setFillColor(colors[randomIndex]);
                    window.draw(cell);
                }
            }

            window.display();
        }

    return 0;
}
