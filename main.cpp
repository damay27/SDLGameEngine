#include <iostream>

#define SDL_MAIN_HANDLED 
#include <SDL.h>
#include <SDL_image.h>


#include "Camera.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include <vector>

int global_init(int sdl_flags, int img_flags) {
	//Initialize SDL
	if (SDL_Init(sdl_flags) != 0) {
		std::cout << "Failed to initialize SDL" << std::endl;
		return -1;
	}

	//Initialize the image loader
	if (IMG_Init(img_flags) != img_flags) {
		std::cout << "Failed to initialize image loading library" << std::endl;
		SDL_Quit();
		return -1;
	}

	return 0;
}

void global_quit() {
	SDL_Quit();
	IMG_Quit();
}

int main() {

	global_init(SDL_INIT_VIDEO, IMG_INIT_PNG | IMG_INIT_JPG);

	SDL_Color clear_color = { 255, 0, 0, 0 };
	Camera camera("damay", 1280, 720, false, clear_color);

	SpriteTexture sprite_texture("./test2.png", camera.get_render_context());

	AnimatedSprite sprite("./sprite_sheet_test.png", camera.get_render_context(), 1, 1, 100, 100, 100, 100);
	FrameSequence seq;
	seq.frame_locations = std::vector<std::pair<int, int>>({ {0,0}, {1, 1}, {2,1} });
	seq.frame_delay = 500;
	sprite.add_sequence("test", seq);
	sprite.select_sequence("test");
	camera.move(0, 0);

	bool close = false;
	while (!close) {
		SDL_Event event;
		while (SDL_PollEvent(&event) == 1) {
			if (event.type == SDL_QUIT) {
				close = true;
			}
		}

		SDL_Delay(50);
		sprite.update_frame();
		camera.draw(sprite);
		camera.render();

		camera.move(-1, -1);
	}

	global_quit();

	return 0;
}

//#include <unordered_map>
//#include <utility>
//#include <string>
//#include <iostream>
//
//int main() {
//	std::unordered_map<std::string, std::string> map;
//	map.insert(std::make_pair<std::string, std::string>("key", "pair"));
//	map.insert({"key", "pair"});
//
//	std::pair<const std::string, std::string> p = *(map.find("key"));
//
//	std::cout << (*(map.find("key"))).second << std::endl;
//}