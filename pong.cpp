// pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<SFML\Graphics.hpp>
#include<math.h>
#include<vector>
#include <ctime>
#include "square.h"


bool keys[] = { false, false,false,false};
enum DIRECTIONS { UP, DOWN,UP2,DOWN2}; //left is 0, right is 1, up is 2, down is 3

int vy,vy2;

int scoreleft = 0;
int scoreright = 0;
int ballx = 4;
int bally = 4;
std::vector<square*> paddles;
int main()
{
    srand(time(NULL));
    square* newsqure1 = new square(100, 400, 100, 10, true);
    paddles.push_back(newsqure1);
    square* newsure2 = new square(700, 400, 100, 10, true);
    paddles.push_back(newsure2);
    square* newsure3 = new square(400, 400, 2, 10, true);//ball
    paddles.push_back(newsure3);
    std::cout << "Hello Pong!\n";

    
    sf::RenderWindow window(sf::VideoMode(800, 800), "Platformer");
    window.setFramerateLimit(60);
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                keys[UP2] = true;
            }
            else keys[UP2] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                keys[DOWN2] = true;
            }
            else keys[DOWN2] = false;
        }
        if (keys[UP] == true) {

            vy = -4;
        }

        else if (keys[DOWN] == true) {

            vy = 4;
        }
        else vy = 0;
        if (keys[UP2] == true) {

            vy2 = -4;
        }

        else if (keys[DOWN2] == true) {

            vy2 = 4;
        }
        else vy2 = 0;
        //why no work??-fixed thanks critical hex:)
        if (paddles[2]->x + paddles[2]->f >= 800 || paddles[2]->x - paddles[2]->f <= 0) {
            if (paddles[2]->x + paddles[2]->f >= 800) {
                scoreright += 1;
                std::cout << scoreright << "dude on the left scored\n";
            }
            else { scoreleft += 1; std::cout << scoreleft << "dude on the right scored\n"; }

            ballx *= -1;
        }
        if (paddles[2]->y - paddles[2]->ydil >= 800 || paddles[2]->y + paddles[2]->ydil <= 0) {
            bally *= -1;
        }//part below is not working now :( - fixed it wasn't using ydil
        int rando;
        if (paddles[0]->x + paddles[0]->f >= paddles[2]->x + paddles[2]->f and paddles[0]->y + paddles[0]->ydil >= paddles[2]->y + paddles[2]->ydil &&
            paddles[0]->y - paddles[0]->ydil <= paddles[2]->y - paddles[2]->ydil
            ) {
            ballx *= -1;
            bally *= -1;
            rando = rand() % 1;
            if (rando == false) {
                bally *= -1;
            }
            else {
                bally * 1;
            }
        }
        if (paddles[1]->x + paddles[1]->f <= paddles[2]->x + paddles[2]->f and paddles[1]->y + paddles[1]->ydil >= paddles[2]->y + paddles[2]->ydil &&
            paddles[1]->y - paddles[1]->ydil <= paddles[2]->y - paddles[2]->ydil
            ) {
            ballx *= -1;
            bally *= -1;
            rando = rand() % 1;
            if (rando == false) {
                bally *= -1;
            }
            else {
                bally * 1;
            }
        }

        paddles[2]->x += ballx;
        paddles[2]->y += bally;
        paddles[1]->y += vy2;
        
        paddles[0]->y += vy;
        
        paddles[1]->update();
        paddles[1]->draw(window);
        paddles[2]->update();
        paddles[2]->draw(window);
        paddles[0]->update();
        paddles[0]->draw(window);
        window.display();
        window.clear();
    }
}

