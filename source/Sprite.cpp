#include "Sprite.h"
#include "SDL.h"

Sprite::Sprite(SpriteTexture* texture, int pos_x, int pos_y, int width, int height) :
	texture(texture), world_x(pos_x), world_y(pos_y), x_resolution(width), y_resolution(height)
{
	int x_res, y_res;
	this->texture->get_texture_resolution(x_res, y_res);
	this->texture_sub_rect.x = x_res;
	this->texture_sub_rect.x = y_res;
}

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
	return texture;
}

void Sprite::set_sub_rect(int x, int y, int w, int h) {
	this->texture_sub_rect.x = x;
	this->texture_sub_rect.y = y;
	this->texture_sub_rect.w = w;
	this->texture_sub_rect.h = h;
}


void Sprite::set_sub_rect(SDL_Rect sub_rect) {
	this->texture_sub_rect = sub_rect;
}

SDL_Rect* Sprite::get_sub_rect() {
	return &(this->texture_sub_rect);
}
