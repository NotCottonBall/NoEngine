# CMake Setup
We use Cmake with Cmake Presets.\
This means we dont have to run a lot of commands, just use the presets already available or create new ones.

# Build Types
We use three build types

## Debug
This build type is for ***Engine Development*** and wont have any optimizations for debugging purposes.

## DebRelease
I dont know what to do about this builod but i think having a middle ground between Release and Debug will be helpful

## Release
This build will have the Engine's UI and some optimizations.\
Only some optimizations because we want to be able to debug some things if there is a fault in the Engine.\
Also, This is the build users will be using to make a *Game*

## RelExport
I dont know what to do about this builod but i think having a middle ground between Export and Release will be helpful

## Export
This build will have **No Optimizations**.\
Neither will it have any Engine's UI.\
This build is the shipped game made by the Engine using the Release Build.\
This will consist of all the optimizations. Engine and Others.