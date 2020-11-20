
#ifndef SPRIETEXTURE_H
#define SPRIETEXTURE_H

#include "SDL.h"
#include <string>


class SpriteTexture
{
	SDL_Texture* texture;
	//SDL_Rect texture_sub_rect, draw_rect;
	int texture_x_resolution, texture_y_resolution;

public:

	/*
		Create a sprite with the given rendering context using the image loaded from the file.

		Parameters:
			file_path : String that contains the path to the file to be loaded.
			render_context. Pointer to the renderer for the window that the sprite will be drawn to.
	*/
	SpriteTexture(std::string file_path, SDL_Renderer* render_context);


	/*
		Frees the texture object.
	*/
	~SpriteTexture();

	/*
		Returns a pointer to the sprite textue.

		Return:
			Pointer to internal textue object.
	*/
	SDL_Texture* get_texture();

	/*
		Retreives the width and height of the textue. This is the width and
		height of the entire texture, NOT the sub-section that is drawn.
	*/
	void get_texture_resolution(int &width, int &height);

};

#endif