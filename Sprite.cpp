#include "Sprite.h"
#include "SDL.h"

Sprite::Sprite(std::string path, SDL_Renderer* render_context, float pos_x, float pos_y, unsigned int width, unsigned int height) :
	world_x(pos_x), world_y(pos_y), sprite_width(width), sprite_height(height), sprite_texture(path, render_context) {}

void Sprite::move(float x, float y) {
	this->world_x += x;
	this->world_y += y;
}

void Sprite::scale(float x, float y) {
	this->sprite_width = (unsigned int) (this->sprite_width * x);
	this->sprite_height = (unsigned int) (this->sprite_height * y);
}

void Sprite::set_position(float x, float y) {
	this->world_x = x;
	this->world_y = y;
}

void Sprite::set_dimensions(unsigned int& w, unsigned int& h) {
	this->sprite_width = w;
	this->sprite_height = h;
}

void Sprite::get_position(float& x, float& y) {
	x = this->world_x;
	y = this->world_y;
}

void Sprite::get_dimensions(unsigned int& w, unsigned int& h) {
	w = this->sprite_width;
	h = this->sprite_height;
}

SpriteTexture* Sprite::get_texture() {
	return &(this->sprite_texture);
}
