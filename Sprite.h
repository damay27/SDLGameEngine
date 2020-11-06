
#ifndef SPRITE_H
#define SPRITE_H

#include "SpriteTexture.h"
#include <string>

class Sprite
{
	SpriteTexture sprite_texture;

	float world_x, world_y;
	unsigned int sprite_width, sprite_height;

public:

	/*
		Initializes the sprite object using the image at the given path and the
		provided rendering context.

		Parameters:
			path : String containing the path to the image file.
			render_context : SDL_Renderer object that is paired with a window.
			pos_x : X position of the sprite.
			pos_y : Y position of the sprite.
			width : Width of the sprite.
			height : Height of the sprite.
	*/
	Sprite(std::string path, SDL_Renderer* render_context, float pos_x, float pos_y, unsigned int width, unsigned int height);

	/*
		Moves the sprite by the given amount.

		Parameters:
			x : Amount to move along the horizontal axis.
			y : Amount to move along the vertical axis.
	*/
	void move(float x, float y);

	/*
		Scales the sprite along each axis.

		Parameters:
			x : Horizontal scale factor.
			y : Vertical scale factor
	*/
	void scale(float x, float y);

	/*
		Sets the world position of the sprite.

		Parameters:
			x : The horizontal location of the sprite.
			y : The vertical position of the sprite.
	*/
	void set_position(float x, float y);

	/*
		Sets the width and height of the sprite.

		Parameters:
			w : Width of the sprite.
			h : Height of the sprite.
	*/
	void set_dimensions(unsigned int& w, unsigned int& h);

	/*
		Retrieves current position of the sprite.

		Parameters:
			x : Referance to the variable to load the horizontal position to.
			y : Referance to the variable to load the vertical position to.
	*/
	void get_position(float& x, float& y);

	/*
		Retrieves current dimensions of the sprite.

		Parameters:
			w : Referance to the variable to load the width of the sprite into.
			h : Referance to the variable to load the height of the sprite into.
	*/
	void get_dimensions(unsigned int& w, unsigned int& h);

	/*
		Returns a pointer to the internal texture.

		Return:
			Pointer to the internal SpriteTexture object.
	*/
	SpriteTexture* get_texture();

};

#endif