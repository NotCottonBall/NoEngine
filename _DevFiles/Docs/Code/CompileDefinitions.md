# Requirements
[Prefix.md](Prefix.md) (todo: link this in github wiki)

# List Of Compile Definitions
## For Platform Specification
PREFIX: `SD_PLATFORM_`

### For Windows: `SD_PLATFORM_WINDOWS`
### For Unix: `SD_PLATFORM_UNIX`
### For Apple: `SD_PLATFORM_APPLE`

## For Build Types
This is a little different as it doesnt have ALL_CAPS but Camel case due to redability.

PREFIX: `SD_`

Well, after the prefix, you just need to add the BuildType.\
To check all the build types you can just go to [Config.md](../Building/Config.md)

Example:\
For Debug build it would be: `SD_Debug`\
For RelExport build it would be: `SD_RelExport`