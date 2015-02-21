# Twinkle
GPU-accelerated UI framework powered by JavaScript for desktop/mobile apps

![Screenshot](https://raw.githubusercontent.com/cgbystrom/twinkle/master/screenshot1.jpg)

## Getting started

Even though the underlying render library supports multiple platforms,
Twinkle right now requires Windows to run/build.
On top of that you need Visual Studio (preferably 2013) and the DirectX SDK.

1. Git clone the project
1. Run ```bin\premake4 vs2013``` to generate a solution file
   (change parameter to whatever MSVS version you have)
1. Run ```example\compile_shaders.bat``` to compile the shaders from the example
1. Open the solution file and build it, then run it!
1. Profit!

## TODO
Lol, everything.

## Inspiration
 * The workflows of HTML/CSS
 * Love2D
 * React and React Native
 * Netflix's Gibbon
