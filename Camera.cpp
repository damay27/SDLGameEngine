#include "Camera.h"
#include "SpriteTexture.h"

Camera::Camera(std::string window_name, int window_width, int window_height, bool full_screen, SDL_Color clear_color) :
	gpu_render(window_name, window_width, window_height, full_screen, clear_color), world_x(0), world_y(0), zoom_factor(1.0),
	window_width(window_width), window_height(window_height)
{
	this->window_center_x = window_width / 2;
	this->window_center_y = window_height / 2;
	
	this->pixels_per_unit = 100;
}

void Camera::move(float x, float y) {
	this->world_x += x;
	this->world_y += y;
}

void Camera::set_position(float x, float y) {
	this->world_x = x;
	this->world_y = y;
}

void Camera::change_zoom_factor(float zoom) {
	this->zoom_factor += zoom;
}

void Camera::set_zoom_factor(float zoom) {
	this->zoom_factor = zoom;
}

int Camera::draw(Sprite& sprite) {
	float x_global, y_global;
	unsigned int width, height;
	sprite.get_position(x_global, y_global);
	sprite.get_dimensions(width, height);


	/*unsigned int x_camera_space = (unsigned int) ( (x_global - this->world_x) * this->zoom_factor * this->horizontal_res_scale_factor );
	unsigned int y_camera_space = (unsigned int) ( (y_global - this->world_y) * this->zoom_factor * this->vertical_res_scale_factor );*/

	//float x_camera_space = (x_global - this->world_x);
	//float y_camera_space = (y_global - this->world_y);

	//x_camera_space = ((x_camera_space - this->window_center_x) * this->zoom_factor) + this->window_center_x;
	//y_camera_space = ((y_camera_space - this->window_center_y) * this->zoom_factor) + this->window_center_y;

	//SDL_Rect draw_rect;
	//draw_rect.x = (int)(x_camera_space * this->resolution_scale_factor);
	//draw_rect.y = (int)(y_camera_space * this->resolution_scale_factor);
	///*draw_rect.x = (int) (x_camera_space * this->horizontal_res_scale_factor);
	//draw_rect.y = (int)(y_camera_space * this->vertical_res_scale_factor);*/
	////draw_rect.w = (unsigned int) (width * this->zoom_factor * this->horizontal_res_scale_factor);
	////draw_rect.h = (unsigned int) (height * this->zoom_factor * this->vertical_res_scale_factor);
	//draw_rect.w = (unsigned int)(width * this->zoom_factor * 1);
	//draw_rect.h = (unsigned int)(height * this->zoom_factor * 1);

	float x_camera_space = (x_global - this->world_x);
	float y_camera_space = (y_global - this->world_y);

	x_camera_space = ((x_camera_space - this->window_center_x) * this->zoom_factor) + this->window_center_x;
	y_camera_space = ((y_camera_space - this->window_center_y) * this->zoom_factor) + this->window_center_y;

	SDL_Rect draw_rect;
	draw_rect.x = (int)(x_camera_space * this->pixels_per_unit);
	draw_rect.y = (int)(y_camera_space * this->pixels_per_unit);
	/*draw_rect.x = (int) (x_camera_space * this->horizontal_res_scale_factor);
	draw_rect.y = (int)(y_camera_space * this->vertical_res_scale_factor);*/
	//draw_rect.w = (unsigned int) (width * this->zoom_factor * this->horizontal_res_scale_factor);
	//draw_rect.h = (unsigned int) (height * this->zoom_factor * this->vertical_res_scale_factor);
	draw_rect.w = (unsigned int)(width * this->zoom_factor * this->pixels_per_unit);
	draw_rect.h = (unsigned int)(height * this->zoom_factor * this->pixels_per_unit);

	SpriteTexture* sprite_texture = sprite.get_texture();

	this->gpu_render.clear();

	this->gpu_render.draw(sprite_texture->get_texture(), sprite_texture->get_sub_rect(), &draw_rect);

	this->gpu_render.render();
	return -1;
	//NOTE: Fix the above mess
}

SDL_Renderer* Camera::get_render_context() {
	return this->gpu_render.get_render_context();
}