
//Almodovar Tufiño Tarek               
 //423127375
 //Fecha de entrega: 15 de febrero 2026    
 //Practica 2

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Almodóvar Tufiño Tarek", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		/*0.5f,  0.5f, 0.0f,    1.0f,0.0f,1.0f,  // top right
		0.5f, -0.5f, 0.0f,    0.6f,0.6f,0.6f,  // bottom right
		-0.5f, -0.3f, 0.0f,   0.3f,0.3f,0.3f,  // bottom left
		-0.5f,  0.5f, 0.0f,   0.3f,0.3f,0.3f, // top left  */  /*
		0.1f,  0.08f, 0.0f,    1.0f,0.0f,1.0f,  // 0   Cap A
		0.1f, -0.08f, 0.0f,    0.6f,0.6f,0.6f,  // 1
        -0.1f, 0.08f, 0.0f,   0.3f,0.3f,0.3f,  // 2
		-0.1f, -0.08f, 0.0f,   0.3f,0.3f,0.3f, // 3
		0.15f, 0.0f, 0.0f,     0.3f,0.3f,0.0f , //4
		-0.15f, 0.0f, 0.0f,    0.3f,0.3f,0.0f  //5   
		-0.07f, 0.18f, 0.0f,   0.3f,0.3f,0.0f, //6    Cap B
		0.07f, 0.18f, 0.0f,    0.3f,0.3f,0.0f, //7
		-0.12f, 0.14f, 0.0f,   0.3f,0.3f,0.0f, //8
		0.12f, 0.14f, 0.0f,    0.3f,0.3f,0.0f, //9
		0.00f, 0.00f, 0.0f,    0.3f,0.3f,0.0f, //10 */

	     
	    	// Posiciones (x, y, z)      // Colores (r, g, b)
			// Puntos marcados en tu imagen (aproximados)
			/* 0 */  0.25f,  0.05f, 0.0f,   0.6f, 0.4f, 0.2f, // Punto 0
		 /* 1 */  0.25f, -0.25f, 0.0f,   0.4f, 0.2f, 0.1f, // Punto 1
		 /* 2 */ -0.25f,  0.05f, 0.0f,   0.6f, 0.4f, 0.2f, // Punto 2
		 /* 3 */ -0.25f, -0.25f, 0.0f,   0.4f, 0.2f, 0.1f, // Punto 3
		 /* 4 */  0.45f, -0.10f, 0.0f,   0.3f, 0.2f, 0.1f, // Punto 4
		 /* 5 */ -0.45f, -0.10f, 0.0f,   0.3f, 0.2f, 0.1f, // Punto 5
		 /* 6 */ -0.20f,  0.35f, 0.0f,   0.5f, 0.3f, 0.2f, // Punto 6
		 /* 7 */  0.20f,  0.35f, 0.0f,   0.5f, 0.3f, 0.2f, // Punto 7
		 /* 8 */ -0.35f,  0.20f, 0.0f,   0.4f, 0.2f, 0.1f, // Punto 8
		 /* 9 */  0.35f,  0.20f, 0.0f,   0.4f, 0.2f, 0.1f, // Punto 9
		 /* 10 */ 0.00f, -0.10f, 0.0f,   0.5f, 0.3f, 0.2f, // Centro A
		 /* 11 */ 0.00f,  0.20f, 0.0f,   0.7f, 0.5f, 0.3f, // Centro B

		// Puntas de la tortuga (Caparazón)
		 /* 12 */ 0.00f, -0.50f, 0.0f,   0.4f, 0.2f, 0.1f, // Punta abajo
		 /* 13 */ 0.00f,  0.50f, 0.0f,   0.3f, 0.2f, 0.1f, // Punta arriba (cuello)

		// Extremidades (Verdes)
		 /* 14 */ 0.00f,  0.80f, 0.0f,   0.2f, 0.4f, 0.2f, // Cabeza
		 /* 15 */ 0.85f,  0.25f, 0.0f,   0.1f, 0.3f, 0.1f, // Aleta frontal der (punta)
		 /* 16 */-0.85f,  0.25f, 0.0f,   0.1f, 0.3f, 0.1f, // Aleta frontal izq (punta)
		 /* 17 */ 0.50f,  0.55f, 0.0f,   0.2f, 0.4f, 0.2f, // Aleta frontal der (arriba)
		 /* 18 */-0.50f,  0.55f, 0.0f,   0.2f, 0.4f, 0.2f, // Aleta frontal izq (arriba)
		 /* 19 */ 0.55f, -0.65f, 0.0f,   0.1f, 0.3f, 0.1f, // Pata trasera der
		 /* 20 */-0.55f, -0.65f, 0.0f,   0.1f, 0.3f, 0.1f  // Pata trasera izq   
		
	};
	unsigned int indices[] = {  // note that we start from 0!
		/*
		1,2,3,// second Triangle
		0,1,2,
		0,1,4,
		2,3,5,
		8,9,10    */
		 
		10, 11, 0,  10, 0, 4,   10, 4, 1,   // Lado derecho (A)
	10, 1, 12,  10, 12, 3,  10, 3, 5,   // Parte inferior (A)
	10, 5, 2,   10, 2, 11,              // Lado izquierdo (A)
	11, 0, 9,   11, 9, 7,   11, 7, 13,  // Lado derecho (B)
	11, 13, 6,  11, 6, 8,   11, 8, 2,   // Lado izquierdo (B)

	// EXTREMIDADES (Verdes)
	13, 14, 7,   13, 6, 14,             // Cabeza (unida al cuello)
	7, 17, 15,   7, 15, 9,              // Aleta frontal derecha
	6, 18, 16,   6, 16, 8,              // Aleta frontal izquierda
	1, 4, 19,    1, 19, 12,             // Pata trasera derecha
	3, 5, 20,    3, 20, 12              // Pata trasera izquierda
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);


        // glPointSize(10);
          //7glDrawArrays(GL_POINTS,0,4);
        
          // glDrawArrays(GL_LINES,3,4);
          //glDrawArrays(GL_LINE_LOOP,0,4);
        
           //glDrawArrays(GL_TRIANGLES,0,3);
           //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
		//dibujamos el caparazon
		 // glDrawArrays(GL_TRIANGLES, 0, 3);
		  //glDrawArrays(GL_TRIANGLES, 1, 3);
		  //glDrawArrays(GL_TRIANGLES, 3, 3);
		  //glDrawArrays(GL_TRIANGLES, 4, 3);
		  glDrawElements(GL_TRIANGLES, 66, GL_UNSIGNED_INT, 0);
        
        
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}