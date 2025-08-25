# The Code Structure
Well we have a rule for the NoEngine project.\
Basically, We have all of our Includes (`.h`s), that has funtionality expected to be exported inside of the `Include/` folder of our project.

Example:\
If there is a Test function that needs to be exported/usable to the user, we will add that function to a `.h` if it doesn't already exists in one and put the `.h` inside of the `Include/` folder in a sensable order.

If you can't find a sensable path for the `.h` then, create a similar path to where the `.cpp` file is gonna be.\
Example: If you have a `Test.cpp` inside of `Src/Testing/TestFunctions/Test.cpp`, You will put the header into a similar structure in the `Include/` folder like this: `Include/Testing/Test.h` or `Include/Testing/TestFunctions/Test.cpp` if you wanna be more specific.