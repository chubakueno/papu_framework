#include <SDL\SDL.h>
#include "MainGame.h"

int main(int argc,char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	MainGame mainge;
	mainge.run();
	return 0;
}