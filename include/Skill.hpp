#pragma once

#ifndef __SKILL_H__
#define __SKILL_H__

#include <vector> // std::vector
#include <Position.hpp>

/**
* @brief The Effect / Character / Grid / Position class.Forward declared to avoid recursive includes in some files when it's not needed.
* Since our use of these classes require polymorphism, we need to use pointers to Effects instead of
* actual entity objects.
*/
class Effect;
class Character;
class Grid;
class Position;

/*
* @brief The Skill class represents the skills of the different character. It is the base class of different classes. 
*/
class Skill
{
public:
		
	/**
	* @brief Default constructor. Initialize a skill with a multiplier, a range, a character and an effect.
	*/
	explicit Skill(int multiplier, int range, Character* character, Effect *effect = nullptr);
	/**
	* @brief Skill destructor. Explicitly defaulted (~Skill() = default)
	*/
	inline virtual ~Skill() noexcept = default;
	/**
	* @brief method that returns the private attribut of the SKill classes (multiplier).
	*/
	int getMultiplier() const;
	/**
	*@brief method that returns the private attribut of the Skill classes (range).
	*/
	int getRange() const;
	/**
	*@brief method that returns the private attribut of the Skill classes (effect). 
	* An effect can exist or be nullptr.
	*/
	const Effect* getEffect() const;
	/**
	*@brief method that returns the private attribut of the Skill classes (Owner).
	* A skill can have 1 Owner. But an Owner can have different skills. 
	* The Owner is the one that activates the different classes.
	*/
	Character* getOwner() const;


	
	/**
	* @brief Activate method is the method that triggers the damage of the skill.
	*/
	virtual void activate(Grid& grid, Character* target) const = 0;
	
	virtual std::vector<Position> getPossibleZones(const Grid& grid) const = 0;

	virtual std::string getName() const = 0;

	virtual bool canActivate(Grid& grid, Character* target) const = 0;


	/**
	*
	*/
	//virtual bool canActivate(Grid* grid) const = 0;

	
protected:
		
	int _multiplier;
	int _range;
	Effect *_effect;
	Character *_character;
};

#endif // !__SKILL_H__ 
