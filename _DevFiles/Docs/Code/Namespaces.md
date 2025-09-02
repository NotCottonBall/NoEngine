This file contains all the namespaces and what they are for

# The Core 
The Core namesapces

## NoEngine
This is the namespace used for all the core components of NoEngine. like creating the Engine itself with
```cpp
NoEngine::Engine engine;
```

## NoRender
This is the namespace that will contain the renderer specific code like API Initialization.\
This is purely on for the API specific code inside the `NoEngine` project and should not be used by the Client or the Editor.

## NoGlobal
This namespace is for the global variables which will have sub namespaces like `Versions` which is the only sub-namespace of NoGlobals right now.

**List Of Sub-Namespaces**
- Versions