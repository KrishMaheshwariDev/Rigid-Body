#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/quaternion.hpp>
#include<glm/gtx/quaternion.hpp>

class ITransform {
public:
	virtual void translate(const glm::vec3& delta) = 0;
	virtual void rotate(float angle, const glm::vec3& axis) = 0;
	virtual void scaleBy(const glm::vec3& factor) = 0;
	virtual void setPosition(const glm::vec3& pos) = 0;
	virtual void setRotation(const glm::quat& rot) = 0;
	virtual void setScale(const glm::vec3& newScale) = 0;
	virtual glm::vec3 getPosition() const = 0;
	virtual glm::quat getRotation() const = 0;
	virtual glm::vec3 getScale() const = 0;
	virtual glm::mat4 getModelMatrix() const = 0;
	virtual ~ITransform() = default;
};

class Transform : public ITransform {

private:
	glm::vec3 position{ 0.0f };
	glm::quat rotation{ 1.0f, 0.0f,0.0f,0.0f };
	glm::vec3 scale{ 1.0f };

public:
	void translate(const glm::vec3& delta) override;
	void rotate(float angle, const glm::vec3& axis) override;
	void scaleBy(const glm::vec3& factor) override;
	void setPosition(const glm::vec3& pos) override;
	void setRotation(const glm::quat& rot) override;
	void setScale(const glm::vec3& newScale) override;
	glm::vec3 getPosition() const override;
	glm::quat getRotation() const override;
	glm::vec3 getScale() const override;
	glm::mat4 getModelMatrix() const override;
	~Transform() override = default;
};