#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main(void) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// comment Creating a window object in OpenGL
	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << " Failed to open Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// making context of our window 
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// we tell the function that  We have to tell OpenGL the size of the rendering window so OpenGL knows how we want to display the data 
	//and coordinates with respect to the window. We can set those dimensions via the glViewport function:
	//glViewport(0, 0, 800, 600);



	//********Viewport Before we can start rendering we have to do one last thing.We have to tell OpenGL the size of the rendering window so OpenGL knows how we want to display the dataand coordinates with respect to the window.We can set those dimensions via the glViewport function :


	//glViewport(0, 0, 800, 600);
	//The first two parameters of glViewport set the location of the lower left corner of the window.The thirdand fourth parameter set the widthand height of the rendering window in pixels, which we set equal to GLFW's window size.
	//We could actually set the viewport dimensions at values smaller than GLFW's dimensions; then all the OpenGL rendering would be displayed in a smaller window and we could for example display other elements outside the OpenGL viewport.
	 //Behind the scenes OpenGL uses the data specified via glViewport to transform the 2D coordinates it processed to coordinates on your screen.For example, a processed point of location(-0.5, 0.5) would(as its final transformation) be mapped to(200, 450) in screen coordinates.Note that processed coordinates in OpenGL are between - 1 and 1 so we effectively map from the range(-1 to 1) to(0, 800) and (0, 600).
   //However, the moment a user resizes the window the viewport should be adjusted as well.We can register a callback function on the window that gets called each time the window is resized.This resize callback function has the following prototype :


	//void framebuffer_size_callback(GLFWwindow * window, int width, int height);
	//The framebuffer size function takes a GLFWwindow as its first argumentand two integers indicating the new window dimensions.Whenever the window changes in size, GLFW calls this functionand fills in the proper arguments for you to process.

	//We do have to tell GLFW we want to call this function on every window resize by registering it :
	//When the window is first displayed framebuffer_size_callback gets called as well with the resulting window dimensions.For retina displays widthand height will end up significantly higher than the original input values.

   // There are many callbacks functions we can set to register our own functions.For example, we can make a callback function to process joystick input changes, process error messages etc.We register the callback functions after we've created the window and before the render loop is initiated.



	//void framebuffer_size_callback(GLFWwindow * window, int width, int height);
	//{
		//glViewport(0, 0, width, height);
	//}

	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback(GLFWwindow * window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
	}

