#ifndef CAMERA_H
#define CAMERA_H

#include "GPURenderer.h"
#include "Sprite.h"
#include "SDL.h"
#include <string>

//This is the "default" resolution
#define BASE_HORIZONTAL_RES 1920
#define BASE_VERTICAL_RES 1080

class Camera
{
	GPURenderer gpu_render;
	float world_x, world_y;
	int window_width, window_height;
	int window_center_x, window_center_y;
	float zoom_factor;
	float pixels_per_unit;


public:
	Camera(std::string window_name, int window_width, int window_height, bool full_screen, SDL_Color clear_color = { 0 });
	
	void move(float x, float y);
	void set_position(float x, float y);
	void change_zoom_factor(float zoom);
	void set_zoom_factor(float zoom);

	int draw(Sprite& sprite);

	int draw_screen_space(Sprite& sprite);

	SDL_Renderer* get_render_context();
};

#endif