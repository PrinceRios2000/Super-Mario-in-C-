#include "../headers/Game.h"

#pragma once

Game::Game()
{
    quit = false;
    Initialized = false;
    start = 5;
    Lives = 3;
    Dead = false;
    Frames = 0;
    SDL_Color textColor = {248, 249, 249};
    EnterTexture.loadFromRenderedText("Press Enter", textColor);
    GameOverTexture.loadFromRenderedText("Game Over", textColor);
    tubeColliders.push_back(tube.GetColliders());
    groundColliders.push_back(ground.GetColliders());
    platformColliders.push_back(platform1.GetColliders());
    laserBallColliders.push_back(laserBall1.GetColliders());
    blockColliders.push_back(block1.GetColliders());
    questionBlockColliders.push_back(questionBlock1.GetColliders());
    tubes.push_back(tube);
    PopulateBlocks();
    PopulateQuestionBlocks();
    PopulateGrounds();
    PopulateTubes();
    PopulatePlatforms();
}

void Game::MarioMove()
{
    this->mario.Move( tubeColliders, groundColliders, platformColliders, blockColliders, questionBlockColliders );
}

void Game::MarioHandleEvent(SDL_Event& e)
{
    this->mario.HandleEvent(e);
}

void Game::PopulateLaserBalls()
{
    laserBallColliders.push_back(new_laserBall1.GetColliders());
    laserBallColliders.push_back(new_laserBall2.GetColliders());
    laserBallColliders.push_back(new_laserBall3.GetColliders());
    laserBallColliders.push_back(new_laserBall4.GetColliders());
    laserBallColliders.push_back(new_laserBall5.GetColliders());
    laserBallColliders.push_back(new_laserBall6.GetColliders());
    laserBallColliders.push_back(new_laserBall7.GetColliders());
    laserBallColliders.push_back(new_laserBall8.GetColliders());
    laserBallColliders.push_back(new_laserBall9.GetColliders());
    laserBallColliders.push_back(new_laserBall10.GetColliders());
}

void Game::PopulateGoombas()
{
    goombaColliders.push_back(new_goomba1.GetColliders());
    goombaColliders.push_back(new_goomba2.GetColliders());
    goombaColliders.push_back(new_goomba3.GetColliders());
    goombaColliders.push_back(new_goomba4.GetColliders());
    goombaColliders.push_back(new_goomba5.GetColliders());
    goombaColliders.push_back(new_goomba6.GetColliders());
    goombaColliders.push_back(new_goomba7.GetColliders());
    goombaColliders.push_back(new_goomba8.GetColliders());
    goombaColliders.push_back(new_goomba9.GetColliders());
    goombaColliders.push_back(new_goomba10.GetColliders());
    goombaColliders.push_back(new_goomba11.GetColliders());
    goombaColliders.push_back(new_goomba12.GetColliders());
    goombaColliders.push_back(new_goomba13.GetColliders());
    goombaColliders.push_back(new_goomba14.GetColliders());
}

void Game::PopulateBlocks()
{
    blockColliders.push_back(new_block1.GetColliders());
    blockColliders.push_back(new_block2.GetColliders());
    blockColliders.push_back(new_block3.GetColliders());
    blockColliders.push_back(new_block4.GetColliders());
    blockColliders.push_back(new_block5.GetColliders());
    blockColliders.push_back(new_block6.GetColliders());
    blockColliders.push_back(new_block7.GetColliders());
    blockColliders.push_back(new_block8.GetColliders());
    blockColliders.push_back(new_block9.GetColliders());
    blockColliders.push_back(new_block10.GetColliders());
    blockColliders.push_back(new_block11.GetColliders());
    blockColliders.push_back(new_block12.GetColliders());
    blockColliders.push_back(new_block13.GetColliders());
    blockColliders.push_back(new_block14.GetColliders());
}

void Game::PopulateQuestionBlocks()
{
    questionBlockColliders.push_back(new_questionBlock1.GetColliders());
    questionBlockColliders.push_back(new_questionBlock2.GetColliders());
    questionBlockColliders.push_back(new_questionBlock3.GetColliders());
    questionBlockColliders.push_back(new_questionBlock4.GetColliders());
}

void Game::PopulateGrounds()
{
    groundColliders.push_back(new_ground1.GetColliders());
    groundColliders.push_back(new_ground2.GetColliders());
    groundColliders.push_back(new_ground3.GetColliders());
    groundColliders.push_back(new_ground4.GetColliders());
    groundColliders.push_back(new_ground5.GetColliders());
    groundColliders.push_back(new_ground6.GetColliders());
    groundColliders.push_back(new_ground7.GetColliders());
    groundColliders.push_back(new_ground8.GetColliders());
    groundColliders.push_back(new_ground9.GetColliders());
    groundColliders.push_back(new_ground10.GetColliders());
    groundColliders.push_back(new_ground11.GetColliders());
    groundColliders.push_back(new_ground12.GetColliders());
    groundColliders.push_back(new_ground13.GetColliders());
    groundColliders.push_back(new_ground14.GetColliders());
    groundColliders.push_back(new_ground15.GetColliders());
    groundColliders.push_back(new_ground16.GetColliders());
    groundColliders.push_back(new_ground17.GetColliders());
    groundColliders.push_back(new_ground18.GetColliders());
    groundColliders.push_back(new_ground19.GetColliders());
}

void Game::PopulateTubes()
{
    tubeColliders.push_back(new_tube1.GetColliders());
    tubeColliders.push_back(new_tube2.GetColliders());
    tubeColliders.push_back(new_tube3.GetColliders());
    tubeColliders.push_back(new_tube4.GetColliders());
    tubeColliders.push_back(new_tube5.GetColliders());
    tubeColliders.push_back(new_tube6.GetColliders());
    tubeColliders.push_back(new_tube7.GetColliders());
    tubeColliders.push_back(new_tube8.GetColliders());
    tubeColliders.push_back(new_tube9.GetColliders());
    tubeColliders.push_back(new_tube10.GetColliders());
    tubeColliders.push_back(new_tube11.GetColliders());
}

void Game::PopulatePlatforms()
{
    platformColliders.push_back(new_platform1.GetColliders());
    platformColliders.push_back(new_platform2.GetColliders());
    platformColliders.push_back(new_platform3.GetColliders());
    platformColliders.push_back(new_platform4.GetColliders());
    platformColliders.push_back(new_platform5.GetColliders());
    platformColliders.push_back(new_platform6.GetColliders());
    platformColliders.push_back(new_platform7.GetColliders());
    platformColliders.push_back(new_platform8.GetColliders());
    platformColliders.push_back(new_platform9.GetColliders());
    platformColliders.push_back(new_platform10.GetColliders());
    platformColliders.push_back(new_platform11.GetColliders());
    platformColliders.push_back(new_platform12.GetColliders());
    platformColliders.push_back(new_platform13.GetColliders());
    platformColliders.push_back(new_platform14.GetColliders());
    platformColliders.push_back(new_platform15.GetColliders());
    platformColliders.push_back(new_platform16.GetColliders());
    platformColliders.push_back(new_platform17.GetColliders());
    platformColliders.push_back(new_platform18.GetColliders());
    platformColliders.push_back(new_platform19.GetColliders());
    platformColliders.push_back(new_platform20.GetColliders());
    platformColliders.push_back(new_platform21.GetColliders());
    platformColliders.push_back(new_platform22.GetColliders());
    platformColliders.push_back(new_platform23.GetColliders());
    platformColliders.push_back(new_platform24.GetColliders());
    platformColliders.push_back(new_platform25.GetColliders());
    platformColliders.push_back(new_platform26.GetColliders());
    platformColliders.push_back(new_platform27.GetColliders());
    platformColliders.push_back(new_platform28.GetColliders());
    platformColliders.push_back(new_platform29.GetColliders());
    platformColliders.push_back(new_platform30.GetColliders());
    platformColliders.push_back(new_platform31.GetColliders());
    platformColliders.push_back(new_platform32.GetColliders());
    platformColliders.push_back(new_platform33.GetColliders());
    platformColliders.push_back(new_platform34.GetColliders());
    platformColliders.push_back(new_platform35.GetColliders());
    platformColliders.push_back(new_platform36.GetColliders());
    platformColliders.push_back(new_platform37.GetColliders());
    platformColliders.push_back(new_platform38.GetColliders());
    platformColliders.push_back(new_platform39.GetColliders());
    platformColliders.push_back(new_platform40.GetColliders());
    platformColliders.push_back(new_platform41.GetColliders());
    platformColliders.push_back(new_platform42.GetColliders());
    platformColliders.push_back(new_platform43.GetColliders());
    platformColliders.push_back(new_platform44.GetColliders());
    platformColliders.push_back(new_platform45.GetColliders());
    platformColliders.push_back(new_platform46.GetColliders());
    platformColliders.push_back(new_platform47.GetColliders());
    platformColliders.push_back(new_platform48.GetColliders());
    platformColliders.push_back(new_platform49.GetColliders());
    platformColliders.push_back(new_platform50.GetColliders());
    platformColliders.push_back(new_platform51.GetColliders());
    platformColliders.push_back(new_platform52.GetColliders());
    platformColliders.push_back(new_platform53.GetColliders());
    platformColliders.push_back(new_platform54.GetColliders());
    platformColliders.push_back(new_platform55.GetColliders());
    platformColliders.push_back(new_platform56.GetColliders());
    platformColliders.push_back(new_platform57.GetColliders());
    platformColliders.push_back(new_platform58.GetColliders());
    platformColliders.push_back(new_platform59.GetColliders());
    platformColliders.push_back(new_platform60.GetColliders());
    platformColliders.push_back(new_platform61.GetColliders());
    platformColliders.push_back(new_platform62.GetColliders());
    platformColliders.push_back(new_platform63.GetColliders());
    platformColliders.push_back(new_platform64.GetColliders());
    platformColliders.push_back(new_platform65.GetColliders());
    platformColliders.push_back(new_platform66.GetColliders());
    platformColliders.push_back(new_platform67.GetColliders());
    platformColliders.push_back(new_platform68.GetColliders());
    platformColliders.push_back(new_platform69.GetColliders());
    platformColliders.push_back(new_platform70.GetColliders());
    platformColliders.push_back(new_platform71.GetColliders());
    platformColliders.push_back(new_platform72.GetColliders());
    platformColliders.push_back(new_platform73.GetColliders());
    platformColliders.push_back(new_platform74.GetColliders());
    platformColliders.push_back(new_platform75.GetColliders());
    platformColliders.push_back(new_platform76.GetColliders());
    platformColliders.push_back(new_platform77.GetColliders());
    platformColliders.push_back(new_platform78.GetColliders());
    platformColliders.push_back(new_platform79.GetColliders());
    platformColliders.push_back(new_platform80.GetColliders());
    platformColliders.push_back(new_platform81.GetColliders());
    platformColliders.push_back(new_platform82.GetColliders());
    platformColliders.push_back(new_platform83.GetColliders());
    platformColliders.push_back(new_platform84.GetColliders());
}

void Game::DrawSpaceships()
{
    spaceship1.Draw( camera.x, camera.y );
    spaceship2.Draw( camera.x, camera.y);
    spaceship3.Draw( camera.x, camera.y );
    spaceship4.Draw( camera.x, camera.y );
    spaceship5.Draw( camera.x, camera.y );
    spaceship6.Draw( camera.x, camera.y );
    spaceship7.Draw( camera.x, camera.y );
    spaceship8.Draw( camera.x, camera.y );
    spaceship9.Draw( camera.x, camera.y );
    spaceship10.Draw( camera.x, camera.y );
}

void Game::DrawLaserBalls()
{
    laserBall1.Draw( camera.x, camera.y );
    laserBall2.Draw( camera.x, camera.y );
    laserBall3.Draw( camera.x, camera.y );
    laserBall4.Draw( camera.x, camera.y );
    laserBall5.Draw( camera.x, camera.y );
    laserBall6.Draw( camera.x, camera.y );
    laserBall7.Draw( camera.x, camera.y );
    laserBall8.Draw( camera.x, camera.y );
    laserBall9.Draw( camera.x, camera.y );
    laserBall10.Draw( camera.x, camera.y );
}

void Game::DrawTubes()
{
    tube1.Draw( camera.x, camera.y );
    tube2.Draw( camera.x, camera.y );
    tube3.Draw( camera.x, camera.y );
    tube4.Draw( camera.x, camera.y );
    tube5.Draw( camera.x, camera.y );
    tube6.Draw( camera.x, camera.y );
    tube7.Draw( camera.x, camera.y );
    tube8.Draw( camera.x, camera.y );
    tube9.Draw( camera.x, camera.y );
    tube10.Draw( camera.x, camera.y );
    tube11.Draw( camera.x, camera.y );
}

void Game::DrawGrounds()
{
    ground1.Draw( camera.x, camera.y );
    ground2.Draw( camera.x, camera.y );
    ground3.Draw( camera.x, camera.y );
    ground4.Draw( camera.x, camera.y );
    ground5.Draw( camera.x, camera.y );
    ground6.Draw( camera.x, camera.y );
    ground7.Draw( camera.x, camera.y );
    ground8.Draw( camera.x, camera.y );
    ground9.Draw( camera.x, camera.y );
    ground10.Draw( camera.x, camera.y );
    ground11.Draw( camera.x, camera.y );
    ground12.Draw( camera.x, camera.y );
    ground13.Draw( camera.x, camera.y );
    ground14.Draw( camera.x, camera.y );
    ground15.Draw( camera.x, camera.y );
    ground16.Draw( camera.x, camera.y );
    ground17.Draw( camera.x, camera.y );
    ground18.Draw( camera.x, camera.y );
    ground19.Draw( camera.x, camera.y );
}

void Game::DrawPlatforms()
{
    platform1.Draw( camera.x, camera.y );
    platform2.Draw( camera.x, camera.y );
    platform3.Draw( camera.x, camera.y );
    platform4.Draw( camera.x, camera.y );
    platform5.Draw( camera.x, camera.y );
    platform6.Draw( camera.x, camera.y );
    platform7.Draw( camera.x, camera.y );
    platform8.Draw( camera.x, camera.y );
    platform9.Draw( camera.x, camera.y );
    platform10.Draw( camera.x, camera.y);
    platform11.Draw( camera.x, camera.y );
    platform12.Draw( camera.x, camera.y );
    platform13.Draw( camera.x, camera.y );
    platform14.Draw( camera.x, camera.y );
    platform15.Draw( camera.x, camera.y );
    platform16.Draw( camera.x, camera.y );
    platform17.Draw( camera.x, camera.y );
    platform18.Draw( camera.x, camera.y );
    platform19.Draw( camera.x, camera.y );
    platform20.Draw( camera.x, camera.y );
    platform21.Draw( camera.x, camera.y );
    platform22.Draw( camera.x, camera.y );
    platform23.Draw( camera.x, camera.y );
    platform24.Draw( camera.x, camera.y );
    platform25.Draw( camera.x, camera.y );
    platform26.Draw( camera.x, camera.y );
    platform27.Draw( camera.x, camera.y );
    platform27.Draw( camera.x, camera.y );
    platform28.Draw( camera.x, camera.y );
    platform29.Draw( camera.x, camera.y );
    platform30.Draw( camera.x, camera.y );
    platform31.Draw( camera.x, camera.y );
    platform32.Draw( camera.x, camera.y );
    platform33.Draw( camera.x, camera.y );
    platform34.Draw( camera.x, camera.y );
    platform35.Draw( camera.x, camera.y );
    platform36.Draw( camera.x, camera.y );
    platform37.Draw( camera.x, camera.y );
    platform38.Draw( camera.x, camera.y );
    platform39.Draw( camera.x, camera.y );
    platform40.Draw( camera.x, camera.y );
    platform41.Draw( camera.x, camera.y );
    platform42.Draw( camera.x, camera.y );
    platform43.Draw( camera.x, camera.y );
    platform44.Draw( camera.x, camera.y );
    platform45.Draw( camera.x, camera.y );
    platform46.Draw( camera.x, camera.y );
    platform47.Draw( camera.x, camera.y );
    platform48.Draw( camera.x, camera.y );
    platform49.Draw( camera.x, camera.y );
    platform50.Draw( camera.x, camera.y );
    platform51.Draw( camera.x, camera.y );
    platform52.Draw( camera.x, camera.y );
    platform53.Draw( camera.x, camera.y );
    platform54.Draw( camera.x, camera.y );
    platform55.Draw( camera.x, camera.y );
    platform56.Draw( camera.x, camera.y );
    platform57.Draw( camera.x, camera.y );
    platform58.Draw( camera.x, camera.y );
    platform59.Draw( camera.x, camera.y );
    platform60.Draw( camera.x, camera.y );
    platform61.Draw( camera.x, camera.y );
    platform62.Draw( camera.x, camera.y );
    platform63.Draw( camera.x, camera.y );
    platform64.Draw( camera.x, camera.y );
    platform65.Draw( camera.x, camera.y );
    platform66.Draw( camera.x, camera.y );
    platform67.Draw( camera.x, camera.y );
    platform68.Draw( camera.x, camera.y );
    platform69.Draw( camera.x, camera.y );
    platform70.Draw( camera.x, camera.y );
    platform71.Draw( camera.x, camera.y );
    platform72.Draw( camera.x, camera.y );
    platform73.Draw( camera.x, camera.y );
    platform74.Draw( camera.x, camera.y );
    platform75.Draw( camera.x, camera.y );
    platform76.Draw( camera.x, camera.y );
    platform77.Draw( camera.x, camera.y );
    platform78.Draw( camera.x, camera.y );
    platform79.Draw( camera.x, camera.y );
    platform80.Draw( camera.x, camera.y );
    platform81.Draw( camera.x, camera.y );
    platform82.Draw( camera.x, camera.y );
    platform83.Draw( camera.x, camera.y );
    platform84.Draw( camera.x, camera.y );
}

void Game::DrawPlants()
{
    plant1.Draw( camera.x, camera.y );
    plant2.Draw( camera.x, camera.y );
    plant3.Draw( camera.x, camera.y );
    plant4.Draw( camera.x, camera.y );
}

void Game::DrawBlocks()
{
    block1.Draw( camera.x, camera.y );
    block2.Draw( camera.x, camera.y);
    block3.Draw( camera.x, camera.y );
    block4.Draw( camera.x, camera.y );
    block5.Draw( camera.x, camera.y );
    block6.Draw( camera.x, camera.y );
    block7.Draw( camera.x, camera.y );
    block8.Draw( camera.x, camera.y );
    block9.Draw( camera.x, camera.y );
    block10.Draw( camera.x, camera.y );
    block11.Draw( camera.x, camera.y );
    block12.Draw( camera.x, camera.y );
    block13.Draw( camera.x, camera.y );
    block14.Draw( camera.x, camera.y );
}

void Game::DrawQuestionBlocks()
{
    questionBlock1.Draw( camera.x, camera.y );
    questionBlock2.Draw( camera.x, camera.y );
    questionBlock3.Draw( camera.x, camera.y );
    questionBlock4.Draw( camera.x, camera.y );
}

bool Game::CheckLaserCollision()
{
    if(laserBall1.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship1.GetPosX(), spaceship1.GetPosY(), this->mario.GetColliders()) || 
    laserBall2.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship2.GetPosX(), spaceship2.GetPosY(), this->mario.GetColliders()) ||
    laserBall3.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship3.GetPosX(), spaceship3.GetPosY(), this->mario.GetColliders()) ||
    laserBall4.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship4.GetPosX(), spaceship4.GetPosY(), this->mario.GetColliders()) ||
    laserBall5.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship5.GetPosX(), spaceship5.GetPosY(), this->mario.GetColliders()) ||
    laserBall6.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship6.GetPosX(), spaceship6.GetPosY(), this->mario.GetColliders()) ||
    laserBall7.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship7.GetPosX(), spaceship7.GetPosY(), this->mario.GetColliders()) ||
    laserBall8.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship8.GetPosX(), spaceship8.GetPosY(), this->mario.GetColliders()) ||
    laserBall9.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship9.GetPosX(), spaceship9.GetPosY(), this->mario.GetColliders()) ||
    laserBall10.CheckCollision(this->mario.GetPosX(), this->mario.GetPosY(), spaceship10.GetPosX(), spaceship10.GetPosY(), this->mario.GetColliders()))
    {
        return true;
    }
    return false;
}

void Game::MoveGoombas()
{
    goomba1.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba2.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba3.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba4.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba5.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba6.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba7.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba8.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba9.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba10.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba11.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba12.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba13.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());
    goomba14.CheckGoombaCollision(groundColliders, tubeColliders, this->mario.GetColliders(), this->mario.GetPosX(), this->mario.GetPosY());

}

void Game::DrawGoombas()
{
    goomba1.Draw( camera.x, camera.y );
    goomba2.Draw( camera.x, camera.y );
    goomba3.Draw( camera.x, camera.y );
    goomba4.Draw( camera.x, camera.y );
    goomba5.Draw( camera.x, camera.y );
    goomba6.Draw( camera.x, camera.y );
    goomba7.Draw( camera.x, camera.y );
    goomba8.Draw( camera.x, camera.y );
    goomba9.Draw( camera.x, camera.y );
    goomba10.Draw( camera.x, camera.y );
    goomba11.Draw( camera.x, camera.y );
    goomba12.Draw( camera.x, camera.y );
    goomba13.Draw( camera.x, camera.y );
    goomba14.Draw( camera.x, camera.y );
}

bool Game::CheckPlantCollision()
{
    return (plant1.CheckCollision(this->mario.GetColliders()) || plant2.CheckCollision(this->mario.GetColliders()) || plant3.CheckCollision(this->mario.GetColliders())
        || plant4.CheckCollision(this->mario.GetColliders()));
}

void Game::DrawMenu()
{
    EnterTexture.render( ( SCREEN_WIDTH - EnterTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - EnterTexture.getHeight() ) / 2 );
}

void Game::DrawGameOver()
{
    GameOverTexture.render( ( SCREEN_WIDTH - GameOverTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - GameOverTexture.getHeight() ) / 2 );
}

void Game::Draw()
{
    camera.x = ( this->mario.GetPosX() + MARIO_WIDTH / 2 ) - 300;
    camera.y = ( this->mario.GetPosY() + MARIO_WIDTH / 2 ) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds
    if( camera.x < 0 )
    { 
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > LEVEL_WIDTH - camera.w )
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if( camera.y > SCREEN_HEIGHT - camera.h )
    {
        camera.y = SCREEN_HEIGHT - camera.h;
    }

    SDL_RenderClear(renderer);
    if(Dead)
    {
        if(Frames < 300)
        {
            DrawGameOver();
            Frames++;
        }
        else
        {
            Dead = false;
            Initialized = false;
            Frames = 0;
        }
    }
    else 
    {
        if(!Initialized)
        {
            DrawMenu();
        }
        else
        {
            MarioMove();
            if(CheckLaserCollision())
            {
                Lives -= 1;
                this->mario.Reset();
            }
            if(CheckPlantCollision())
            {
                Lives -= 1;
                this->mario.Reset();
            }
            if(!Lives)
            {
                Dead = true;
                Lives = 3;
                return;
            }
            DrawGoombas();
            MoveGoombas();
            DrawLaserBalls();
            DrawSpaceships();
            DrawPlants();
            DrawTubes();
            DrawGrounds();
            DrawPlatforms();
            DrawBlocks();
            DrawQuestionBlocks();
            this->mario.Draw( camera.x, camera.y );
        }
    }
    SDL_RenderPresent(renderer);
}

void Game::Run()
{
    SDL_Event event;
    while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				quit = true;
            if(!Initialized)
            {
                if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
                {
                    if( event.key.keysym.sym == SDLK_RETURN)
                        Initialized = true;
                        this->mario.SetVelX();
                }
            }
            
            else
            {
                MarioHandleEvent( event );
            }
		}
		Draw();
	}
}