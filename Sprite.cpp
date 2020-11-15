#include "Sprite.h"
#include "SDL.h"

Sprite::Sprite(std::string path, SDL_Renderer* render_context, int pos_x, int pos_y, int width, int height) :
	SpriteTexture(path, render_context), world_x(pos_x), world_y(pos_y), x_resolution(width), y_resolution(height) {}

void Sprite::move(int x, int y) {
	this->world_x += x;
	this->world_y += y;
}

void Sprite::scale(float x, float y) {
	this->x_resolution *= x;
	this->y_resolution *= y;
}

void Sprite::set_position(int x, int y) {
	this->world_x = x;
	this->world_y = y;
}

void Sprite::set_resolution(unsigned int w, unsigned int h) {
	this->x_resolution = w;
	this->y_resolution = h;
}

void Sprite::get_position(int& x, int& y) {
	x = this->world_x;
	y = this->world_y;
}

void Sprite::get_resolution(unsigned int& w, unsigned int& h) {
	w = this->x_resolution;
	h = this->y_resolution;
}

SpriteTexture* Sprite::get_texture() {
	return this;
}
