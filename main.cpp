#include <iostream>

#define SDL_MAIN_HANDLED 
#include <SDL.h>
#include <SDL_image.h>


#include "Camera.h"
#include "Sprite.h"

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
	Camera camera("damay", 500, 500, false, clear_color);

	SpriteTexture sprite_texture("./test2.png", camera.get_render_context());

	//if (gpu_render.is_ready() == false) {
	//	global_quit();
	//	return -1;
	//}

	//SDL_Surface* image = IMG_Load("./test.png");
	//if (image == NULL) {
	//	std::cout << "Error loading image" << std::endl;
	//	global_quit();
	//	return -1;
	//}
	//SDL_Texture* texture = SDL_CreateTextureFromSurface(camera.get_render_context(), image);
	//if (texture == NULL) {
	//	std::cout << "Error creating textue" << std::endl;
	//	global_quit();
	//	return -1;
	//}


	//SDL_Rect image_pos;
	//image_pos.x = 0;
	//image_pos.y = 0;
	//image_pos.w = 100;
	//image_pos.h = 100;

	//sprite_texture.set_position(500, 0);


	Sprite sprite("./test.png", camera.get_render_context(), 1, 1, 100, 100);
	camera.move(0, 0);

	bool close = false;
	while (!close) {
		SDL_Event event;
		while (SDL_PollEvent(&event) == 1) {
			if (event.type == SDL_QUIT) {
				close = true;
			}
		}

		//gpu_render.clear();
		//gpu_render.draw(texture, NULL, &image_pos);
		////gpu_render.draw(sprite_texture);
		//gpu_render.render();
		SDL_Delay(16);

		////sprite_texture.move(0, 2);
		//image_pos.x += 1;
		//image_pos.y += 1;

		camera.draw(sprite);

		/*camera.move(1, 1);*/
		//camera.change_zoom_factor(-.005);
	}


	//SDL_FreeSurface(image);
	global_quit();

	return 0;
}