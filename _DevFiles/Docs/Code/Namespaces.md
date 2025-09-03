This file contains all the namespaces and what they are for

# The Core
The Core namesapces

## SodaEngine
This is the namespace used for all the core components of SodaEngine. like creating the Engine itself with
```cpp
SDEngine::Engine engine;
```

## SDFixedGlobal
This namespace has fixed global values that are const.\
This namespace is for the global variables which will have sub namespaces like `Versions` which is the only
sub-namespace of SDFixedGlobals right now.

**List Of Sub-Namespaces**
- Versions
    - Includes the versions of engine and something else later on maybe.

## SDDebug
This namespace contains all the stuff related to debugging. like Log, which is a sub-namespace

**List Of Sub-Namespace**
- Log
    - The logging functions like LogInfo, LogDebug, etc...

<br>

# The Engine Development Only
These are the engine development only namespaces that shall only be used inside the `SodaEngine` project.\
All these private namespaces will be named with the prefix `_`.\
For example: `_SDRender`

## _SDRender
This is the namespace that will contain the renderer specific code like API Initialization.\
This is purely on for the API specific code inside the `SodaEngine` project and should not be used by the Client or the
Editor.