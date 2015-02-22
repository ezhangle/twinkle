# Twinkle
GPU-accelerated UI framework powered by JavaScript for desktop/mobile apps.
Idea is to combine the fast workflow and deployment model of web with the performance
of native code and GPU acceleration.

![Screenshot](https://raw.githubusercontent.com/cgbystrom/twinkle/master/screenshot1.jpg)

## Motivation
Web provides some really nice development models. It's fast at creating things with save-reload cycles
being below a second. Deployment is also very straightforward and new content is at the push of a button
rolled out to all users.

However, it is easy to conflate web and fast workflows. In theory, you *can* have the latter without buying into the browser model.
A lot of the problems with achieving 60 FPS performance by using HTML/DOM stem from the execution model of browsers.
Browsers expect everything to happen inside one loop/thread. That includes:
HTML parsing, style calculation, layouting, painting, compositing, JS execution, garbage collection, image decoding,
image resizing, JSON serialization and so on. In short, HTML/DOM carries a lot of legacy making
performant UIs difficult if not impossible, unless you are on a very high-end desktop machine.

This may be fine when you are actually doing what the DOM was designed for - creating documents.
But when high fidelity UIs expected to run at 60 FPS are being forced on top of the DOM, problem arises.
As someone said, image decoding alone is a showstopper for 60 FPS when doing everything serially.

The plan for Twinkle is to address this problem. Take the good parts from HTML/CSS, parallelize heavy operations and go GPU only.
Fortunately, Twinkle is not the first to try attacking this. The closest thing we've heard about
is Netflix's Gibbon, which they talked about at React.js Conf 2015. From what one can learn there is that Gibbon is a
retained UI built using JavaScript with loads of different rendering backends. Each supporting the vastly different platforms Netflix TV UI
is expected to run on. As of late, Gibbon seem to have React.js support.

Facebook themselves also announced "react-native" at mentioned conference. They are essentially doing the same thing - 
UI logic in JavaScript with async communication back to native code. However, Facebook is targeting mobile only which
lets them use each platform's native UI framework.

For Twinkle and Gibbon, such an alternative may be harder since the target platform is unknown.

## Getting started

Right now, Twinkle requires Windows, Visual Studio 2013 and the DirectX SDK to build (*)

To get started:
1. Git clone the project
1. Run ```bin\premake4 vs2013``` to generate a solution file
1. Run ```example\compile_shaders.bat``` to compile the shaders from the example
1. Open the solution file, build it and then run it!
1. Profit!

*) bgfx is inherently cross-platform so supporting more environments is very feasible.
The css-layout library currently is C99 which only VS2013 and above supports on Windows.

Keyboard shortcuts:
 * F1: Toggle render stats
 * F3: Toggle wireframe
 * F7: Toggle vsync

## TODO
Lol, everything.

## Inspiration
 * The workflows of HTML/CSS
 * Love2D
 * react-canvas
 * React and React Native
 * Netflix's Gibbon
