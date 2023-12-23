# CMake Language



## Comments:

```cmake
# singleline comment

#[=[
This is a multiline comments
]=]
```

## Command invocation:

The only data  type recognized by CMake is a **string**.

* Scripting commands
* Project commands
* CTest commands

## Command argument:

### Bracket arguments

```cmake
# multiline arguments
# blanket will be reserved
message([[multiline
bracket=
ddd  ddd   ddd
]])

#multiline arguments that can include [[  ]]
message([==[
[["ddddd"]]
]==])
```

### Quoted argument

To include a quote character within the output string, you have to escape it with a backslash`\`

```cmake
message("dddddddd \"  \n dfdfdfd")
```

### unquoted argument

Unquoted argument evaluate both **escape sequences** and **variable references**.

`;` will be treated as a delimiter . You can use `\`  to escape it.

#### Example

```cmake
message(a\ sigle\ argument)
message(three;separated;arguments)
message(${CMAKE_VERSION})
# ()  should be used in pairs.
message(()())  


#output
a sigle argument
threeseparatedarguments
3.27.1
()()
```



## Variables

Three different categories resided in different scopes :

* normal
* cache
* environment

Variables are case-sensitive. All variables are stored internally as strings.

```cmake
set([[My string]] "Tests")
message(${My\ string})
```

***Avoid using `CMAKE_` or `_CMAKE_`*** 

To unset a variable, use `unset()`



### Variable references

variable evaluation or interpolation id performed ion an **inside-out** fashion.

* ${}  syntax is used to reference normal or cache variables
* $ENV{}  syntax is used to reference environment variables
* $CACHE{}    cache variable.



### Using the environment variables

You can set()   / unset()  environment variables, but changes will only be made to a local copy in the running `cmake `process.

The value set during the configuration is persisted to the generated buildsystem.

### Using the cache variables

Essentially, they're persistent variables stored in a  `CMakeCache,txt`.



## How to use the variable scope in CMake(Hard)

`CMake` has two scops:

* **Function scope**
* **Directory scope**

Whenever we try to access the normal variable, CMake  will search for the variables from the current scope or search through the cache variables.

 ```cmake
 #ADD PARENT_SCOPE      change the variable in the calling (parent) scope.
 set(MyVariable "New Value" PARENT_SCOPE)
 ```



## Using lists





## Understanding control structures in CMake

### Condition blocks:

```cmake
if(<condition)
	<commands>
elseif(<condition)
	<commands>
else()
	<conmmands>
endif()
```

#### Logical operators:

```cmake
NOT <condition>
<condition> AND <condition>
<condition> OR <condition>
```

***CMake will try to evaluate unquoted arguments as if they are variable references***

```cmake
set(VAR1 FALSE)
set(VAR2 "VAR1")
if(${VAR2})
```



> **TRUE**:
>
> * **ON Y YES TRUE**
> * A non-zero number

```cmake
set(FOO BAR)
if(FOO)

#Because CMAKE makes an exception when it comes to unquoted variable.
#It will only evaluate if(FOO) to false if it is any of the following constants
```

* OFF NO FALSE N IGNORE NOTFOUND
* A string ending with -NOTFOUND
* An empty string 
* Zero

```cmake
#That above will equal to 
if(FOO)
```



```cmake
if(DEFINE <name>)
if(DEFINE CACHE{<name>})
```



### Conparing values:

`EQUAL、LESS、LESS_EQUAL、GREATED、GREATED_EQUAL`

### Loop：

```cmake
while(<condition>)
	<commands>
endwhile()
```

```cmake
foreach(<lopp_var> RANGE <max>)
	<commands>
endforeach()
```

### Command definitions:

#### Macros:

```cmake
macro(<name> [argument...])
	<commands>
endmacro()
```

#### functions:

```cmake
function(<name> [aruguments])
	<commands>
endfunction()
```



> * CMAKE_CURRENT_FUNCTION
> * CMAKE_CURRENT_FUNCTION_LIST_DIR
> * CMAKE_CURRENT_FUNCTION_LIST_FILE
> * CMAKE_CURRENT_FUNCTION_LIST_LINE









