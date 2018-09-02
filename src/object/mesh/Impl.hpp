#pragma once

#include <System/VertexPosTex.hpp>
#include <System/Shader.hpp>
#include <System/Camera.hpp>
#include <object/texture.hpp>

#include <vector>
#include <memory>

namespace mesh {

class BaseImpl {
public:
    BaseImpl(unsigned int num_triangles)
        :_num_triangles(num_triangles) {

    }

    ~BaseImpl() {

    }

    unsigned int _num_triangles;

    unsigned int _vertex_buffer;
	unsigned int _vertex_array;
};

template<typename T>
class Impl : public BaseImpl {
public:
    typedef T VertexType;

    Impl(std::initializer_list<VertexType> vertices)
        :BaseImpl(static_cast<unsigned int>(vertices.size())),
        _vertices(std::move(vertices)) {
        glGenVertexArrays(1, &_vertex_array);
        glGenBuffers(1, &_vertex_buffer);

        glBindVertexArray(_vertex_array);

        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(VertexType), &_vertices[0], GL_STATIC_DRAW);

        // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        // glEnableVertexAttribArray(0);

        // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        // glEnableVertexAttribArray(1);

        VertexType::Register();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    ~Impl() {
        glDeleteVertexArrays(1, &_vertex_array);
	    glDeleteBuffers(1, &_vertex_buffer);
    }

protected:
    std::vector<VertexType> _vertices;

};

}  // namespace mesh