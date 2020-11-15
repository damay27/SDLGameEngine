
#ifndef SPRIETEXTURE_H
#define SPRIETEXTURE_H

#include "SDL.h"
#include <string>


class SpriteTexture
{
	SDL_Texture* texture;
	//SDL_Rect texture_sub_rect, draw_rect;
	SDL_Rect texture_sub_rect;
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
		Sets the region of the texture that will be drawn.

		Parameters:
			x : Horizontal location of the rectangle origin.
			y : Vertical location of the rectangle origin.
			w : Width of the rectangle.
			h : Height of the rectangle.

	*/
	void set_sub_rect(int x, int y, int w, int h);

	/*
		Sets the region of the texture that will be drawn.

		Parameters:
			sub_rect : SDL_Rectangle object that defines the region that will be drawn.
	*/
	void set_sub_rect(SDL_Rect sub_rect);

	/*
		Sets location and size of the sprite when it is drawn on screen.

		Parameters:
			x : Horizontal location of the rectangle origin.
			y : Vertical location of the rectangle origin.
			w : Width of the rectangle.
			h : Height of the rectangle.

	*/
	//void set_draw_rect(int x, int y, int w, int h);

	///*
	//	Sets location and size of the sprite when it is drawn on screen.

	//	Parameters:
	//		draw_rect : SDL_Rectangle object that defines the region that will be drawn.
	//*/
	//void set_draw_rect(SDL_Rect draw_rect);

	/*
		Returns the rectangle that defines the subsection of the texture that will be drawn.

		Return:
			Pointer to the internal rectangle object.
	*/
	SDL_Rect* get_sub_rect();

	/*
		Returns the rectangle that defines the location and size of the sprite when it is drawn.

		Return:
			Pointer to the internal rectangle object.
	*/
	/*SDL_Rect* get_draw_rect();*/

	/*
		Returns a pointer to the sprite textue.

		Return:
			Pointer to internal textue object.
	*/
	SDL_Texture* get_texture();

	/*
		Sets the position of the sprite on screen.

		Parameters:
			x : Horizontal location.
			y : Vertical location.
	*/
	//void set_position(int x, int y);

	///*
	//	Moves the sprite to a new location on screen.

	//	Parameters:
	//		x : Movement along the horizontal axis.
	//		y : Movement along the vertical axis.

	//*/
	//void move(int x, int y);

	///*
	//	Sets the size of the sprite on screen.

	//	Parameters:
	//		w : Horizontal size.
	//		h : Vertical size.
	//*/
	//void set_dimensions(int w, int h);

	/*
		Retreives the width and height of the textue. This is the width and
		height of the entire texture, NOT the sub-section that is drawn.
	*/
	void get_texture_resolution(int &width, int &height);

};

#endif