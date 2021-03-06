#pragma once
#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "textureClass.h"
#include "shader.h"


class SpriteRenderer
{
public:
	// Constructor (inits shaders/shapes)
	SpriteRenderer(Shader &shader, glm::vec2 playerPos, glm::vec2 playerSize);
	// Destructor
	~SpriteRenderer();
	// Renders a defined quad textured with given sprite
	void DrawSprite(textureClass &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3({ 1.0f, 1.0f, 1.0f}));
	void resetCam(glm::vec2 playerPos, glm::vec2 playerSize);
	void setCam(float x, float y) { camX += x; camY += y; }
	void getCam(float &x, float &y) { x = camX; y = camY; }


private:
	// Render state
	Shader shader;
	GLuint quadVAO;
	// Initializes and configures the quad's buffer and vertex attributes
	void initRenderData();
		
	float camX, camY;
};

#endif

