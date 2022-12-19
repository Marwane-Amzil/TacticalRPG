#include <utils/AnimationManager.hpp>
#include <schemas/animations.hpp>
#include <GUI/game/Animation.hpp>
#include <fstream>

utils::AnimationManager::AnimationManager()
	: _animations() {}

utils::AnimationManager::~AnimationManager() noexcept
{
	for (auto& [type, animations] : _animations)
	{
		for (auto& [name, animation] : animations)
		{
			delete animation;
		}
	}
}

void utils::AnimationManager::loadAnimations()
{
	std::ifstream infile("assets/data/animations.bin", std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	std::streampos length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* buffer = new char[length];
	infile.read(buffer, length);
	infile.close();

	auto animations_list = GetAnimationSetRoot(buffer)->set();

	for (size_t i = 0; i < animations_list->size(); i++)
	{
		auto animations = animations_list->Get(i)->animations();
		
		for (size_t j = 0; j < animations->size(); j++)
		{
			gui::Animation* animation = new gui::Animation;
			
			for (size_t k = 0; k < animations->Get(j)->frames()->size(); k++)
			{
				animation->addFrame(animations->Get(j)->frames()->Get(k)->left(), animations->Get(j)->frames()->Get(k)->top(), animations->Get(j)->frames()->Get(k)->width(), animations->Get(j)->frames()->Get(k)->height());
			}

			_animations[animations_list->Get(i)->type()->data()][animations->Get(j)->name()->data()] = animation;
		}
	}

	delete[] buffer;
}

const std::map<std::string, gui::Animation*>& utils::AnimationManager::get(const std::string& type) const
{
	return _animations.at(type);
}

const gui::Animation& utils::AnimationManager::get(const std::string& type, const std::string& name) const
{
	return *_animations.at(type).at(name);
}