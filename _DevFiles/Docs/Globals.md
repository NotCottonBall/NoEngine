Globals are the variables that will be used throught the whole codebase of the project.\
Each Project/Modules will have it's own globals.\
That doesn't mean Globals for each project are not sharable.

All Globals should be static meaning only one instance of them will exist.

# Types Of Globals
## Fixed Globals
These globals are fixed `constexpr` values that cannot be changed

## Value Globals
These are globals whose values can be changed. (Does Not Exist Yet)