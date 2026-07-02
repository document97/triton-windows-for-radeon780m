# Install script for directory: C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/llvm/lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/LLVM")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/IR/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/FuzzMutate/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/FileCheck/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/InterfaceStub/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/IRPrinter/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/IRReader/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/CGData/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/CodeGen/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/CodeGenTypes/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/BinaryFormat/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Bitcode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Bitstream/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/DWARFLinker/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Extensions/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Frontend/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Transforms/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Linker/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Analysis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/LTO/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/MC/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/MCA/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/ObjCopy/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Object/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/ObjectYAML/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Option/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Remarks/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Debuginfod/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/DebugInfo/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/DWP/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/ExecutionEngine/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Target/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/SandboxIR/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/AsmParser/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/LineEditor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/ProfileData/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Passes/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/TargetParser/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/TextAPI/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Telemetry/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/ToolDrivers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/XRay/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/Testing/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/WindowsDriver/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/WindowsManifest/cmake_install.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9/build/lib/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
