#include <iostream>
#include"game.hpp"

using namespace std;


int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    //Initialize the game
    Game game;
    
    
    //Game loop
    while(game.running()){
        //Update the Game
        game.Update();
        
        
        //Render the game
        game.Render();
    }

    //End of the app
    return 0;
}