#include "SpriteTexture.h"

#include <SDL.h>
#include <SDL_image.h>

SpriteTexture::SpriteTexture(std::string file_path, SDL_Renderer* render_context) {
	/*this->draw_rect = { 0 };*/
	this->texture_sub_rect = { 0 };
	
	SDL_Surface* image_surface = IMG_Load(file_path.c_str());
	this->texture = SDL_CreateTextureFromSurface(render_context, image_surface);
	this->texture_sub_rect.w = image_surface->w;
	this->texture_sub_rect.h = image_surface->h;
	//this->draw_rect.w = image_surface->w;
	//this->draw_rect.h = image_surface->h;
	this->texture_x_resolution = image_surface->w;
	this->texture_y_resolution = image_surface->h;
	SDL_FreeSurface(image_surface);
}


SpriteTexture::~SpriteTexture() {
	SDL_DestroyTexture(this->texture);
}


void SpriteTexture::set_sub_rect(int x, int y, int w, int h) {
	this->texture_sub_rect.x = x;
	this->texture_sub_rect.y = y;
	this->texture_sub_rect.w = w;
	this->texture_sub_rect.h = h;
}


void SpriteTexture::set_sub_rect(SDL_Rect sub_rect) {
	this->texture_sub_rect = sub_rect;
}


//void SpriteTexture::set_draw_rect(int x, int y, int w, int h) {
//	this->draw_rect.x = x;
//	this->draw_rect.y = y;
//	this->draw_rect.w = w;
//	this->draw_rect.h = h;
//}
//
//
//void SpriteTexture::set_draw_rect(SDL_Rect draw_rect) {
//	this->draw_rect = draw_rect;
//}


SDL_Rect* SpriteTexture::get_sub_rect() {
	return &(this->texture_sub_rect);
}


//SDL_Rect* SpriteTexture::get_draw_rect() {
//	return &(this->draw_rect);
//}


SDL_Texture* SpriteTexture::get_texture() {
	return this->texture;
}


//void SpriteTexture::set_position(int x, int y) {
//	this->draw_rect.x = x;
//	this->draw_rect.y = y;
//}
//
//
//void SpriteTexture::move(int x, int y) {
//	this->draw_rect.x += x;
//	this->draw_rect.y += y;
//}
//
//
//void SpriteTexture::set_dimensions(int w, int h) {
//	this->draw_rect.w = w;
//	this->draw_rect.h = h;
//}


void SpriteTexture::get_texture_resolution(int& width, int& height) {
	width = this->texture_x_resolution;
	height = this->texture_y_resolution;
}