#pragma once
#include "spaceship.hpp"
#include "obstacles.hpp"
#include "alien.hpp"
#include"mysteryship.hpp"

class Game{
    public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    bool run;
    bool win;
    int lives;
    int score;
    int highscore;

    private:
    void DeleteInactiveLasers();
    std::vector<Obstacle> CreateObstacles();
    std::vector<Alien> CreateAliens();
    void MoveAliens();
    void MoveDownAliens(int distance);
    void AlienShootLaser();
    void CheckForCollisions();  
    void CheckforWin();
    void GameOver();
    void Reset();
    void InitGame();
    void CheckForHighScore();
    void saveHighscoreToFile(int highscore);
    int loadHighscorefromFile();
    
    Spaceship spaceship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    int aliensDirection;
    std::vector<Laser> alienLasers;
    constexpr static float alienLaserShootInterval = 0.35;
    float timeLastAlienFired;
    MysteryShip mysteryShip;
    float mysteryShipSpawnInterval;
    float timeLastSpawn;
    
};