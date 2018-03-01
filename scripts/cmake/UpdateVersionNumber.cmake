macro(UpdateVersionNumber)
  file(READ src/Switch.Core/src/Native/EnvironmentVersionApi.cpp ENVIRONMENT_VERSION_API)
  string(FIND "${ENVIRONMENT_VERSION_API}" "${Switch_VERSION}" STRING_FOUND)
  if (${STRING_FOUND} EQUAL -1)
    print("")
    print("--------------------------------")
    print("--- Version number changed ! ---")
    print("--------------------------------")
    print("")
    
    file(WRITE src/Switch.Core/src/Native/EnvironmentVersionApi.cpp
      "#include \"Api.hpp\"\n"
      "\n"
      "System::Version Native::EnvironmentApi::GetVersion() {\n"
      "  return System::Version::Parse(\"${Switch_VERSION}\");\n"
      "}\n"
    )
    
    file(WRITE .appveyor.yml
      "version: ${Switch_VERSION}.{build}\n"
      "image: Visual Studio 2017\n"
      "environment:\n"
      "  matrix:\n"
      "  - BUILD_OPTION: \"Visual Studio 14 2015\"\n"
      "  - BUILD_OPTION: \"Visual Studio 14 2015 Win64\"\n"
      "  - BUILD_OPTION: \"Visual Studio 15 2017\"\n"
      "  - BUILD_OPTION: \"Visual Studio 15 2017 Win64\"\n"
      "build_script:\n"
      "- cmd: scripts\\appveyor\\build.cmd\n"
      "test_script:\n"
      "- cmd: scripts\\appveyor\\test.cmd\n"
    )
    
    file(WRITE install.sh
      "export switch_version=${Switch_VERSION}\n"
      "scripts/install/install.sh \"$@\"\n"
    )
    
    file(WRITE install.cmd
      "@set switch_version=${Switch_VERSION}\n"
      "@call scripts\\install\\install.cmd %*\n"
    )
  endif()
endmacro()
