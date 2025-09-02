# How The Engine Starts
The engine starts buy creating the `NoEngine::Engine` object and calling the `NoEngien::Engine::Run` function.

The constructor of the **Engine** class will call **Initialization** stuff that include initializing **SDL**, **Vulkan** and a **Window** for now.\
And the `NoEngien::Engine::Run` function will contain the main loop of the engine and calls every other function related to the main loop like the `ProcessEvent` function.