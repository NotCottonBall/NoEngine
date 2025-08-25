# How Libraries Are Structured.
We have a complex setup for this aswell.

basically, we have two folders, `Headers/` and `Libraries/`.\
- **Headers** contain the libs that don't need building and doesnt produce a .lib or similar file and instead gets stiched with the main project.
- **Libraries** contain the libs that need building. The one that generate a .lib or similar file.

Libraries has a seperate CMakeLists.txt that should be ran before building the main project because it sets up all the libraries required.