#include "Camera.h"

Camera::Camera(const Vec2f _Size, const Vec3f _Cam_Position)
{
	cameraSize = _Size;
	cameraSpeed = 0.5f;

	yaw = 0;
	pitch = 0;

	view = glm::mat4(1.f);

	cameraPos = glm::vec3(_Cam_Position.x, _Cam_Position.y, _Cam_Position.z);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(cameraPos - cameraTarget);

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	updateView();
}

Camera::~Camera()
{
}

void Camera::setViewDistance(const Vec2f _View_Distance)
{
	viewDistance = _View_Distance;
}

void Camera::setPosition(const glm::vec3 _Position)
{
	cameraPos = _Position;
}

void Camera::setSize(const Vec2f _Size)
{
	cameraSize = _Size;
	updateView();
}

void Camera::move(const glm::vec3 _Direction)
{
	cameraPos += _Direction;
}

void Camera::update()
{
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(glm::value_ptr(view));
}

void Camera::updateDirection()
{
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}

void Camera::updateView()
{
	glViewport(0.0f, 0.0f, cameraSize.x, cameraSize.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)cameraSize.x / (float)cameraSize.y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
}
