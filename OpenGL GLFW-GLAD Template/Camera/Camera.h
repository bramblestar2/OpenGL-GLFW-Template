#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Essentials/Vec3/Vec3.h"
#include "../Essentials/Vec2/Vec2.h"
//THIS CLASS WILL HANDLE 3D VIEWING

enum class Camera_Movement { FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN };

class Camera
{
public:
	Camera(const Vec2f _Size = Vec2f(), const Vec3f _Cam_Position = Vec3f());
	~Camera();

	void setViewDistance(const Vec2f _View_Distance);
	void setPosition(const glm::vec3 _Position);
	void setSize(const Vec2f _Size);

	void move(const glm::vec3 _Direction);

	void update(); //Updates OpenGL View matrix
private:
	void updateDirection();
	void updateView(); //Updates OpenGL glFustrum

	Vec2f cameraSize;
	//X > Near
	//Y > Far
	Vec2f viewDistance;

	//Camera
	glm::mat4 view;

	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;

	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	float cameraSpeed;
	//

	//
	float yaw, pitch;
	//
};