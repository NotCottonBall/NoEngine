Asserts are used to check if something is valid and throw a breakpoint with an error message if it isn't.

# Types Of Asserts

## SD_ENGINE_ASSERT (The Only One)

For now there is only one assert used for the Engine called `SD_ENGINE_ASSERT`
I don't really see a reason to include a client side asserts so we wont have them right now.

## Parameters

To use `SD_ENGINE_ASSERT` you need to know what to pass in.

**Here's the list:**

- `Expr` Is the expression you give to the assert to check if it's valid or not.
- `Msg` Is the message you give to the assert thats printed if the assertion gets called.
- `Callback` Is the callback expression that gets ran if the assertion gets called. Can be used to run deletion function
  if something fails.

**Example:**

```
SD_ENGINE_ASSERT(m_Exists, "The Thing Doesn't Exist", QuitApp());
```

Assuming `m_Exists` is a boolean, if its false, then the assertion gets called with the message and `QuitApp()` function
gets called.\
You can always give `void()` as the last param to do nothing.

For each build type ASSERT functions differently. Check the code to know about it. (
`PROJECT_ROOT/SodaEngine/Src/Debug/SDAssert.h`)