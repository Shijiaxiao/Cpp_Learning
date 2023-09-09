# Naming



## File Names
* my_header.h
* my_header.cc
* main.cpp


## Type Names
``` cpp
// classe and struct
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...

// typedefs
typedef hash_map<UrlTableProperties *, std::string> PropertiesMap;

// using aliases
using PropertiesMap = hash_map<UrlTableProperties *, std::string>;

// enums
enum class UrlTableError { ...
``` 


## Variable Names

### Common Variables
``` cpp
std::string table_name;  // OK - snake_case.
``` 

### Class Data Members
Data members of classes, both static and non-static, are named like ordinary nonmember variables, but with a trailing underscore.
``` cpp
class TableInfo {
  ...
 private:
  std::string table_name_;  // OK - underscore at end.
  static Pool<TableInfo>* pool_;  // OK.
};
```

### Struct Data Members
Data members of structs, both static and non-static, are named like ordinary nonmember variables. They do not have the trailing underscores that data members in classes have.
``` cpp
struct UrlTableProperties {
  std::string name;
  int num_entries;
  static Pool<UrlTableProperties>* pool;
};
```


## Constant Names
Variables declared constexpr or const, and whose value is fixed for the duration of the program, are named with a leading "k" followed by mixed case. Underscores can be used as separators in the rare cases where capitalization cannot be used for separation. For example:
``` cpp
const int kDaysInAWeek = 7;
const int kAndroid8_0_0 = 24;  // Android 8.0.0
```
All such variables with static storage duration (i.e., statics and globals, see Storage Duration for details) should be named this way. This convention is optional for variables of other storage classes, e.g., automatic variables; otherwise the usual variable naming rules apply. For example:
``` cpp
void ComputeFoo(absl::string_view suffix) {
  // Either of these is acceptable.
  const absl::string_view kPrefix = "prefix";
  const absl::string_view prefix = "prefix";
  ...
}
void ComputeFoo(absl::string_view suffix) {
  // Bad - different invocations of ComputeFoo give kCombined different values.
  const std::string kCombined = absl::StrCat(kPrefix, suffix);
  ...
}
```


## Function Names
Regular functions have mixed case; accessors and mutators may be named like variables.
Ordinarily, functions should start with a capital letter and have a capital letter for each new word.
``` cpp
AddTableEntry()
DeleteUrl()
OpenFileOrDie()
```
(The same naming rule applies to class- and namespace-scope constants that are exposed as part of an API and that are intended to look like functions, because the fact that they're objects rather than functions is an unimportant implementation detail.)
Accessors and mutators (get and set functions) may be named like variables. These often correspond to actual member variables, but this is not required. For example, int count() and void set_count(int count).


## Namespace Names
Namespace names are all lower-case, with words separated by underscores. Top-level namespace names are based on the project name . Avoid collisions between nested namespaces and well-known top-level namespaces.


## Enumerator Names
Enumerators (for both scoped and unscoped enums) should be named like constants, not like macros. That is, use kEnumName not ENUM_NAME.
``` cpp
enum class UrlTableError {
  kOk = 0,
  kOutOfMemory,
  kMalformedInput,
};
```


## Macro Names
You're not really going to define a macro, are you? If you do, they're like this: MY_MACRO_THAT_SCARES_SMALL_CHILDREN_AND_ADULTS_ALIKE.
Please see the description of macros; in general macros should not be used. However, if they are absolutely needed, then they should be named with all capitals and underscores, and with a project-specific prefix.
``` cpp
#define MYPROJECT_ROUND(x) ...
```





# Comments

## TODO Comments
Use TODO comments for code that is temporary, a short-term solution, or good-enough but not perfect.
TODOs should include the string TODO in all caps, followed by the bug ID, name, e-mail address, or other identifier of the person or issue with the best context about the problem referenced by the TODO.
``` cpp
// TODO: bug 12345678 - Remove this after the 2047q4 compatibility window expires.
// TODO: example.com/my-design-doc - Manually fix up this code the next time it's touched.
// TODO(bug 12345678): Update this list after the Foo service is turned down.
// TODO(John): Use a "\*" here for concatenation operator.
```
If your TODO is of the form "At a future date do something" make sure that you either include a very specific date ("Fix by November 2005") or a very specific event ("Remove this code when all clients can handle XML responses.").


