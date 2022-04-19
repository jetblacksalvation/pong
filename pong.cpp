// pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<SFML\Graphics.hpp>
#include<math.h>
#include<vector>
#include <ctime>
#include "square.h"


bool keys[] = { false, false};
enum DIRECTIONS { UP, DOWN}; //left is 0, right is 1, up is 2, down is 3

int vx, vy;

int ballx, bally = 1;
std::vector<square*> paddles;
int main()
{
    square* newsqure1 = new square(100, 400, 100, 10, true);
    paddles.push_back(newsqure1);
    square* newsure2 = new square(800, 400, 100, 10, true);
    paddles.push_back(newsure2);
    square* newsure3 = new square(400, 400, 2, 10, true);//ball
    paddles.push_back(newsure3);
    std::cout << "Hello Pong!\n";


    sf::RenderWindow window(sf::VideoMode(800, 800), "Platformer");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                keys[UP] = true;
            }
            else keys[UP] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;
        }
        if (keys[UP] == true) {

            vy = -1;
        }

        else if (keys[DOWN] == true) {

            vy = 1;
        }
        else vy = 0;
        //why no work??
        if (paddles[2]->x + paddles[2]->f >= 800 || paddles[2]->x - paddles[2]->f <= 0) {
            ballx * -1;
        }
        if (paddles[2]->y - paddles[2]->ydil >= 800 || paddles[2]->y + paddles[2]->ydil <= 0) {
            bally * -1;
        }
        paddles[2]->x += ballx;
        paddles[2]->y += bally;
        
        paddles[0]->y += vy;
        paddles[1]->y = paddles[2]->y;
        paddles[2]->update();
        paddles[2]->draw(window);
        paddles[0]->update();
        paddles[0]->draw(window);
        window.display();
        window.clear();
    }
}

