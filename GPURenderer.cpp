#include "GPURenderer.h"

GPURenderer::GPURenderer(std::string window_name, int width, int height, bool full_screen, SDL_Color clear_color) {

	//Make sure the internal values have default values
	this->window = NULL;
	this->window_renderer = NULL;
	this->ready = false;

	//Set the flags based on whether it should be full screen
	int flags = SDL_WINDOW_SHOWN;
	if (full_screen) {
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	//Create the SDL window and check for errors
	this->window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	if (this->window == NULL) {
		this->ready = false;
		return;
	}

	//Create the renderer object and check for errors
	this->window_renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (this->window_renderer == NULL) {
		this->ready = false;
		return;
	}

	//Set the windows clear color
	int status = this->set_clear_color(clear_color);
	if (status == -1) {
		this->ready = false;
		return;
	}

	//If we reached this point then the object was configured correctly and is now ready.
	this->ready = true;

}

GPURenderer::~GPURenderer() {
	//Destroy both the window and the renderer.
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->window_renderer);
}


int GPURenderer::draw(SDL_Texture* draw_texture, SDL_Rect* texture_sub_section, SDL_Rect* draw_rect) {
	return SDL_RenderCopy(this->window_renderer, draw_texture, texture_sub_section, draw_rect);
}

int GPURenderer::draw(SpriteTexture& sprite_texture) {
	return SDL_RenderCopy(this->window_renderer, sprite_texture.get_texture(), sprite_texture.get_sub_rect(), sprite_texture.get_draw_rect());
}


void GPURenderer::render() {
	SDL_RenderPresent(this->window_renderer);
}


int GPURenderer::clear() {
	return SDL_RenderClear(this->window_renderer);
}


int GPURenderer::set_clear_color(SDL_Color color) {
	return SDL_SetRenderDrawColor(this->window_renderer, color.r, color.g, color.b, color.a);
}


bool GPURenderer::is_ready() {
	return this->ready;
}


SDL_Renderer* GPURenderer::get_render_context() {
	return this->window_renderer;
}