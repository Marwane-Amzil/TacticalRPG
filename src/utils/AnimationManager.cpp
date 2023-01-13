#include <utils/AnimationManager.hpp> // AnimationManager declarations
#include <components/AnimationComponent.hpp> // AnimationComponent
#include <schemas/animations.hpp> // schema for animation flatbuffers deserialization
#include <fstream> // std::ifstream

void AnimationManager::load()
{
	std::ifstream infile("assets/data/animations.bin", std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	std::streampos length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* buffer = new char[length];
	infile.read(buffer, length);
	infile.close();

	const auto anim_packages = GetAnimationRoot(buffer)->animations();
	const auto special_anim_packages = GetAnimationRoot(buffer)->specials();

	for (const Animation* const& animimation : *anim_packages)
	{
		const auto frames = animimation->frames();
		std::vector<sf::IntRect> frames_vector;

		for (const Frame* const& frame : *frames)
		{
			const int x = frame->left();
			const int y = frame->top();
			const int width = frame->width();
			const int height = frame->height();
			frames_vector.emplace_back(x, y, width, height);
		}

		_animations.push_back(std::move(frames_vector));
	}

	for (const Set* const& set : *special_anim_packages)
	{
		const auto animations = set->animations();

		for (const Animation* const& animimation : *animations)
		{
			const auto frames = animimation->frames();
			std::vector<sf::IntRect> frames_vector;

			for (const Frame* const& frame : *frames)
			{
				const int x = frame->left();
				const int y = frame->top();
				const int width = frame->width();
				const int height = frame->height();
				frames_vector.emplace_back(x, y, width, height);
			}

			_specials[set->type()->data()][animimation->name()->data()] = std::move(frames_vector);
		}
	}
}

std::vector<AnimationComponent> AnimationManager::getAnimations() const
{
	std::vector<AnimationComponent> animations;

	for (const std::vector<sf::IntRect>& frames : _animations)
	{
		animations.emplace_back(frames, sf::seconds(0.1f));
	}

	return animations;
}

std::vector<AnimationComponent> AnimationManager::getSpecialAnimations(std::string_view type) const
{
	std::vector<AnimationComponent> animations;

	for (const auto& [name, frames] : _specials.at(type.data()))
	{
		animations.emplace_back(frames, sf::seconds(0.1f));
	}

	return animations;
}