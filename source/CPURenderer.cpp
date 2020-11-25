#include "CPURenderer.h"

CPURenderer::CPURenderer(std::string window_name, int width, int height, bool full_screen, SDL_Color screen_color) {

	this->clear_color = 0;
	this->window = NULL;
	this->window_surface = NULL;

	int flags = SDL_WINDOW_SHOWN;
	if (full_screen) {
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	this->window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	if (this->window == NULL) {
		this->ready = false;
		return;
	}

	this->window_surface = SDL_GetWindowSurface(this->window);
	if (this->window_surface == NULL) {
		this->ready = false;
		return;
	}

	this->clear_color = SDL_MapRGB(this->window_surface->format, screen_color.r, screen_color.g, screen_color.b);

	this->ready = true;

}

CPURenderer::~CPURenderer() {
	SDL_DestroyWindow(this->window);
}


int CPURenderer::draw(SDL_Surface* draw_surface, SDL_Rect* sub_section, int x, int y) {
	SDL_Rect position;
	position.x = x;
	position.y = y;
	return SDL_BlitSurface(draw_surface, sub_section, this->window_surface, &position);
}

int CPURenderer::render() {
	return SDL_UpdateWindowSurface(this->window);
}

int CPURenderer::clear() {
	return SDL_FillRect(this->window_surface, NULL, this->clear_color);
}

int CPURenderer::clear(SDL_Color color) {
	Uint32 int_color = SDL_MapRGB(this->window_surface->format, color.r, color.g, color.b);
	return SDL_FillRect(this->window_surface, NULL, int_color);
}

bool CPURenderer::is_ready() {
	return this->ready;
}