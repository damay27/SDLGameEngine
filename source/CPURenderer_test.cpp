//#include <iostream>
//
//#define SDL_MAIN_HANDLED 
//#include <SDL.h>
//#include <SDL_image.h>
//
//#include "CPURenderer.h"
//
//int global_init(int sdl_flags, int img_flags) {
//	//Initialize SDL
//	if (SDL_Init(sdl_flags) != 0) {
//		std::cout << "Failed to initialize SDL" << std::endl;
//		return -1;
//	}
//
//	//Initialize the image loader
//	if (IMG_Init(img_flags) != img_flags) {
//		std::cout << "Failed to initialize image loading library" << std::endl;
//		SDL_Quit();
//		return -1;
//	}
//}
//
//void global_quit() {
//	SDL_Quit();
//	IMG_Quit();
//}
//
//int main() {
//
//	global_init(SDL_INIT_VIDEO, IMG_INIT_PNG | IMG_INIT_JPG);
//
//	CPURenderer cpu_render("damay", 640, 480, false);
//
//	if (cpu_render.is_ready() == false) {
//		global_quit();
//		return -1;
//	}
//
//	SDL_Surface* image = IMG_Load("./test.png");
//	if (image == NULL) {
//		std::cout << "Error loading image" << std::endl;
//		global_quit();
//		return -1;
//	}
//
//	SDL_Rect image_pos;
//	image_pos.x = 0;
//	image_pos.y = 0;
//
//	bool close = false;
//	while (!close) {
//		SDL_Event event;
//		while (SDL_PollEvent(&event) == 1) {
//			if (event.type == SDL_QUIT) {
//				close = true;
//			}
//		}
//
//		cpu_render.clear();
//		cpu_render.draw(image, NULL, image_pos.x, image_pos.y);
//		cpu_render.render();
//		SDL_Delay(50);
//
//		image_pos.x += 1;
//		image_pos.y += 1;
//	}
//
//
//	SDL_FreeSurface(image);
//	global_quit();
//
//	return 0;
//}