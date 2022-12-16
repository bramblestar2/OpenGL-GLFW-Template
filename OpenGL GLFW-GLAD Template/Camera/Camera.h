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

	void setClearDepth(const float _Depth);
	void enableDepth();

	glm::vec3 getCameraPosition() const { return cameraPos; }

	void setSize(const float _X, const float _Y);
	void setSize(const Vec2f _Size);

	void setViewDistance(const float _Near, const float _Far);
	void setCameraSpeed(const float _Speed) { cameraSpeed = _Speed; }
	void setCameraPosition(const Vec3f _Position);

	void move(const float _X, const float _Y, const float _Z) { move(Vec3f(_X, _Y, _Z)); }
	void move(const Vec3f _Direction);

	void update(const double _DT);
	void updateMovement(const double _DT);

private:
	void updateDirection();
	void updateView();

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
};