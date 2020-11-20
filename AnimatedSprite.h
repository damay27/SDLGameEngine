
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "SpriteTexture.h"
#include "Sprite.h"

#include "SDL.h"

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

/*
	Contains information about a sequence of frames.
	
	Members:
		frame_locations : A vector of x and y offsets to each frame in the sequence.
		Keep in mind that these are measured in frames no pixels. So if you are trying to
		access the third frame of the second row you would set the location to (2, 1).
		Zero indexing is used.

		frame_delay : The delay in ms for how long each frame will stay on.
*/
struct FrameSequence {
	std::vector < std::pair<int, int> > frame_locations;
	int frame_delay;
};

class AnimatedSprite : public Sprite
{
	int frame_width, frame_height;
	int frame_index;
	int sequence_index;
	Uint32 last_draw_time;

	std::unordered_map<std::string, struct FrameSequence>::const_iterator current_sequence_iter;
	std::unordered_map<std::string, struct FrameSequence> sequence_map;


public:
		AnimatedSprite(SpriteTexture *texture, SDL_Renderer* render_context, float pos_x, float pos_y, unsigned int width, unsigned int height, int frame_width, int frame_height);

		/*
			Sets the size of a animation frame on the sprite sheet. This is different
			from the size of the object on screen.

			Parameters:
				width : Width of the frame.
				height : Height of the frame.
		*/
		void set_frame_size(int width, int height);

		/*
			Gets the size of a animation frame on the sprite sheet. This is different
			from the size of the object on screen.

			Parameters:
				width : Width of the frame. The value is loaded into this variable.
				height : Height of the frame. The value is loaded into this variable.
		*/
		void get_frame_size(int &width, int &height);

		/*
			Add an animation sequence. Once added this sequence of frames can be selcectd
			for playback.

			Parameters:
				name : String containg the sequence name. This is how you will select the
				sequence later.
				sequence : Reference to a sequence struct.
		*/
		void add_sequence(std::string name, struct FrameSequence &sequence);

		/*
			Select the sequence to play using its name.

			Parameters:
				name : The name of the sequence being selected.
		*/
		int select_sequence(std::string name);

		/*
			Update the animation. This will move to the next frame in needed.
		*/
		void update_frame();

};

#endif