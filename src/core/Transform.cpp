#include "Transform.h"


	void Transform::setPosition(const glm::vec3& pos) {
		this->position = pos;
	}

	void Transform::setRotation(const glm::quat& rot) {
		this->rotation = rot;
	}

	void Transform::setScale(const glm::vec3& scl) {
		this->scale = scl;
	}

	glm::vec3 Transform::getPosition() const {
		return position;
	}

	glm::quat Transform::getRotation() const {
		return rotation;
	}

	glm::vec3 Transform::getScale() const {
		return scale;
	}

	void Transform::translate(const glm::vec3& delta) {
		position += delta;
	}

	void Transform::rotate(float angle, const glm::vec3& axis) {
		rotation = glm::normalize(glm::angleAxis(glm::radians(angle), glm::normalize(axis)) * rotation);
	}

	void Transform::scaleBy(const glm::vec3& factor) {
		scale *= factor;
	}

	glm::mat4 Transform::getModelMatrix() const{
		glm::mat4 trans = glm::translate(glm::mat4(1.0f), position);
		glm::mat4 rot = glm::toMat4(rotation);
		glm::mat4 scl = glm::scale(glm::mat4(1.0f), scale);
		return trans * rot * scl;
	}