#include <GUI/ui/State.hpp>

State::State(StateMachine& machine, sf::RenderWindow &window, const bool replace)
: _machine{ machine }
, _window{ window }
, m_replacing{ replace }
{

}

std::unique_ptr<State> State::next()
{
	return std::move( m_next );
}

bool State::isReplacing() const
{
	return m_replacing;
}
