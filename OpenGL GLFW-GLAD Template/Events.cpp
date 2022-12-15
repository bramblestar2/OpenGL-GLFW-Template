#include "Events.h"

Events::Events()
{
}

Events::~Events()
{
}

EventTypes Events::getType() const
{
	return handler.current_type();
}

bool Events::pollEvents()
{
	if (!handler.isEmpty())
	{
		handler.pop_event();
		return true;
	}
	else
		return false;
}

void Events::setEventWindow(GLFWwindow* window)
{
	handler.setup_events(window);
}

Events::Bundled Events::operator->()
{
	Bundled temp;
	temp.event = handler.current_event();
	temp.type = handler.current_type();
	return temp;
}
