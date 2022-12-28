#pragma once

#ifndef __HEALER_H__
#define __HEALER_H__

#include <Entities/Characters/MagicCharacter.hpp>
#include <Constants.hpp>

class Healer : public MagicCharacter
{
public:

	/**
	*
	*/
	Healer(const int x, const int y, const char player);
	/**
	*
	*/
	~Healer() = default;

private:

	/**
	*
	*/
	std::vector<Position> getPossibleMoves(const Grid& grid) const override;
	/**
	*
	*/
	std::vector<Position> getPossibleActions(const Grid& grid) const override;
	/**
	*
	*/
	bool equals(const Entity& other) const override;
	/**
	*
	*/
	std::string_view getClass() const override;

private:

	typedef MagicCharacter super;
};

#endif // !__HEALER_H__