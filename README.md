## Lighting models
In this project I implemented different lighting models in [OpenGL](https://wikis.khronos.org/opengl/Main_Page). All lighting models are implemented in src/shaders directory as fragment_XXX.glsl and vertex_XXX.glsl.

### Technology used
 - C++,
 - GLFW,
 - GLAD,
 - GLM.

### Available models
 - [Lambert reflectance](https://en.wikipedia.org/wiki/Lambertian_reflectance)

## TODO:
 - Implement [lighting models](https://en.wikipedia.org/wiki/Computer_graphics_lighting), I will start with Phong and Phong Blinn;
 - Create a solid structure for the project.

## Compilation
Get the repository:
``` bash
git clone link_to_the_repo
```

Building the project:
``` bash
cd lighting_models
mkdir build
cmake -S . -B buiuld
```

The you can compile and run it:
``` bash
cmake --build build
./build/app
```