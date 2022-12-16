#include "Camera.h"

Camera::Camera(const Vec2f _Size, const Vec3f _Pos)
{
	cameraSize = _Size;
	cameraSpeed = 0.5f;

	view = glm::mat4(1.f);

	cameraPos = glm::vec3(_Pos.x, _Pos.y, _Pos.z);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(cameraPos - cameraTarget);

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	updateView();
}

Camera::~Camera()
{

}

void Camera::setClearDepth(const float _Depth)
{
	glClearDepth(_Depth);
}

void Camera::enableDepth()
{
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
}

void Camera::setViewDistance(const float _Near, const float _Far)
{
	viewDistance = Vec2f(_Near, _Far);
}

void Camera::setCameraPosition(const Vec3f _Position)
{
	cameraPos.x = _Position.x;
	cameraPos.y = _Position.y;
	cameraPos.z = _Position.z;
}

void Camera::move(const Vec3f _Direction)
{
	cameraPos.x += _Direction.x;
	cameraPos.y += _Direction.y;
	cameraPos.z += _Direction.z;
}

void Camera::update(const double _DT)
{
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(glm::value_ptr(view));
}

void Camera::updateMovement(const double _DT)
{
	float camSpeed = cameraSpeed * (_DT * 100);
	GLFWwindow* currentWindow;
	currentWindow = glfwGetCurrentContext();
	
	if (glfwGetKey(currentWindow, GLFW_KEY_LEFT_CONTROL))
		camSpeed *= 2;
	else if (glfwGetKey(currentWindow, GLFW_KEY_TAB))
		camSpeed /= 2;

	if (glfwGetKey(currentWindow, GLFW_KEY_W))
	{
		glm::vec3 temp = camSpeed * cameraFront;
		//temp.y = 0;
		cameraPos += temp;
	}
	else if (glfwGetKey(currentWindow, GLFW_KEY_S))
	{
		glm::vec3 temp = camSpeed * cameraFront;
		//temp.y = 0;
		cameraPos -= temp;
	}
	if (glfwGetKey(currentWindow, GLFW_KEY_A))
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * camSpeed;
	else if (glfwGetKey(currentWindow, GLFW_KEY_D))
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * camSpeed;

	if (glfwGetKey(currentWindow, GLFW_KEY_SPACE))
		cameraPos.y += camSpeed;
	else if (glfwGetKey(currentWindow, GLFW_KEY_LEFT_SHIFT))
		cameraPos.y -= camSpeed;
}

void Camera::setSize(const float _X, const float _Y)
{
	setSize(Vec2f(_X, _Y));
}

void Camera::setSize(const Vec2f _Size)
{
	cameraSize = _Size;
	updateView();
}

void Camera::updateDirection()
{
	//glm::vec3 direction;
	//direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	//direction.y = sin(glm::radians(pitch));
	//direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	//cameraFront = glm::normalize(direction);
}

void Camera::updateView()
{
	glViewport(0.0f, 0.0f, cameraSize.x, cameraSize.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)cameraSize.x / (float)cameraSize.y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
}