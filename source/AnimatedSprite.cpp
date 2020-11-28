#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SpriteTexture* texture, float pos_x, float pos_y, unsigned int width, unsigned int height, int frame_width, int frame_height) :
	Sprite(texture, pos_x, pos_y, width, height), frame_width(frame_width), frame_height(frame_height), frame_index(0), sequence_index(0), last_draw_time(0)
{
	this->set_sub_rect(0, 0, frame_width, frame_height);
}

void AnimatedSprite::set_frame_size(int width, int height) {
	this->frame_width = width;
	this->frame_height = height;
}

void AnimatedSprite::get_frame_size(int& width, int& height) {
	width = this->frame_width;
	height = this->frame_height;
}

void AnimatedSprite::add_sequence(std::string name, struct FrameSequence& sequence) {
	this->sequence_map.insert( { name, sequence } );
}

int AnimatedSprite::select_sequence(std::string name) {
	std::unordered_map<std::string, struct FrameSequence>::const_iterator iter = this->sequence_map.find(name);

	if (iter == this->sequence_map.end()) {
		return -1;
	}

	this->current_sequence_iter = iter;

	this->frame_index = 0;
	this->last_draw_time = 0;
	
	return 0;

}

void AnimatedSprite::update_frame() {
	std::pair<int, int> frame_location;
	int frame_count;
	unsigned int frame_delay;
	Uint32 current_time;

	//Get the time that each frame is visible for the current sequence
	frame_delay = (*current_sequence_iter).second.frame_delay;
	current_time = SDL_GetTicks();

	//Check if its time for the next frame to be drawn.
	if (frame_delay <= current_time - this->last_draw_time) {
		//Load data about the sequence
		frame_count = (*current_sequence_iter).second.frame_locations.size();
		frame_location = (*current_sequence_iter).second.frame_locations.at(this->frame_index);

		//Compute the location of the current frame with in the sprite sheet
		int frame_location_x = frame_location.first * this->frame_width;
		int frame_location_y = frame_location.second * this->frame_height;
		
		//Set the sub rectangle on the sprite sheet/texture
		this->set_sub_rect(frame_location_x, frame_location_y, this->frame_width, this->frame_height);

		//Increment the frame index and wrap it around to zero if needed
		this->frame_index++;
		if (this->frame_index >= frame_count) {
			this->frame_index = 0;
		}

		//Record when this frame was drawn
		this->last_draw_time = current_time;

	}
}