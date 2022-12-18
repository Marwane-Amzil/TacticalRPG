#pragma once

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <SFML/Graphics/Rect.hpp> // sf::IntRect
#include <SFML/System/Time.hpp> // sf::Time
#include <vector> // std::vector

namespace sf
{
	class Texture;
}

namespace gui
{
	class Animation
	{
	public:

		explicit Animation(const sf::Texture* texture = nullptr);

		inline ~Animation() noexcept = default;

		const sf::Texture* getTexture() const;

		const sf::IntRect& getFrame(size_t index) const;
		
		const sf::IntRect& getCurrentFrame() const;

		size_t getCurrentFrameIndex() const;

		constexpr size_t getFrameCount() const;
		
		bool isPlaying() const;

		bool isLooping() const;
		
		void addFrame(const sf::IntRect& frame);

		void addFrame(int x, int y, int width, int height);
		
		void setTexture(const sf::Texture* texture);

		void setLoop(bool loop);

		void pause();

		void play();

		void stop();

		void update(sf::Time elapsed_time);
		
	private:

		std::vector<sf::IntRect> _frames; // The frames of the animation
		const sf::Texture* _texture;	  // The texture of the animation
		sf::Time _frame_time;			  // The time between each frame
		sf::Time _current_time;			  // The current time
		size_t _current_frame;			  // The current frame of the animation
		bool _is_playing;				  // Is the animation playing
		bool _is_looping;				  // Is the animation looping
	};
}

#endif // !__ANIMATION_H__