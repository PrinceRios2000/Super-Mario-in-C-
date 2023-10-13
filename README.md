# Super-Mario-in-CPP
Super Mario Game in C++




Instructions for Setting up SDL2 on Mac

Prerequisites:
- Homebrew (https://brew.sh/)

1. Install sdl2 using command \
  brew install sdl2

2. Create root project folder with two folders: include and lib

3. Find directory for sdl2 (will look something like this /usr/local/Cellar/sdl2/2.0.5)

4. Transfer contents of include file in sdl2/2.0.5 over to the include file in your root project folder

5. Transer contents of lib folder in sdl2/2.0.5 over to the lib file in your root project folder

6. Create a makefile and place the following block of code inside file

   make:
     g++ main.cpp -o play -I include -L lib -l SDL2-2.0.0

8. Lastly, to run the game, type in the following command in terminal:

    make game

    and then

   ./play
