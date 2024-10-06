# JoystickToTankSteering
A function I came up with to translate joystick input into wheel motion for differential steering vehicles. Primarily made with videogames in mind. This was inspired by the game Roblox (2009 era) which allowed players to easily build vehicles that would use this type of steering.

Written in C++ but can be easily translated to any other language.

The primary feature of this function is that it's continuous across a typical joystick space [-1,1], instead of only trying to handle integer inputs with if statements.
The output of the function is a 2D Vector where the y component is the motion of the left wheels, and the y component is the motion of the right wheels.
So an input value like (0,0.72) will give an output of (0.72,0.72), and an input of (0.687,-0.721) should give an output of (-0.644331, -0.500473)

And of course, the output of this function can be multiplied to scale up/down the speed/torque you want for your wheels.

The function also contains 2 constants which you could change to tweak the wheel speeds. It may also be preferred that these values be additional arguments that are fed in from somwhere else.
There are many ways this function could be improved apon, but right now it serves as a basic starting point for when you want tank-like steering.
