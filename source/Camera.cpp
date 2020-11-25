#include "Camera.h"
#include "SpriteTexture.h"

Camera::Camera(std::string window_name, int window_width, int window_height, bool full_screen, SDL_Color clear_color) :
	GPURenderer(window_name, window_width, window_height, full_screen, clear_color), world_x(0), world_y(0),
	window_width(window_width), window_height(window_height)
{	

}

void Camera::move(int x, int y) {
	this->world_x += x;
	this->world_y += y;
}

void Camera::set_position(int x, int y) {
	this->world_x = x;
	this->world_y = y;
}

int Camera::draw(Sprite& sprite) {
	int x_global, y_global;
	unsigned int width, height;
	sprite.get_position(x_global, y_global);
	sprite.get_resolution(width, height);

	int x_camera_space = (x_global - this->world_x);
	int y_camera_space = (y_global - this->world_y);

	SDL_Rect draw_rect;
	draw_rect.x = (x_camera_space);
	draw_rect.y = (y_camera_space);
	draw_rect.w = (int) (width * (this->window_width/(float)BASE_HORIZONTAL_RES));
	draw_rect.h = (int) (height * (this->window_height / (float)BASE_VERTICAL_RES));

	SpriteTexture* sprite_texture = sprite.get_texture();

	clear();

	return GPURenderer::draw(sprite_texture->get_texture(), sprite.get_sub_rect(), &draw_rect);
}

//int draw_screen_space(Sprite& sprite) {
//
//}
