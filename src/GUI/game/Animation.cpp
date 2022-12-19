#include <GUI/game/Animation.hpp>
#include <SFML/Graphics/Texture.hpp>

gui::Animation::Animation()
	: _frames(), _frame_time(sf::seconds(0.15f)), _current_time(), _current_frame(0), _is_playing(false), _is_looping(false) {}

const sf::IntRect& gui::Animation::getFrame(size_t index) const
{
	return _frames[index];
}

const sf::IntRect& gui::Animation::getCurrentFrame() const
{
	return _frames[_current_frame];
}

size_t gui::Animation::getCurrentFrameIndex() const
{
	return _current_frame;
}

size_t gui::Animation::getFrameCount() const
{
	return _frames.size();
}

bool gui::Animation::isPlaying() const
{
	return _is_playing;
}

bool gui::Animation::isLooping() const
{
	return _is_looping;
}

void gui::Animation::addFrame(const sf::IntRect& frame)
{
	_frames.push_back(frame);
}

void gui::Animation::addFrame(int x, int y, int width, int height)
{
	_frames.emplace_back(x, y, width, height);
}

void gui::Animation::setLoop(bool loop)
{
	_is_looping = loop;
}

void gui::Animation::pause()
{
	_is_playing = false;
}

void gui::Animation::play()
{
	_is_playing = true;
}

void gui::Animation::stop()
{
	_is_playing = false;
	_current_frame = 0;
}

void gui::Animation::update(sf::Time elapsed_time)
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
				_current_frame = 0;

				if (!_is_looping)
				{
					stop();
				}
				else
				{
					std::reverse(_frames.begin(), _frames.end());
				}
			}
		}
	}
}
