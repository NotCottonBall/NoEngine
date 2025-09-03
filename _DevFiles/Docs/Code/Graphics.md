# Graphics Setup
All the API initialization code will be inside of the `PROJECT_ROOT/SodaEngine/Src/Renderer/<API_NAME>` folder.\
It will also have the API specific code for creating buffers, textures and all the other graphics stuff.

# Vulkan Setup
Vulkan. This API has a lot of boilerplate code. Createing an instance, validating extensions and layers, creating physical and logical devices, etc...\
So, everything as said will be inside of the API specific folder.

# Some Global Stuff
Some global variables will be used by these API specific code like the version of the engine which is required to create a `Vulkan Application`.\
It is not a necessity but I wanna fill it.