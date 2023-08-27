#include <SDL2/SDL.h>
#include <stdio.h>
#include "Ground.h"
#include "Globals.h"
#include "Tube.h"
#include "QuestionBlock.h"
#include "Block.h"
#include "Mario.h"
#include "Goomba.h"
#include "Platform.h"
#include "Plant.h"
#include "Spaceship.h"
#include "LaserBall.h"

#pragma once

class Game
{
    public:
        Game();
        void MarioHandleEvent( SDL_Event& e );
        void MarioMove();
        void PopulateGrounds();
        void PopulateTubes();
        void PopulatePlatforms();
        void PopulateBlocks();
        void PopulateQuestionBlocks();
        void PopulateGoombas();
        void PopulateLaserBalls();
        void DrawLaserBalls();
        void DrawSpaceships();
        void DrawTubes();
        void DrawGrounds();
        void DrawPlatforms();
        void DrawPlants();
        void DrawBlocks();
        void DrawQuestionBlocks();
        void DrawGoombas();
        void MoveGoombas();
        bool CheckLaserCollision();
        bool CheckPlantCollision();
        void Draw();
        void DrawMenu();
        void DrawGameOver();
        void Run();
    private:
        std::vector<Tube> tubes;
        std::vector<std::vector<SDL_Rect> > groundColliders;
        std::vector<std::vector<SDL_Rect> > tubeColliders;
        std::vector<std::vector<SDL_Rect> > platformColliders;
        std::vector<std::vector<SDL_Rect> > blockColliders;
        std::vector<std::vector<SDL_Rect> > questionBlockColliders;
        std::vector<std::vector<SDL_Rect> > laserBallColliders;
        std::vector<std::vector<SDL_Rect> > goombaColliders;
        LTexture EnterTexture;
        LTexture GameOverTexture;
        Tube tube = Tube(500, 400);
        Ground ground = Ground(0);
        Mario mario;
        bool quit;
        bool Initialized;
        int Lives;
        bool Dead;
        int Frames;
        SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        int start;

        // Goombas to be rendered
        Goomba goomba1 = Goomba(1530);
        Goomba goomba2 = Goomba(1350);
        Goomba goomba3 = Goomba(3335);
        Goomba goomba4 = Goomba(3200);
        Goomba goomba5 = Goomba(5600);
        Goomba goomba6 = Goomba(5735);
        Goomba goomba7 = Goomba(9100);
        Goomba goomba8 = Goomba(9235);
        Goomba goomba9 = Goomba(8965);
        Goomba goomba10 = Goomba(8830);
        Goomba goomba11 = Goomba(10700);
        Goomba goomba12 = Goomba(10935);
        Goomba goomba13 = Goomba(11170);
        Goomba goomba14 = Goomba(11405);

        Goomba new_goomba1 = Goomba(1530);
        Goomba new_goomba2 = Goomba(1350);
        Goomba new_goomba3 = Goomba(3335);
        Goomba new_goomba4 = Goomba(3200);
        Goomba new_goomba5 = Goomba(5600);
        Goomba new_goomba6 = Goomba(5735);
        Goomba new_goomba7 = Goomba(9100);
        Goomba new_goomba8 = Goomba(9235);
        Goomba new_goomba9 = Goomba(8965);
        Goomba new_goomba10 = Goomba(8830);
        Goomba new_goomba11 = Goomba(10700);
        Goomba new_goomba12 = Goomba(10935);
        Goomba new_goomba13 = Goomba(11170);
        Goomba new_goomba14 = Goomba(11405);

        // Spaceships to be rendered
        Spaceship spaceship1 = Spaceship(1000, 50);
        Spaceship spaceship2 = Spaceship(2000, 50);
        Spaceship spaceship3 = Spaceship(3000, 50);
        Spaceship spaceship4 = Spaceship(4000, 50);
        Spaceship spaceship5 = Spaceship(5000, 50);
        Spaceship spaceship6 = Spaceship(6000, 50);
        Spaceship spaceship7 = Spaceship(7000, 50);
        Spaceship spaceship8 = Spaceship(8000, 50);
        Spaceship spaceship9 = Spaceship(9000, 50);
        Spaceship spaceship10 = Spaceship(10000, 50);

        // Laser balls to be rendered
        LaserBall laserBall1 = LaserBall(spaceship1.GetPosX(), spaceship1.GetPosY());
        LaserBall laserBall2 = LaserBall(spaceship2.GetPosX(), spaceship2.GetPosY());
        LaserBall laserBall3 = LaserBall(spaceship3.GetPosX(), spaceship3.GetPosY());
        LaserBall laserBall4 = LaserBall(spaceship4.GetPosX(), spaceship4.GetPosY());
        LaserBall laserBall5 = LaserBall(spaceship5.GetPosX(), spaceship5.GetPosY());
        LaserBall laserBall6 = LaserBall(spaceship6.GetPosX(), spaceship6.GetPosY());
        LaserBall laserBall7 = LaserBall(spaceship7.GetPosX(), spaceship7.GetPosY());
        LaserBall laserBall8 = LaserBall(spaceship8.GetPosX(), spaceship8.GetPosY());
        LaserBall laserBall9 = LaserBall(spaceship9.GetPosX(), spaceship9.GetPosY());
        LaserBall laserBall10 = LaserBall(spaceship10.GetPosX(), spaceship10.GetPosY());

        LaserBall new_laserBall1 = LaserBall(spaceship1.GetPosX(), spaceship1.GetPosY());
        LaserBall new_laserBall2 = LaserBall(spaceship2.GetPosX(), spaceship2.GetPosY());
        LaserBall new_laserBall3 = LaserBall(spaceship3.GetPosX(), spaceship3.GetPosY());
        LaserBall new_laserBall4 = LaserBall(spaceship4.GetPosX(), spaceship4.GetPosY());
        LaserBall new_laserBall5 = LaserBall(spaceship5.GetPosX(), spaceship5.GetPosY());
        LaserBall new_laserBall6 = LaserBall(spaceship6.GetPosX(), spaceship6.GetPosY());
        LaserBall new_laserBall7 = LaserBall(spaceship7.GetPosX(), spaceship7.GetPosY());
        LaserBall new_laserBall8 = LaserBall(spaceship8.GetPosX(), spaceship8.GetPosY());
        LaserBall new_laserBall9 = LaserBall(spaceship9.GetPosX(), spaceship9.GetPosY());
        LaserBall new_laserBall10 = LaserBall(spaceship10.GetPosX(), spaceship10.GetPosY());

        // Tubes to be rendered
        Tube tube1 = Tube(500, 400);
        Tube tube2 = Tube(1600, 375);
        Tube tube3 = Tube(2000, 375);
        Tube tube4 = Tube(2800, 350);
        Tube tube5 = Tube(3400, 350);
        Tube tube6 = Tube(4400, 375);
        Tube tube7 = Tube(5800, 400);
        Tube tube8 = Tube(6700, 350);
        Tube tube9 = Tube(7800, 375);
        Tube tube10 = Tube(8200, 375);
        Tube tube11 = Tube(9300, 350);

        // Tubes to be collided with
        Tube new_tube1 = Tube(500, 400);
        Tube new_tube2 = Tube(1600, 375);
        Tube new_tube3 = Tube(2000, 375);
        Tube new_tube4 = Tube(2800, 350);
        Tube new_tube5 = Tube(3400, 350);
        Tube new_tube6 = Tube(4400, 375);
        Tube new_tube7 = Tube(5800, 400);
        Tube new_tube8 = Tube(6700, 350);
        Tube new_tube9 = Tube(7800, 375);
        Tube new_tube10 = Tube(8200, 375);
        Tube new_tube11 = Tube(9300, 350);

        // Grounds to be rendered
        Ground ground1 = Ground(0);
        Ground ground2 = Ground(875);
        Ground ground3 = Ground(1400);
        Ground ground4 = Ground(1600);
        Ground ground5 = Ground(2450);
        Ground ground6 = Ground(2700);
        Ground ground7 = Ground(3400);
        Ground ground8 = Ground(4100);
        Ground ground9 = Ground(5000);
        Ground ground10 = Ground(5500);
        Ground ground11 = Ground(6100);
        Ground ground12 = Ground(6500);
        Ground ground13 = Ground(7400);
        Ground ground14 = Ground(7800);
        Ground ground15 = Ground(8300);
        Ground ground16 = Ground(9000);
        Ground ground17 = Ground(9900);
        Ground ground18 = Ground(10400);
        Ground ground19 = Ground(10800);

        // Grounds to be collided with 
        Ground new_ground1 = Ground(0);
        Ground new_ground2 = Ground(875);
        Ground new_ground3 = Ground(1400);
        Ground new_ground4 = Ground(1600);
        Ground new_ground5 = Ground(2450);
        Ground new_ground6 = Ground(2700);
        Ground new_ground7 = Ground(3400);
        Ground new_ground8 = Ground(4100);
        Ground new_ground9 = Ground(5000);
        Ground new_ground10 = Ground(5500);
        Ground new_ground11 = Ground(6100);
        Ground new_ground12 = Ground(6500);
        Ground new_ground13 = Ground(7400);
        Ground new_ground14 = Ground(7800);
        Ground new_ground15 = Ground(8300);
        Ground new_ground16 = Ground(9000);
        Ground new_ground17 = Ground(9900);
        Ground new_ground18 = Ground(10400);
        Ground new_ground19 = Ground(10800);

        // Platforms to be rendered
        Platform platform1 = Platform(3640, 455);
        Platform platform2 = Platform(3675, 455);
        Platform platform3 = Platform(3710, 455);
        Platform platform4 = Platform(3745, 455);
        Platform platform5 = Platform(3780, 455);
        Platform platform6 = Platform(3812, 455);

        Platform platform7 = Platform(3675, 420);
        Platform platform8 = Platform(3710, 420);
        Platform platform9 = Platform(3745, 420);
        Platform platform10 = Platform(3780, 420);
        Platform platform11 = Platform(3812, 420);

        Platform platform12 = Platform(3710, 385);
        Platform platform13 = Platform(3745, 385);
        Platform platform14 = Platform(3780, 385);
        Platform platform15 = Platform(3812, 385);

        Platform platform16 = Platform(3745, 350);
        Platform platform17 = Platform(3780, 350);
        Platform platform18 = Platform(3812, 350);

        Platform platform19 = Platform(3780, 315);
        Platform platform20 = Platform(3812, 315);

        Platform platform21 = Platform(3812, 280);

        Plant plant1 = Plant(3860, 410);
        Plant plant2 = Plant(3950, 410);

        Platform platform22 = Platform(4035, 455);
        Platform platform23 = Platform(4070, 455);
        Platform platform24 = Platform(4105, 455);
        Platform platform25 = Platform(4140, 455);
        Platform platform26 = Platform(4175, 455);
        Platform platform27 = Platform(4210, 455);

        Platform platform28 = Platform(4035, 420);
        Platform platform29 = Platform(4070, 420);
        Platform platform30 = Platform(4105, 420);
        Platform platform31 = Platform(4140, 420);
        Platform platform32 = Platform(4175, 420);

        Platform platform33 = Platform(4035, 385);
        Platform platform34 = Platform(4070, 385);
        Platform platform35 = Platform(4105, 385);
        Platform platform36 = Platform(4140, 385);

        Platform platform37 = Platform(4035, 350);
        Platform platform38 = Platform(4070, 350);
        Platform platform39 = Platform(4105, 350);

        Platform platform40 = Platform(4035, 315);
        Platform platform41 = Platform(4070, 315);
        
        Platform platform42 = Platform(4035, 280);

        Platform platform43 = Platform(6010, 455);
        Platform platform44 = Platform(6045, 455);
        Platform platform45 = Platform(6080, 455);
        Platform platform46 = Platform(6115, 455);
        Platform platform47 = Platform(6150, 455);
        Platform platform48 = Platform(6185, 455);

        Platform platform49 = Platform(6045, 420);
        Platform platform50 = Platform(6080, 420);
        Platform platform51 = Platform(6115, 420);
        Platform platform52 = Platform(6150, 420);
        Platform platform53 = Platform(6185, 420);

        Platform platform54 = Platform(6080, 385);
        Platform platform55 = Platform(6115, 385);
        Platform platform56 = Platform(6150, 385);
        Platform platform57 = Platform(6185, 385);

        Platform platform58 = Platform(6115, 350);
        Platform platform59 = Platform(6150, 350);
        Platform platform60 = Platform(6185, 350);

        Platform platform61 = Platform(6150, 315);
        Platform platform62 = Platform(6185, 315);
        
        Platform platform63 = Platform(6185, 280);

        Plant plant3 = Plant(6225, 410);
        Plant plant4 = Plant(6315, 410);

        Platform platform64 = Platform(6400, 455);
        Platform platform65 = Platform(6435, 455);
        Platform platform66 = Platform(6470, 455);
        Platform platform67 = Platform(6505, 455);
        Platform platform68 = Platform(6540, 455);
        Platform platform69 = Platform(6575, 455);

        Platform platform70 = Platform(6400, 420);
        Platform platform71 = Platform(6435, 420);
        Platform platform72 = Platform(6470, 420);
        Platform platform73 = Platform(6505, 420);
        Platform platform74 = Platform(6540, 420);
        
        Platform platform75 = Platform(6400, 385);
        Platform platform76 = Platform(6435, 385);
        Platform platform77 = Platform(6470, 385);
        Platform platform78 = Platform(6505, 385);

        Platform platform79 = Platform(6400, 350);
        Platform platform80 = Platform(6435, 350);
        Platform platform81 = Platform(6470, 350);

        Platform platform82 = Platform(6400, 315);
        Platform platform83 = Platform(6435, 315);

        Platform platform84 = Platform(6400, 280);

        // Platforms to be populated
        Platform new_platform1 = Platform(3640, 455);
        Platform new_platform2 = Platform(3675, 455);
        Platform new_platform3 = Platform(3710, 455);
        Platform new_platform4 = Platform(3745, 455);
        Platform new_platform5 = Platform(3780, 455);
        Platform new_platform6 = Platform(3812, 455);

        Platform new_platform7 = Platform(3675, 420);
        Platform new_platform8 = Platform(3710, 420);
        Platform new_platform9 = Platform(3745, 420);
        Platform new_platform10 = Platform(3780, 420);
        Platform new_platform11 = Platform(3812, 420);

        Platform new_platform12 = Platform(3710, 385);
        Platform new_platform13 = Platform(3745, 385);
        Platform new_platform14 = Platform(3780, 385);
        Platform new_platform15 = Platform(3812, 385);

        Platform new_platform16 = Platform(3745, 350);
        Platform new_platform17 = Platform(3780, 350);
        Platform new_platform18 = Platform(3812, 350);

        Platform new_platform19 = Platform(3780, 315);
        Platform new_platform20 = Platform(3812, 315);

        Platform new_platform21 = Platform(3812, 280);

        Plant new_plant1 = Plant(3860, 410);
        Plant new_plant2 = Plant(3950, 410);

        Platform new_platform22 = Platform(4035, 455);
        Platform new_platform23 = Platform(4070, 455);
        Platform new_platform24 = Platform(4105, 455);
        Platform new_platform25 = Platform(4140, 455);
        Platform new_platform26 = Platform(4175, 455);
        Platform new_platform27 = Platform(4210, 455);

        Platform new_platform28 = Platform(4035, 420);
        Platform new_platform29 = Platform(4070, 420);
        Platform new_platform30 = Platform(4105, 420);
        Platform new_platform31 = Platform(4140, 420);
        Platform new_platform32 = Platform(4175, 420);

        Platform new_platform33 = Platform(4035, 385);
        Platform new_platform34 = Platform(4070, 385);
        Platform new_platform35 = Platform(4105, 385);
        Platform new_platform36 = Platform(4140, 385);

        Platform new_platform37 = Platform(4035, 350);
        Platform new_platform38 = Platform(4070, 350);
        Platform new_platform39 = Platform(4105, 350);

        Platform new_platform40 = Platform(4035, 315);
        Platform new_platform41 = Platform(4070, 315);
        
        Platform new_platform42 = Platform(4035, 280);

        Platform new_platform43 = Platform(6010, 455);
        Platform new_platform44 = Platform(6045, 455);
        Platform new_platform45 = Platform(6080, 455);
        Platform new_platform46 = Platform(6115, 455);
        Platform new_platform47 = Platform(6150, 455);
        Platform new_platform48 = Platform(6185, 455);

        Platform new_platform49 = Platform(6045, 420);
        Platform new_platform50 = Platform(6080, 420);
        Platform new_platform51 = Platform(6115, 420);
        Platform new_platform52 = Platform(6150, 420);
        Platform new_platform53 = Platform(6185, 420);

        Platform new_platform54 = Platform(6080, 385);
        Platform new_platform55 = Platform(6115, 385);
        Platform new_platform56 = Platform(6150, 385);
        Platform new_platform57 = Platform(6185, 385);

        Platform new_platform58 = Platform(6115, 350);
        Platform new_platform59 = Platform(6150, 350);
        Platform new_platform60 = Platform(6185, 350);

        Platform new_platform61 = Platform(6150, 315);
        Platform new_platform62 = Platform(6185, 315);
        
        Platform new_platform63 = Platform(6185, 280);

        Plant new_plant3 = Plant(6225, 410);
        Plant new_plant4 = Plant(6315, 410);

        Platform new_platform64 = Platform(6400, 455);
        Platform new_platform65 = Platform(6435, 455);
        Platform new_platform66 = Platform(6470, 455);
        Platform new_platform67 = Platform(6505, 455);
        Platform new_platform68 = Platform(6540, 455);
        Platform new_platform69 = Platform(6575, 455);

        Platform new_platform70 = Platform(6400, 420);
        Platform new_platform71 = Platform(6435, 420);
        Platform new_platform72 = Platform(6470, 420);
        Platform new_platform73 = Platform(6505, 420);
        Platform new_platform74 = Platform(6540, 420);
        
        Platform new_platform75 = Platform(6400, 385);
        Platform new_platform76 = Platform(6435, 385);
        Platform new_platform77 = Platform(6470, 385);
        Platform new_platform78 = Platform(6505, 385);

        Platform new_platform79 = Platform(6400, 350);
        Platform new_platform80 = Platform(6435, 350);
        Platform new_platform81 = Platform(6470, 350);

        Platform new_platform82 = Platform(6400, 315);
        Platform new_platform83 = Platform(6435, 315);

        Platform new_platform84 = Platform(6400, 280);

        // Blocks to be rendered
        Block block1 = Block(253, 258);
        Block block2 = Block(210, 258);
        Block block3 = Block(1150, 258);
        Block block4 = Block(1193, 258);
        Block block5 = Block(1278, 258);
        Block block6 = Block(3020, 258);
        Block block7 = Block(3105, 258);
        Block block8 = Block(3148, 258);
        Block block9 = Block(5300, 258);
        Block block10 = Block(5343, 258);
        Block block11 = Block(5426, 258);
        Block block12 = Block(8600, 258);
        Block block13 = Block(8643, 258);
        Block block14 = Block(8726, 258);

        // Blocks to be collided with
        Block new_block1 = Block(253, 258);
        Block new_block2 = Block(210, 258);
        Block new_block3 = Block(1150, 258);
        Block new_block4 = Block(1193, 258);
        Block new_block5 = Block(1278, 258);
        Block new_block6 = Block(3020, 258);
        Block new_block7 = Block(3105, 258);
        Block new_block8 = Block(3148, 258);
        Block new_block9 = Block(5300, 258);
        Block new_block10 = Block(5343, 258);
        Block new_block11 = Block(5426, 258);
        Block new_block12 = Block(8600, 258);
        Block new_block13 = Block(8643, 258);
        Block new_block14 = Block(8726, 258);

        // Question blocks to be rendered
        QuestionBlock questionBlock1 = QuestionBlock(1237, 261);
        QuestionBlock questionBlock2 = QuestionBlock(3064, 261);
        QuestionBlock questionBlock3 = QuestionBlock(5387, 261);
        QuestionBlock questionBlock4 = QuestionBlock(8687, 261);

        // Question blocks to be collided with
        QuestionBlock new_questionBlock1 = QuestionBlock(1237, 261);
        QuestionBlock new_questionBlock2 = QuestionBlock(3064, 261);
        QuestionBlock new_questionBlock3 = QuestionBlock(5387, 261);
        QuestionBlock new_questionBlock4 = QuestionBlock(8687, 261);
};
#include "../src/Game.cpp" 