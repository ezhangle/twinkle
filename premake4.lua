solution "Twinkle"
   configurations { "Debug", "Release" }
   location "build"

project "Twinkle"
   kind "ConsoleApp"
   language "C++"

   files {
      "src/*.cpp",
      "src/*.h",
      "thirdparty/**.cpp",
      "thirdparty/**.c",
   }

   includedirs { "src", "thirdparty/compat/msvc", "thirdparty", "thirdparty/bgfx", "thirdparty/khronos"   }

   configuration "Debug"
      targetdir "build/debug"
      defines { "DEBUG", "_CRT_SECURE_NO_WARNINGS" }
      flags { "Symbols" }

   configuration "Release"
      targetdir "build/release"
      defines { "NDEBUG" }
      flags { "Optimize" }