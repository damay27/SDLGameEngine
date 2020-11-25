#ifndef CAMERA_H
#define CAMERA_H

#include "GPURenderer.h"
#include "Sprite.h"
#include "SDL.h"
#include <string>

//This is the "default" resolution
#define BASE_HORIZONTAL_RES 1920
#define BASE_VERTICAL_RES 1080

class Camera : public GPURenderer
{
	//GPURenderer gpu_render;
	int world_x, world_y;
	int window_width, window_height;


public:
	Camera(std::string window_name, int window_width, int window_height, bool full_screen, SDL_Color clear_color = { 0 });
	
	void move(int x, int y);
	void set_position(int x, int y);

	int draw(Sprite& sprite);

	int draw_screen_space(Sprite& sprite);
};

#endif