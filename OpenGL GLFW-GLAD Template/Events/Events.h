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

	Bundled getEvent();
	EventHandler::events event() const;
	EventTypes type() const;

	bool pollEvents();
	void setEventWindow(GLFWwindow* window);

private:
	EventHandler handler;
};

