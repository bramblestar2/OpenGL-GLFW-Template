#pragma once
#include "EventHandler.h"

class Events : public EventHandler
{
	struct Bundled
	{
		EventHandler::events event;
		EventTypes type;
	};

public:
	Events();
	~Events();

	EventTypes getType() const;

	bool pollEvents();
	void setEventWindow(GLFWwindow* window);

	Events::Bundled operator->();
private:
	EventHandler handler;
};

