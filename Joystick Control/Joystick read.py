from pygame import joystick
import pygame

joystick.init()

_joystick = joystick.Joystick(0)
_joystick.init()
print (_joystick.get_init())
print (_joystick.get_numaxes())


while True:
    print(_joystick.get_axis(0))

    