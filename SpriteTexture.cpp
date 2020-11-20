#include "SpriteTexture.h"

#include <SDL.h>
#include <SDL_image.h>

SpriteTexture::SpriteTexture(std::string file_path, SDL_Renderer* render_context) {

	SDL_Surface* image_surface = IMG_Load(file_path.c_str());
	this->texture = SDL_CreateTextureFromSurface(render_context, image_surface);
	this->texture_x_resolution = image_surface->w;
	this->texture_y_resolution = image_surface->h;
	SDL_FreeSurface(image_surface);
}


SpriteTexture::~SpriteTexture() {
	SDL_DestroyTexture(this->texture);
}

SDL_Texture* SpriteTexture::get_texture() {
	return this->texture;
}

void SpriteTexture::get_texture_resolution(int& width, int& height) {
	width = this->texture_x_resolution;
	height = this->texture_y_resolution;
}