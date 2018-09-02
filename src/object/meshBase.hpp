#pragma once

#include <System/VertexPosTex.hpp>
#include <System/Shader.hpp>
#include <System/Camera.hpp>
#include <object/texture.hpp>

#include <vector>
#include <memory>

template<typename T>
class MeshBase {
public:
    typedef T VertexType;

    MeshBase(std::initializer_list<VertexType> vertices)
        :_vertices(std::move(vertices)),
        _num_triangles(static_cast<unsigned int>(_vertices.size())) {
        glGenVertexArrays(1, &_vertex_array);
        glGenBuffers(1, &_vertex_buffer);

        glBindVertexArray(_vertex_array);

        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(VertexPosTex), &_vertices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    ~MeshBase() {
        glDeleteVertexArrays(1, &_vertex_array);
	    glDeleteBuffers(1, &_vertex_buffer);
    }

protected:
    std::vector<VertexType> _vertices;

    unsigned int _num_triangles;

    unsigned int _vertex_buffer;
	unsigned int _vertex_array;
};
