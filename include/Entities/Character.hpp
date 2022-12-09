#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <Entity.hpp> // Entity class
#include <vector> // std::vector

/**
* @brief The Grid class. Forward declared to avoid recursive includes in some files when it's not needed.
* The characters need to know what is in the grid that could block them, such as obstacle or even other
* characters. To do so, we need to pass the play grid as an argument of movements or other actions functions.
* All we need is a reference to this grid so there is no need to indicate a proper implementation of this class
* in the header file.
*/
class Grid;

/**
* @brief The Character class represents any entity that the user can play with. According to the rules,
* this same entity is divided in several other classes (derived) to allow different play styles and strategies.
* Each character (class) has its own gimmicks and stats.
*/
class Character : public Entity
{
public:

	/**
	* @brief Constructor taking 2 position values and a hp value for
	* the base constructor and values for the will and both physical and
	* magical resistance of the character.
	* Initialize a character with a given position and a given hp value.
	* To achieve this, it will call the base class constructor (Entity).
	*
	* @param x: x position
	* @param y: y position
	* @param hp: hp of the character
	* @param player: owner of the character
	* @param will: will of the character
	* @param res_phy: res_phy of the character
	* @param res_mag: res_mag of the character
	* @param magic: magic force of a character
	* @param strength: pure strength of a character
	*/
	Character(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int magic, const int strength);
	/**
	* @brief Method which returns the player who owns the character
	* 
	* @return returns the owner (player) of the character
	*/
	char getPlayer() const;
	/**
	* @brief Method which returns the will of the character
	* 
	* @return returns the will of the character
	*/
	int getWill() const;
	/**
	* @brief Method which returns the physical resistance of a character
	* 
	* @return returns the physical resistance of a character
	*/
	int getResPhy() const;
	/**
	* @brief Method which returns the magical resistance of a character
	*
	* @return returns the magical resistance of a character
	*/
	int getResMag() const;
	/**
	* @brief Method which returns the possibility for a character to move
	* 
	* @return returns movement possibility
	*/
	bool getMove() const;
	/**
	* @brief Method which returns the possibility for a character to perform an action
	*
	* @return returns action possibility
	*/
	bool getAction() const;
	/**
	* @brief Method which returns the possibility for a character to perform an special action
	*
	* @return returns special action possibility
	*/
	bool getSpecialAction() const;
	/**
	 * @brief Get the Magic object
	 * 
	 * @return int 
	 */
	int getMagic() const;
	/**
	 * @brief Get the Strength object
	 * 
	 * @return int 
	 */
	int getStrength() const;	
	/**
	* @brief Method which sets the current will value of the character.
	*
	* @param will: new will value to set
	*/
	void setWill(const int will);
	/**
	* @brief Method which sets the current physical resistance value of the character.
	*
	* @param res_phy: new physical res value to set
	*/
	void setResPhy(const int res_phy);
	/**
	* @brief Method which sets the current magical resistance value of the character.
	*
	* @param res_mag: new magical res value to set
	*/
	void setResMag(const int res_mag);
	/**
	* @brief Method which sets the possibility for a character to move
	*
	* @param can_move: movement possibility
	*/
	void setMove(const bool can_move);
	/**
	* @brief Method which sets the possibility for a character to perform an action
	*
	* @param can_act: action possibility
	*/
	void setAction(const bool can_act);
	/**
	* @brief Method which sets the possibility for a character to perform an special action
	*
	* @param can_sp_act: special action possibility
	*/
	void setSpecialAction(const bool can_sp_act);
	/**
	* @brief Character destructor. Explicitly defaulted (~Character() = default).
	* Marked as virtual to perform proper destruction when the current Character is actually
	* an instance of one of the derived class.
	*/
	virtual ~Character() = default;
	/**
	* @brief Method which returns the list of positions the character can actually move on.
	* It requires the grid to performs check for valid moves such as empty case or not.
	* Marked as virtual to call the proper version of this function for each character (class)
	* since they have different gimmicks.
	* 
	* @param grid: current play grid
	* 
	* @return returns a list of cases where the character can move
	*/
	virtual std::vector<Position> getPossibleMoves(const Grid& grid) const = 0;
	/**
	* @brief Method which returns the list of positions the character can launch a skill.
	* It requires the grid to performs check for valid moves such as empty case or not.
	* Marked as virtual to call the proper version of this function for each character (class)
	* since they have different gimmicks.
	*
	* @param grid: current play grid
	*
	* @return returns a list of cases where the character can perform an action
	*/
	virtual std::vector<Position> getPossibleActions(const Grid& grid) const = 0;

	/** @brief Method which after verifying if there an enemy at the selected position will take his hp 
	*	down depending on the strength or magic of the character attacking and the resistance of the one attacked
	*
	*
	* @param pos 
	*/

protected:

	char _player;
	int _will;
	int _res_phy;
	int _res_mag;
	bool _can_move;
	bool _can_act;
	bool _can_sp_act;
	int _magic;
	int _strength;
	

private:

	// Not mendatory. Reminds of Java calls to base class for the ease of writing.
	// For instance, super(...) calls the base class constructor with the specified parameters.
	// In fact, it calls "Entity(...)".
	typedef Entity super;
};

#endif // !__CHARACTER_H__