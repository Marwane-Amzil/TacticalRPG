#pragma once

#include "State.hpp"

#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

namespace sf
{
	class RenderWindow;
}

class StateMachine
{
public:
	StateMachine();

	void run(std::unique_ptr<State> state);

	void nextState();
	void lastState();

	void update();
	void draw();

	[[nodiscard]] bool running() const;
	void quit();

	/*
	template <typename T>
	static std::unique_ptr<T> build(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
	*/
	
	template <typename _Ty, typename... _Args>
	static std::unique_ptr<_Ty> build(_Args&&... argv);

private:
	// The stack of states
	std::stack<std::unique_ptr<State>> m_states;

	bool m_resume;
	bool m_running;
};

/*
template <typename T>
std::unique_ptr<T> StateMachine::build(StateMachine& machine, sf::RenderWindow& window, bool replace)
{
	auto new_state = std::unique_ptr<T>{ nullptr };

	try
	{
		new_state = std::make_unique<T>(machine, window, replace);
	}
	catch(std::runtime_error& exception)
	{
		std::cout << "Creation of new state was unsuccessful\n";
		std::cout << exception.what() << std::endl;
	}

	return new_state;
}
*/

template<typename _Ty, typename ..._Args>
inline std::unique_ptr<_Ty> StateMachine::build(_Args&&... argv)
{
	auto new_state = std::unique_ptr<_Ty>{ nullptr };

	try
	{
		new_state = std::make_unique<_Ty>(std::forward<_Args>(argv)...);
	}
	catch (std::runtime_error& exception)
	{
		std::cout << "Creation of new state was unsuccessful\n";
		std::cout << exception.what() << std::endl;
	}

	return new_state;
}