#include "alien.hpp"

Texture2D Alien::alienImgs[3] = {};

Alien::Alien(int type, Vector2 position)
{
    this-> type = type;
    this-> position = position;

    if(alienImgs[type-1].id == 0){

    switch(type) {
        case 1:
             alienImgs[0] = LoadTexture("pictures/alien1.png");
             break;
        case 2:
            alienImgs[1] = LoadTexture("pictures/alien2.png");
            break;

        case 3:
            alienImgs[2] = LoadTexture("pictures/alien3.png");
            break;
        default:
            alienImgs[0] = LoadTexture("pictures/alien1.png");
            break;
    }}
}

void Alien::Draw(){
    DrawTextureV(alienImgs[type - 1], position, WHITE);
}

int Alien::GetType(){
    return type;
}

void Alien::UnloadImgs()
{
    for(int i= 0; i<4; i++){
        UnloadTexture(alienImgs[i]);
    }
}

Rectangle Alien::getRect()
{
    return {position.x, position.y, float(alienImgs[type - 1].width), float(alienImgs[type-1].height)};
}

void Alien::Update(int direction){
    position.x += direction;
}