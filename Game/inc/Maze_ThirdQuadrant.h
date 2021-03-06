/* Copyright 2021 Samuel Dunny */
/* Maze_ThirdQuadrant (in header file) */

#ifndef MAZE_THIRDQUADRANT_H
#define MAZE_THIRDQUADRANT_H

#include "Maze_Corner.h"
#include "Maze_FourWay.h"
#include "Maze_Hallway.h"
#include "Maze_DeadEnd.h"
#include "Maze_TJunction.h"
#include "Maze_BossRoom.h"
#include "Maze_FiveBlockFiller.h"

/* Purpose:
 *  This class instantiates many maze components into one maze quadrant(step up from maze components)
 *  All cordinate placements assume center is at 0,0 in the window
 */

class Maze_ThirdQuadrant {
protected:
    // wall variables

    // corners
    Maze_Component* CAILAS2_c1;
    Maze_Component* CAILAS2_c2;
    Maze_Component* CAILAS2_c3;
    Maze_Component* CAILAS2_c4;
    Maze_Component* CAILAS2_c5;
    Maze_Component* CAILAS2_c6;
    Maze_Component* CAILAS2_c7;
    Maze_Component* CAILAS2_c8;
    Maze_Component* CAILAS2_c9;
    Maze_Component* CAILAS2_c10;
    Maze_Component* CAILAS2_c11;
    Maze_Component* CAILAS2_c12;

    // four-ways
    Maze_Component* CAILAS2_fw1;

    // hallways
    Maze_Component* CAILAS2_hw1;
    Maze_Component* CAILAS2_hw2;
    Maze_Component* CAILAS2_hw3;
    Maze_Component* CAILAS2_hw4;
    Maze_Component* CAILAS2_hw5;
    Maze_Component* CAILAS2_hw6;

    // deadends
    Maze_Component* CAILAS2_de1;
    Maze_Component* CAILAS2_de2;
    Maze_Component* CAILAS2_de3;
    Maze_Component* CAILAS2_de4;
    Maze_Component* CAILAS2_de5;
    Maze_Component* CAILAS2_de6;
    Maze_Component* CAILAS2_de7;
    Maze_Component* CAILAS2_de8;
    Maze_Component* CAILAS2_de9;
    Maze_Component* CAILAS2_de10;

    // t-junction
    Maze_Component* CAILAS2_tj1;
    Maze_Component* CAILAS2_tj2;
    Maze_Component* CAILAS2_tj3;

    // filler strips

    // boss room
    Maze_Component* CAILAS2_boss_room;
    Vector2f br_coords;

    // textures used for wall and background
    Texture brickwall_big;

public:
    // constructor
    Maze_ThirdQuadrant(sf::Vector2f size);

    // destructor
    ~Maze_ThirdQuadrant();

    // contact update functions between walls and the player
    void MazeContactUpdate_Player(Player* player, float push);

    // contact update function between walls and enemies
    void MazeContactUpdate_Enemies(Enemy_Spawner* enemies, float push);

    // Draw method, draws all walls into referenced window (virtual so it gets overriden)
    void Draw(sf::RenderWindow& window);

    // returns true if Individual's Collider is many contact with any of part of the maze
    bool ColliderCheck(Collider other, float push);

    // function that returns true if given coordinates are in a wall component
    bool inMazeWalls(Vector2f coords);
};

Maze_ThirdQuadrant::Maze_ThirdQuadrant(sf::Vector2f size) {
    // ensure all instance variables are empty
    this->CAILAS2_c1 = nullptr;
    this->CAILAS2_c2 = nullptr;
    this->CAILAS2_c3 = nullptr;
    this->CAILAS2_c4 = nullptr;
    this->CAILAS2_c5 = nullptr;
    this->CAILAS2_c6 = nullptr;
    this->CAILAS2_c7 = nullptr;
    this->CAILAS2_c8 = nullptr;
    this->CAILAS2_c9 = nullptr;
    this->CAILAS2_c10 = nullptr;
    this->CAILAS2_c11 = nullptr;
    this->CAILAS2_c12 = nullptr;

    this->CAILAS2_fw1 = nullptr;

    this->CAILAS2_hw1 = nullptr;
    this->CAILAS2_hw2 = nullptr;
    this->CAILAS2_hw3 = nullptr;
    this->CAILAS2_hw4 = nullptr;
    this->CAILAS2_hw5 = nullptr;
    this->CAILAS2_hw6 = nullptr;

    this->CAILAS2_de1 = nullptr;
    this->CAILAS2_de2 = nullptr;
    this->CAILAS2_de3 = nullptr;
    this->CAILAS2_de4 = nullptr;
    this->CAILAS2_de5 = nullptr;
    this->CAILAS2_de6 = nullptr;
    this->CAILAS2_de7 = nullptr;
    this->CAILAS2_de8 = nullptr;
    this->CAILAS2_de9 = nullptr;
    this->CAILAS2_de10 = nullptr;

    this->CAILAS2_tj1 = nullptr;
    this->CAILAS2_tj2 = nullptr;
    this->CAILAS2_tj3 = nullptr;

    this->CAILAS2_boss_room = nullptr;

    // load wall texture from img/ directory
    brickwall_big.loadFromFile("imgs/wall_texture.png");

    // corners
    CAILAS2_c1 = new Maze_Corner(&brickwall_big, size, Vector2f(-9.0f * scale, 2.0f * scale), true, false);
    CAILAS2_c2 = new Maze_Corner(&brickwall_big, size, Vector2f(-5.0f * scale, 5.0f * scale), true, true);
    CAILAS2_c3 = new Maze_Corner(&brickwall_big, size, Vector2f(-23.0f * scale, 5.0f * scale), true, true);
    CAILAS2_c4 = new Maze_Corner(&brickwall_big, size, Vector2f(-26.0f * scale, 9.0f * scale), true, false);
    CAILAS2_c5 = new Maze_Corner(&brickwall_big, size, Vector2f(-22.0f * scale, 13.0f * scale), true, true);
    CAILAS2_c6 = new Maze_Corner(&brickwall_big, size, Vector2f(-26.0f * scale, 17.0f * scale), true, true);
    CAILAS2_c7 = new Maze_Corner(&brickwall_big, size, Vector2f(-13.0f * scale, 9.0f * scale), true, false);
    CAILAS2_c8 = new Maze_Corner(&brickwall_big, size, Vector2f(-9.0f * scale, 12.0f * scale), true, true);
    CAILAS2_c9 = new Maze_Corner(&brickwall_big, size, Vector2f(-9.0f * scale, 16.0f * scale), true, false);
    CAILAS2_c10 = new Maze_Corner(&brickwall_big, size, Vector2f(-17.0f * scale, 26.0f * scale), true, true);
    CAILAS2_c11 = new Maze_Corner(&brickwall_big, size, Vector2f(-13.0f * scale, 24.0f * scale), true, true);
    CAILAS2_c12 = new Maze_Corner(&brickwall_big, size, Vector2f(-1.0f * scale, 26.0f * scale), true, true);

    // four-way intersections
    CAILAS2_fw1 = new Maze_FourWay(&brickwall_big, size, Vector2f(-9.0f * scale, 21.0f * scale));

    // 3-wall length hallways
    CAILAS2_hw1 = new Maze_Hallway(&brickwall_big, size, Vector2f(-13.0f * scale, 5.0f * scale), false);
    CAILAS2_hw2 = new Maze_Hallway(&brickwall_big, size, Vector2f(-26.0f * scale, 13.0f * scale), false);
    CAILAS2_hw3 = new Maze_Hallway(&brickwall_big, size, Vector2f(-22.0f * scale, 17.0f * scale), true);
    CAILAS2_hw4 = new Maze_Hallway(&brickwall_big, size, Vector2f(-13.0f * scale, 19.0f * scale), true);
    CAILAS2_hw5 = new Maze_Hallway(&brickwall_big, size, Vector2f(-4.0f * scale, 25.0f * scale), true);
    CAILAS2_hw6 = new Maze_Hallway(&brickwall_big, size, Vector2f(-7.0f * scale, 25.0f * scale), true);

    // deadend
    CAILAS2_de1 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-13.0f * scale, 2.0f * scale), false, false);
    CAILAS2_de2 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-9.0f * scale, 7.0f * scale), false, false);
    CAILAS2_de3 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-22.0f * scale, 9.0f * scale), false, false);
    CAILAS2_de4 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-19.0f * scale, 19.0f * scale), false, true);
    CAILAS2_de5 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-16.0f * scale, 19.0f * scale), true, true);
    CAILAS2_de6 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-17.0f * scale, 22.0f * scale), true, true);
    CAILAS2_de7 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-13.0f * scale, 28.0f * scale), false, true);
    CAILAS2_de8 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-11.0f * scale, 31.0f * scale), false, true);
    CAILAS2_de9 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(-9.0f * scale, 28.0f * scale), false, true);
    CAILAS2_de10 = new Maze_DeadEnd(&brickwall_big, size, Vector2f(3.0f * scale, 26.0f * scale), true, false);

    // T-junction intersections
    CAILAS2_tj1 = new Maze_TJunction(&brickwall_big, size, Vector2f(-18.0f * scale, 5.0f * scale), true, true);
    CAILAS2_tj2 = new Maze_TJunction(&brickwall_big, size, Vector2f(-18.0f * scale, 14.0f * scale), false, true);
    CAILAS2_tj3 = new Maze_TJunction(&brickwall_big, size, Vector2f(-13.0f * scale, 14.0f * scale), false, false);

    // filler segments (used her to fill extra maze space within enemy spawn bounds that we dont want enemies to spawn in)

    // creates room for maze section boss
    this->br_coords = Vector2f(-18.0f * scale, 9.0f * scale);
    CAILAS2_boss_room = new Maze_BossRoom(&brickwall_big, size, br_coords, false, false);
}

Maze_ThirdQuadrant::~Maze_ThirdQuadrant() { /* empty */ }

void Maze_ThirdQuadrant::MazeContactUpdate_Player(Player* character, float push) {
    // a value of 1.0f is an immovable object, wheres 0.0f would move quickly

    CAILAS2_c1->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c2->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c3->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c4->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c5->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c6->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c7->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c8->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c9->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c10->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c11->ColliderCheck(character->GetCollider(), push);
    CAILAS2_c12->ColliderCheck(character->GetCollider(), push);

    CAILAS2_fw1->ColliderCheck(character->GetCollider(), push);

    CAILAS2_hw1->ColliderCheck(character->GetCollider(), push);
    CAILAS2_hw2->ColliderCheck(character->GetCollider(), push);
    CAILAS2_hw3->ColliderCheck(character->GetCollider(), push);
    CAILAS2_hw4->ColliderCheck(character->GetCollider(), push);
    CAILAS2_hw5->ColliderCheck(character->GetCollider(), push);
    CAILAS2_hw6->ColliderCheck(character->GetCollider(), push);

    CAILAS2_de1->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de2->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de3->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de4->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de5->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de6->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de7->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de8->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de9->ColliderCheck(character->GetCollider(), push);
    CAILAS2_de10->ColliderCheck(character->GetCollider(), push);

    CAILAS2_tj1->ColliderCheck(character->GetCollider(), push);
    CAILAS2_tj2->ColliderCheck(character->GetCollider(), push);
    CAILAS2_tj3->ColliderCheck(character->GetCollider(), push);

    CAILAS2_boss_room->ColliderCheck(character->GetCollider(), push);

}

void Maze_ThirdQuadrant::MazeContactUpdate_Enemies(Enemy_Spawner* enemies, float push) {
    // makes wall the immovable object to minotaur
    enemies->UpdateWallCollisions(CAILAS2_c1, push);
    enemies->UpdateWallCollisions(CAILAS2_c2, push);
    enemies->UpdateWallCollisions(CAILAS2_c3, push);
    enemies->UpdateWallCollisions(CAILAS2_c4, push);
    enemies->UpdateWallCollisions(CAILAS2_c5, push);
    enemies->UpdateWallCollisions(CAILAS2_c6, push);
    enemies->UpdateWallCollisions(CAILAS2_c7, push);
    enemies->UpdateWallCollisions(CAILAS2_c8, push);
    enemies->UpdateWallCollisions(CAILAS2_c9, push);
    enemies->UpdateWallCollisions(CAILAS2_c10, push);
    enemies->UpdateWallCollisions(CAILAS2_c11, push);
    enemies->UpdateWallCollisions(CAILAS2_c12, push);

    enemies->UpdateWallCollisions(CAILAS2_fw1, push);

    enemies->UpdateWallCollisions(CAILAS2_hw1, push);
    enemies->UpdateWallCollisions(CAILAS2_hw2, push);
    enemies->UpdateWallCollisions(CAILAS2_hw3, push);
    enemies->UpdateWallCollisions(CAILAS2_hw4, push);
    enemies->UpdateWallCollisions(CAILAS2_hw5, push);
    enemies->UpdateWallCollisions(CAILAS2_hw6, push);

    enemies->UpdateWallCollisions(CAILAS2_de1, push);
    enemies->UpdateWallCollisions(CAILAS2_de2, push);
    enemies->UpdateWallCollisions(CAILAS2_de3, push);
    enemies->UpdateWallCollisions(CAILAS2_de4, push);
    enemies->UpdateWallCollisions(CAILAS2_de5, push);
    enemies->UpdateWallCollisions(CAILAS2_de6, push);
    enemies->UpdateWallCollisions(CAILAS2_de7, push);
    enemies->UpdateWallCollisions(CAILAS2_de8, push);
    enemies->UpdateWallCollisions(CAILAS2_de9, push);
    enemies->UpdateWallCollisions(CAILAS2_de10, push);

    enemies->UpdateWallCollisions(CAILAS2_tj1, push);
    enemies->UpdateWallCollisions(CAILAS2_tj2, push);
    enemies->UpdateWallCollisions(CAILAS2_tj3, push);

    enemies->UpdateWallCollisions(CAILAS2_boss_room, push);
}

void Maze_ThirdQuadrant::Draw(sf::RenderWindow& window) {
    // draws all walls
    CAILAS2_c1->Draw(window);
    CAILAS2_c2->Draw(window);
    CAILAS2_c3->Draw(window);
    CAILAS2_c4->Draw(window);
    CAILAS2_c5->Draw(window);
    CAILAS2_c6->Draw(window);
    CAILAS2_c7->Draw(window);
    CAILAS2_c8->Draw(window);
    CAILAS2_c9->Draw(window);
    CAILAS2_c10->Draw(window);
    CAILAS2_c11->Draw(window);
    CAILAS2_c12->Draw(window);

    CAILAS2_fw1->Draw(window);

    CAILAS2_hw1->Draw(window);
    CAILAS2_hw2->Draw(window);
    CAILAS2_hw3->Draw(window);
    CAILAS2_hw4->Draw(window);
    CAILAS2_hw5->Draw(window);
    CAILAS2_hw6->Draw(window);

    CAILAS2_de1->Draw(window);
    CAILAS2_de2->Draw(window);
    CAILAS2_de3->Draw(window);
    CAILAS2_de4->Draw(window);
    CAILAS2_de5->Draw(window);
    CAILAS2_de6->Draw(window);
    CAILAS2_de7->Draw(window);
    CAILAS2_de8->Draw(window);
    CAILAS2_de9->Draw(window);
    CAILAS2_de10->Draw(window);

    CAILAS2_tj1->Draw(window);
    CAILAS2_tj2->Draw(window);
    CAILAS2_tj3->Draw(window);

    CAILAS2_boss_room->Draw(window);

}

bool Maze_ThirdQuadrant::ColliderCheck(Collider other, float push) {
    // default filler value
    bool piece1_cond = CAILAS2_c1->ColliderCheck(other, push);
    bool piece2_cond = CAILAS2_c2->ColliderCheck(other, push);
    bool piece3_cond = CAILAS2_c3->ColliderCheck(other, push);
    bool piece4_cond = CAILAS2_c4->ColliderCheck(other, push);
    bool piece5_cond = CAILAS2_c5->ColliderCheck(other, push);
    bool piece6_cond = CAILAS2_c6->ColliderCheck(other, push);
    bool piece7_cond = CAILAS2_c7->ColliderCheck(other, push);
    bool piece8_cond = CAILAS2_c8->ColliderCheck(other, push);
    bool piece9_cond = CAILAS2_c9->ColliderCheck(other, push);
    bool piece10_cond = CAILAS2_c10->ColliderCheck(other, push);
    bool piece11_cond = CAILAS2_c11->ColliderCheck(other, push);
    bool piece12_cond = CAILAS2_c12->ColliderCheck(other, push);

    bool piece13_cond = CAILAS2_fw1->ColliderCheck(other, push);

    bool piece14_cond = CAILAS2_hw1->ColliderCheck(other, push);
    bool piece15_cond = CAILAS2_hw2->ColliderCheck(other, push);
    bool piece16_cond = CAILAS2_hw3->ColliderCheck(other, push);
    bool piece17_cond = CAILAS2_hw4->ColliderCheck(other, push);
    bool piece18_cond = CAILAS2_hw5->ColliderCheck(other, push);
    bool piece19_cond = CAILAS2_hw6->ColliderCheck(other, push);

    bool piece20_cond = CAILAS2_de1->ColliderCheck(other, push);
    bool piece21_cond = CAILAS2_de2->ColliderCheck(other, push);
    bool piece22_cond = CAILAS2_de3->ColliderCheck(other, push);
    bool piece23_cond = CAILAS2_de4->ColliderCheck(other, push);
    bool piece24_cond = CAILAS2_de5->ColliderCheck(other, push);
    bool piece25_cond = CAILAS2_de6->ColliderCheck(other, push);
    bool piece26_cond = CAILAS2_de7->ColliderCheck(other, push);
    bool piece27_cond = CAILAS2_de8->ColliderCheck(other, push);
    bool piece28_cond = CAILAS2_de9->ColliderCheck(other, push);
    bool piece29_cond = CAILAS2_de10->ColliderCheck(other, push);

    bool piece30_cond = CAILAS2_tj1->ColliderCheck(other, push);
    bool piece31_cond = CAILAS2_tj2->ColliderCheck(other, push);
    bool piece32_cond = CAILAS2_tj3->ColliderCheck(other, push);

    bool piece33_cond = CAILAS2_boss_room->ColliderCheck(other, push);

    if (piece1_cond ||
        piece2_cond ||
        piece3_cond ||
        piece4_cond ||
        piece5_cond ||
        piece6_cond ||
        piece7_cond ||
        piece8_cond ||
        piece9_cond ||
        piece10_cond ||
        piece11_cond ||
        piece12_cond ||
        piece13_cond ||
        piece14_cond ||
        piece15_cond ||
        piece16_cond ||
        piece17_cond ||
        piece18_cond ||
        piece19_cond ||
        piece20_cond ||
        piece21_cond ||
        piece22_cond ||
        piece23_cond ||
        piece24_cond ||
        piece25_cond ||
        piece26_cond ||
        piece27_cond ||
        piece28_cond ||
        piece29_cond ||
        piece30_cond ||
        piece31_cond ||
        piece32_cond ||
        piece33_cond )
        return true;

    return false;

}

bool Maze_ThirdQuadrant::inMazeWalls(Vector2f coords) {
    // default filler value
    return CAILAS2_c1->inWallStructure(coords) ||
        CAILAS2_c2->inWallStructure(coords) ||
        CAILAS2_c3->inWallStructure(coords) ||
        CAILAS2_c4->inWallStructure(coords) ||
        CAILAS2_c5->inWallStructure(coords) ||
        CAILAS2_c6->inWallStructure(coords) ||
        CAILAS2_c7->inWallStructure(coords) ||
        CAILAS2_c8->inWallStructure(coords) ||
        CAILAS2_c9->inWallStructure(coords) ||
        CAILAS2_c10->inWallStructure(coords) ||
        CAILAS2_c11->inWallStructure(coords) ||
        CAILAS2_c12->inWallStructure(coords) ||
        CAILAS2_fw1->inWallStructure(coords) ||
        CAILAS2_hw1->inWallStructure(coords) ||
        CAILAS2_hw2->inWallStructure(coords) ||
        CAILAS2_hw3->inWallStructure(coords) ||
        CAILAS2_hw4->inWallStructure(coords) ||
        CAILAS2_hw5->inWallStructure(coords) ||
        CAILAS2_hw6->inWallStructure(coords) ||
        CAILAS2_de1->inWallStructure(coords) ||
        CAILAS2_de2->inWallStructure(coords) ||
        CAILAS2_de3->inWallStructure(coords) ||
        CAILAS2_de4->inWallStructure(coords) ||
        CAILAS2_de5->inWallStructure(coords) ||
        CAILAS2_de6->inWallStructure(coords) ||
        CAILAS2_de7->inWallStructure(coords) ||
        CAILAS2_de8->inWallStructure(coords) ||
        CAILAS2_de9->inWallStructure(coords) ||
        CAILAS2_de10->inWallStructure(coords) ||
        CAILAS2_tj1->inWallStructure(coords) ||
        CAILAS2_tj2->inWallStructure(coords) ||
        CAILAS2_tj3->inWallStructure(coords) ||
        CAILAS2_boss_room->inWallStructure(coords);
}

#endif  // MAZE_THIRDQUADRANT_H