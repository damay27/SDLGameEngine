#ifndef CPURENDERER_H
#define CPURENDERER_H

#include <string>
#include <SDL.h>

class CPURenderer
{
	SDL_Window* window;
	SDL_Surface* window_surface;
	Uint32 clear_color;

	bool ready;


public:

	CPURenderer(std::string window_name, int width, int height, bool full_screen, SDL_Color screen_color = { 0 });
	~CPURenderer();
	//void gpu_render();
	int draw(SDL_Surface* draw_surface, SDL_Rect* sub_section, int x, int y);
	int render();
	int clear();
	int clear(SDL_Color color);
	bool is_ready();
	//SDL_Window* get_window();
};

#endif