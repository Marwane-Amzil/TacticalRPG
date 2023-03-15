#include <GUI/game/Animation.hpp> // Animation
#include <SFML/Graphics/Texture.hpp> // sf::Texture

namespace gui
{
	Animation::Animation()
		: _frames(), _frame_time(sf::seconds(0.1f)), _current_time(), _current_frame(0), _is_playing(false), _is_looping(false) {}

	const sf::IntRect& Animation::getFrame(size_t index) const
	{
		return _frames[index];
	}

	const sf::IntRect& Animation::getCurrentFrame() const
	{
		return _frames[_current_frame];
	}

	size_t Animation::getCurrentFrameIndex() const
	{
		return _current_frame;
	}

	size_t Animation::getFrameCount() const
	{
		return _frames.size();
	}

	bool Animation::isPlaying() const
	{
		return _is_playing;
	}

	bool Animation::isLooping() const
	{
		return _is_looping;
	}

	void Animation::addFrame(const sf::IntRect& frame)
	{
		_frames.push_back(frame);
	}

	void Animation::addFrame(int x, int y, int width, int height)
	{
		_frames.emplace_back(x, y, width, height);
	}

	void Animation::setSpeed(float speed)
	{
		_frame_time = sf::seconds(1.0f / speed);
	}

	void Animation::setLoop(bool loop)
	{
		_is_looping = loop;
	}

	void Animation::pause()
	{
		_is_playing = false;
	}

	void Animation::play()
	{
		_is_playing = true;
	}

	void Animation::stop()
	{
		_is_playing = false;
		_current_frame = 0;
	}

	void Animation::update(sf::Time elapsed_time)
	{
		if (_is_playing)
		{
			_current_time += elapsed_time;

			if (_current_time >= _frame_time)
			{
				_current_time = sf::Time::Zero;
				_current_frame++;

				if (_current_frame >= _frames.size())
				{
					if (!_is_looping)
					{
						stop();
					}
					else
					{
						_current_frame = 1;
					}
				}
			}
		}
	}
}
