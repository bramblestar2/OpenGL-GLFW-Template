#include "Events.h"

Events::Events()
{
}

Events::~Events()
{
}

Events::Bundled Events::getEvent()
{
	Bundled temp;
	temp.event = handler.current_event();
	temp.type = handler.current_type();
	return temp;
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
