## RestService is a modern cross-platform RESTful library ##

![Language iso: C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Version](https://img.shields.io/badge/Version-0.4-lightgrey)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux%20%7C%20iOS%20%7C%20Android%20%7C%20Web-lightgrey)
![Dependencies](https://img.shields.io/badge/dependencies-Curl%20%7C%20RapidJson-yellow)

## Installation
<p>
First of all, You need to make sure that curl library is installed on your development environment.
</p>

## Building

- You need CMake tool for building source code
- Get Curl & RapidJson [Pay Attention: RapidJson is header only]
- All source code is written with Pure STL 1z (C++17)
- MSVC 2017, GCC7.x or Glang 7.x
- Add RestService.dll [on Windows], libRestService.dylib [on macOS] or libRestService.so [on Linux] for your project as external library. you can compile it by static mode.
- Import SDK common header ```#include <RestService>```

## Usage Example
```cpp

#include <iostream>
#include <RestService>

int main(int argc, char *argv[])
{
    auto request = RestService::NetworkRequest();
    request.get("http://dummy.restapiexample.com/api/v1/employees");
    auto result = request.getResult();
    std::cout << "Result : " << result << std::endl;

    return 0;
}


```

## Contribution
Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com

## **ToDo**
 * More Exception handling
 * And more features...
