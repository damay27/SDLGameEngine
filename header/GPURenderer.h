#ifndef GPURENDERER_H
#define GPURENDERER_H

#include <SDL.h>
#include "SpriteTexture.h"

class GPURenderer
{
	SDL_Window* window;
	SDL_Renderer* window_renderer;

	bool ready;

public:

	/*
		Creates a hardware accelerated rendering object.

		Parameters:
			window_name : String that will be used as the name of the renderers window.
			width : Width of the window. When full_screen is true this sets the monitor resulotion.
			height : Height of the window. When full_screen is true this sets the monitor resulotion.
			full_screen : Controls if the window will be full screen.
			clear_color : Color that is drawn to the screen with it is cleard.
	*/
	GPURenderer(std::string window_name, int width, int height, bool full_screen, SDL_Color clear_color = { 0, 0, 0, 0 });

	/*
		Destructor responsible for destroying both the window and the renderer objects.
	*/
	~GPURenderer();

	/*
		Draws the given texture or texture subsection to the screen.
		
		Parameters:
			draw_texture : The texture object to draw.
			texture_sub_section : Rectangle representing the sub-region of the input texture to draw.
			draw_rect : Rectangle that sets the position and size of the texture when it is draw on the screen

		Return:
			0 on success negative value on failure.
	*/
	int draw(SDL_Texture* draw_texture, SDL_Rect* texture_sub_section, SDL_Rect* draw_rect);


	/*
		Draws the sprite texture object ot the screen.

		Parameters:
			sprite_texture : SpriteTexture object to draw.

		Return:
			0 on success negative value on failure.
	*/
	//int draw(SpriteTexture& sprite_texture);


	/*
		Responsible for swaping the front and back rendering buffers.
	*/
	void render();

	/*
		Clears the screen to the color spcified in either the constructor or set_clear_color function.

		Return:
			0 on success negative value on failure.
	*/
	int clear();

	/*
		Parameters:
			color : The color value that will be used is subsequent calls to clear().

		Return:
			0 on success negative value on failure.
	*/
	int set_clear_color(SDL_Color color);

	/*
		Returns the status of the object. Indicates if the object was initialized correctly.

		Returns:
			true when the object is ready, false otherwise.
	*/
	bool is_ready();

	/*
		Retreivs a pointer to the internal SDL_Renderer object.

		Returns:
			Pointer to internal SDL_Renderer object. This value may be NULL if the object was
			not configured correctly.
	*/
	SDL_Renderer* get_render_context();

};

#endif