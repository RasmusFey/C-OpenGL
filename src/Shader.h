#ifndef SHADER_H
#define SHADER_H

#include <string>


class Shader {
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use() const;
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void set4Matrixfv(const std::string &name, glm::mat4 value) const;
    explicit operator unsigned int() const;
};

#endif