#pragma once
#include <glm/glm.hpp>
#include <string>

class Shader {
private:
	unsigned int programID;

	unsigned int compileShader(const std::string& source, unsigned int type);
	std::string loadSourceFromFile(const std::string& filepath);

public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void use() const;
	unsigned int getID() const;

	void setMat4(const std::string& name, const glm::mat4& value);
	void setVec3(const std::string& name, const glm::vec3& value);
	void setFloat(const std::string& name, float value);
};