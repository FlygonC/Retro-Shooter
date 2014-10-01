#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "StateMachine.h"
#include "MainMenuState.h"

extern const int screenWidth = 800;
extern const int screenHeight = 600;

int main( int argc, char* argv[] )
{	
	Initialise(screenWidth, screenHeight, false, "Plane Game");
	
    SetBackgroundColour(SColour(0, 30, 100, 255));

	bool GameFinished = false;

	StateMachine state;
	state.PushState(new MainMenuState);

    //Game Loop
    do {
        ClearScreen();

		float DeltaT = GetDeltaTime();

		state.Update(DeltaT);
		state.Draw();

		if (IsKeyDown(256)) {
			GameFinished = true;
		}

    } while(!FrameworkUpdate() && GameFinished == false);

	//Memory clean up
	

    Shutdown();

    return 0;
}
