"""6utt3rd09 settings.

This file holds all the settings that will
define the execution of `6utt3rd09.exe`.

"""
import math


# Screen Resolution and Frame Rate
RES = WIDTH, HEIGHT = 800, 450
FPS = 60

# Player Characteristics
PLAYER_POS = 1.5, 5 # self.mini_map
PLAYER_ANGLE = 0
PLAYER_SPD = 0.004 # player velocity
PLAYER_ROT = 0.002 # rotation speed

# Raycasting Properties
FOV = math.pi / 3 # field of view
HALF_FOV = FOV / 2
NUM_RAYS = WIDTH // 2 # to make it realistic
HALF_NUM_RAYS = NUM_RAYS // 2
DELTA_ANGLE = FOV / NUM_RAYS # angle between rays
MAX_DEPTH = 10
