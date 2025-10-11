#include <glm/glm.hpp>
#include <iostream>

int main() {
    glm::vec3 velocity(1.0f, 0.0f, 0.0f);
    glm::vec3 acceleration(0.0f, 9.8f, 0.0f);

    glm::vec3 result = velocity + acceleration;

    std::cout << "Result: "
        << result.x << ", "
        << result.y << ", "
        << result.z << "\n";
    return 0;
}
