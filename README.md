# (Hopefully) A Minecraft Clone

This is my attemp to make a 3D game similar to Minecraft.

## Tech

I am using Raylib 4.5.0 and C++.

## How to get it going

I am storing the raylib files in a 'lib' directory, so you can simply create a 'lib' directory and add the following files:

- raylib.a
- rahlib.h
- raymath.h
- rcamera.h

To get 'raylib.a' you need to build it from source code for your platform. The header files can be just directly duplicated from the raylib [repo](https://github.com/raysan5/raylib/tree/master/src). There is this awesome [thread](https://www.reddit.com/r/raylib/comments/sh586x/hi_im_trying_to_get_raylib_to_work_on_mac_ive/) explaining how to do this for macs.

My Makefile is made for macs, so if you are also using a mac, run the following to compile:
```
$ make
```
This creates an executable in the 'bin' directory. Run it:
```
$ ./bin/build_osx
```

If you are using Windows, and if you already know how to work with raylib, you can just copy all the files under /src and plug them into your workflow.

## How to play

Uhh it doesn't do much yet, but you can walk around the world with the WASD keys and use your mouse to look around. You can also jump with the space key. The bare bones Minecraft functionality is achieved. There is even a green block you can look at.