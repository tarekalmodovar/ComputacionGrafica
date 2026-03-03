//Almodovar Tufiño Tarek
//423127375
// Practica 4
//Fecha de entrega: 01/03/2026


#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Almodovar Tufiño Tarek", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float verticesCafe[] = {

			// Cara Frontal
			-0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			-0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			-0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,

			// Cara Trasera
			-0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			-0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			-0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,

			// Cara Derecha
			 0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,

			 // Cara Izquierda
			 -0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,

			 // Cara Inferior
			 -0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			  0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			  0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			  0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f, -0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f, -0.5f, -0.5f,  0.6f, 0.3f, 0.1f,

			 // Cara Superior
			 -0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			  0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
			  0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			  0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f,  0.5f,  0.5f,  0.6f, 0.3f, 0.1f,
			 -0.5f,  0.5f, -0.5f,  0.6f, 0.3f, 0.1f,
	};


	float verticesBeige[] = {
		// Posiciones (X, Y, Z)      // Color Beige Cafecito (R, G, B)

		// Cara Frontal
		-0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		-0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		-0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,

		// Cara Trasera
		-0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		-0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		-0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,

		// Cara Derecha
		 0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,

		 // Cara Izquierda
		 -0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,

		 // Cara Inferior
		 -0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		  0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		  0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		  0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f, -0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f, -0.5f, -0.5f,  0.82f, 0.70f, 0.55f,

		 // Cara Superior
		 -0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		  0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
		  0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		  0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f,  0.5f,  0.5f,  0.82f, 0.70f, 0.55f,
		 -0.5f,  0.5f, -0.5f,  0.82f, 0.70f, 0.55f,
	};

	float verticesRojoClaro[] = {
		// Posiciones (X, Y, Z)      // Color Lengua (R, G, B)

		// Cara Frontal
		-0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		-0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		-0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,

		// Cara Trasera
		-0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		-0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		-0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,

		// Cara Derecha
		 0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,

		 // Cara Izquierda
		 -0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,

		 // Cara Inferior
		 -0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		  0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		  0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		  0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f, -0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f, -0.5f, -0.5f,  0.9f, 0.4f, 0.45f,

		 // Cara Superior
		 -0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		  0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
		  0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		  0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f,  0.5f,  0.5f,  0.9f, 0.4f, 0.45f,
		 -0.5f,  0.5f, -0.5f,  0.9f, 0.4f, 0.45f,
	};

	float verticesBlanco[] = {
		// Posiciones (X, Y, Z)      // Colores (R, G, B)

		// 1. Cara Frontal - NEGRO (Ahora es la cara principal)
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,

		// 2. Cara Trasera - BLANCO
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,

		// 3. Cara Derecha - BLANCO
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,

		 // 4. Cara Izquierda - BLANCO
		 -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,

		 // 5. Cara Inferior - BLANCO
		 -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,

		 // 6. Cara Superior - BLANCO
		 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
	};

	float verticesCafeClaro[] = {
		// Posiciones (X, Y, Z)      // Color Café Claro (R, G, B)

		// Cara Frontal
		-0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		-0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		-0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,

		// Cara Trasera
		-0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		-0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		-0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,

		// Cara Derecha
		 0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,

		 // Cara Izquierda
		 -0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,

		 // Cara Inferior
		 -0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		  0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		  0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		  0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f, -0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f, -0.5f, -0.5f,  0.76f, 0.45f, 0.25f,

		 // Cara Superior
		 -0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		  0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
		  0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		  0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f,  0.5f,  0.5f,  0.76f, 0.45f, 0.25f,
		 -0.5f,  0.5f, -0.5f,  0.76f, 0.45f, 0.25f,
	};

	float verticesMagenta[] = {

		// Cara Frontal
		-0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		-0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,

		// Cara Trasera
		-0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		-0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		-0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,

		// Cara Derecha
		 0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,

		 // Cara Izquierda
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,

		 // Cara Inferior
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		  0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.098f, 0.165f,

		 // Cara Superior
		 -0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		  0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.098f, 0.165f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 0.098f, 0.165f,
	};

	float verticesOcre[] = {

		// Cara Frontal
		-0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		-0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		-0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,

		// Cara Trasera
		-0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		-0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		-0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,

		// Cara Derecha
		 0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,

		 // Cara Izquierda
		 -0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,

		 // Cara Inferior
		 -0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		  0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		  0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		  0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f, -0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f, -0.5f, -0.5f,  0.694f, 0.345f, 0.235f,

		 // Cara Superior
		 -0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		  0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
		  0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		  0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f,  0.5f,  0.5f,  0.694f, 0.345f, 0.235f,
		 -0.5f,  0.5f, -0.5f,  0.694f, 0.345f, 0.235f,
	};




	// Usaremos 6 tipos de cubos de distinto color
	GLuint VAOs[7], VBOs[7];
	glGenVertexArrays(7, VAOs);
	glGenBuffers(7, VBOs);
	//glGenBuffers(1, &EBO);


	// --- CUBO CAFÉ (VAOs[0]) ---
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCafe), verticesCafe, GL_STATIC_DRAW);
	// Atributos (Posición y Color)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// --- CUBO BEIGE (VAOs[1]) ---
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBeige), verticesBeige, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// --- CUBO ROJO CLARO (VAOs[2]) ---
	glBindVertexArray(VAOs[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesRojoClaro), verticesRojoClaro, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// --- CUBO BLANCO/NEGRO (VAOs[3]) ---
	glBindVertexArray(VAOs[3]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBlanco), verticesBlanco, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// --- CUBO CAFÉ CLARO (VAOs[4]) ---
	glBindVertexArray(VAOs[4]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCafeClaro), verticesCafeClaro, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// --- CUBO MAGENTA (VAOs[5]) ---
	glBindVertexArray(VAOs[5]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[5]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesMagenta), verticesMagenta, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// --- CUBO OCRE (VAOs[6]) ---
	glBindVertexArray(VAOs[6]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[6]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesOcre), verticesOcre, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Limpiamos el bind


	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.510f, 0.655f, 0.7250f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	

		glBindVertexArray(VAOs[0]);
	    //cabeza del chango
	    model = glm::mat4(1.0f);
		model = glm:: scale(model, glm::vec3(2.0f, 2.0f, 2.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(2.5f, 1.6f, 2.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//cejas del chango (derecha)
		glBindVertexArray(VAOs[4]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-0.5f, 0.3f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.8f, 2.0f, 2.0f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.2f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.5f, 2.0f, 2.0f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//cejas del chango (izquierda)
		glBindVertexArray(VAOs[4]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-0.5f, 0.3f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-0.8f, 2.0f, 2.0f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-1.0f, 0.2f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.5f, 2.0f, 2.0f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//ojos del chango
		glBindVertexArray(VAOs[3]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-1.0f, 0.3f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.5f, 0.5f, 2.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-0.8f, 0.3f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.5f, 0.2f, 2.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pupila izquierda
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.12f, 0.12f, 0.52f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-4.0f, 2.0f, 2.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//ojo derecho 
		glBindVertexArray(VAOs[3]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-1.0f, 0.3f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-0.5f, 0.5f, 2.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.8f, 0.3f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.5f, 0.2f, 2.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pupila derecha
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.12f, 0.12f, 0.52f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(4.0f, 2.0f, 2.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//nariz 
		glBindVertexArray(VAOs[2]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.3f, 0.2f, 0.52f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.1f, 0.1f, 2.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//boca
		glBindVertexArray(VAOs[4]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-0.1f, 0.9f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(10.0f, -0.8f, 4.3f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(-0.1f, 0.9f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-10.0f, -0.8f, 4.3f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//labio superior
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(2.15f,0.2f,0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -0.8f, 4.25f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//labio inferior
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(2.15f, 0.2f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -6.0f, 4.25f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//dientes
		glBindVertexArray(VAOs[3]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.5f, 0.2f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -1.9f, 4.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//parte negra de la boca
		glBindVertexArray(VAOs[3]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(2.0f, 1.1f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -0.55f, 3.5f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//lengua 1
		glBindVertexArray(VAOs[5]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.2f, 0.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -5.0f, 3.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//lengua 2
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 2.0f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 6.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//lengua 3
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 2.5f, 0.3f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -1.5f, 7.0f)); //Derecha, arriba, adelante
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//orejas
		glBindVertexArray(VAOs[1]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.5f, 0.8f, 0.2f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//cuello del chango
		glBindVertexArray(VAOs[0]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(2.0f, 5.0f, 2.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -0.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

	    //cuerpo
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.0f, 2.0f, 3.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -1.4f, 0.0f));  //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//panza
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.5f, 2.0f, 3.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -1.9f, 0.0f));  //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//panza calva
		glBindVertexArray(VAOs[1]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(2.5f, 2.0f, 3.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -1.5f, 0.05f));  //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//panza calva
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.0f, 1.7f, 3.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -2.3f, 0.05f));  //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//hombros
		glBindVertexArray(VAOs[6]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(4.0f, 0.8f, 1.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(0.0f, -3.0f, 0.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//brazo izq
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 3.0f, 1.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(2.0f, -1.3f, 0.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//brazo der
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 3.0f, 1.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-2.0f, -1.3f, 0.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//mano izq
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.5f, 1.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-2.0f, -10.5f, -0.2f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//mano dere
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.5f, 1.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(2.0f, -10.5f, -0.2f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//pierna der
		glBindVertexArray(VAOs[0]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 2.0f, 1.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-1.0f, -2.5f, 0.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pie der
		glBindVertexArray(VAOs[1]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.5f, 1.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-1.0f, -12.0f, 0.1f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pie der
		glBindVertexArray(VAOs[1]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.5f, 1.5f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(1.0f, -12.0f, 0.1f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//pierna izq
		glBindVertexArray(VAOs[0]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 2.0f, 1.0f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(1.0f, -2.5f, 0.0f)); //Derecha, arriba, adelante
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotación para que los ojos estén mirando hacia adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//cigarro
		glBindVertexArray(VAOs[3]);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.6f)); // ancho, alto, profundidad
		model = glm::translate(model, glm::vec3(-6.0f, -10.0f, 3.0f)); //Derecha, arriba, adelante
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
			

		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAOs[0]);
	glDeleteBuffers(1, &VBOs[0]);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.03f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.03f;
	 if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		 movY += 0.03f;
	 if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		 movY -= 0.03f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.4f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.4f;
 }


