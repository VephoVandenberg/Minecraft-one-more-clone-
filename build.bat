cl -Zi main.cpp src/*cpp ^
	-I dependencies/GLEW/include -I dependencies/GLFW/include -I dependencies/glm^
	dependencies/GLEW/lib/glew32.lib dependencies/GLFW/lib/glfw3dll.lib ^
	opengl32.lib gdi32.lib user32.lib shell32.lib
	