#pragma once

#include <memory>
#include "Transform.h"

// collider is not build yet so its just to remove squiggly lines
class Collider {

};

class Entity {
protected:
	bool Anchor = false;
	bool canCollide = true;

	// components required for entity (must have)
	std::unique_ptr<ITransform> transform;
	std::unique_ptr<Collider> collider = nullptr;

public:
	// Constructor requires a transform
	Entity(std::unique_ptr<ITransform> t);

	virtual ~Entity() = default;

	// Transform access
	ITransform& getTransform();
	const ITransform& getTransform() const;

	// Collider access
	void setCollider(std::unique_ptr<Collider> c);
	Collider* getCollider() const;

	// Flags
	bool isAnchored() const;
	void setAnchored(bool state);

	bool isCollidable() const;
	void setCollidable(bool state);

	// Core Interface / Controllers
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
};
