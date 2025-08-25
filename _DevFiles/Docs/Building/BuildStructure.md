# The Build Structure Of This Project
I dont know if I made it too complex then it needs to be but it is modular and adding new modules like libraries made by others or youself should be easy later on.

## The Root
The root folder includes a CMakeLists.txt which is responsible for the NoEngine Project and puts out a static Library named "*NoEngine*".\
It also produces an executable named "*NoEditor*" but our goal is to make them both as indipendent as possible. Meaning, NoEngine's funtionalities can be used inside NoEditor but the other way around is **FORBIDDEN**.

This is because we want the NoEditor to be optional. The user may wanna use it or just use the NoEngine without any GUI.

## Libraries
the *Libraries* folder is responsible for holding huge libraries and packages like SDL.\
This is done because,
- We dont want out code to be interfeared with the Librarie's code.\
- We dont wanna clean rather *BIG* libraries everytime we clean out project cuz that would take a lot of time.
- We can add only the selected libraries to each project. Example, we add SDL3 to NoEngine and its sub projects and we add ImGui only to the NoEditor and *it's* sub projects.

Thats mostly the reasons why you dont wanna have Libraries and NoEngine combined.

## NoEditor
This will be the GUI project (The Editor) of NoEngine.\
This project runs as a sub directory of the NoEngine project. Meaning, when NoEngien is configured, this will too. And when NoEngine is being Built, this will too.

*@todo: remove the line below when NoEditor is not just a testing project*\
For now, it's just a testing project.

## Whats To Come.
*MODULES!* Yea, Modules.

I want modules to be like the libraries that can be added on-demand. Meaning, NoEngine can use them but are not nessary.\
The perfect example I can think of for this is ***Networking Module*** that can be added for networking support inside NoEngine.

Basicly, the development of big components like Networking will be added as a Module.