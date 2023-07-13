"""6utt3rd09 settings.

This file holds all the settings that will
define the execution of `6utt3rd09.exe`.

"""
import math


# Screen Resolution and Frame Rate
RES = WIDTH, HEIGHT = 800, 600
HALF_WIDTH = WIDTH // 2
HALF_HEIGHT = HEIGHT // 2
FPS = 60

# Player Characteristics
PLAYER_POS = 1.5, 5 # self.mini_map
PLAYER_ANGLE = 0
PLAYER_SPD = 0.004 # player velocity
PLAYER_ROT = 0.002 # rotation speed
PLAYER_SIZE_SCALE = 60 # to handle N2W pixelation

# Mouse Properties
MOUSE_SENSITIVITY = 0.0003 # how it feels
MOUSE_MAX_REL = 40 # relative movement
MOUSE_BORDER_LEFT = 100
MOUSE_BORDER_RIGHT = WIDTH - MOUSE_BORDER_LEFT

# Ceiling and Floor Properties
FLOOR_COLOR = (30, 30, 30)

# Raycasting Properties
FOV = math.pi / 3 # field of view
HALF_FOV = FOV / 2
NUM_RAYS = WIDTH // 2 # to make it realistic
HALF_NUM_RAYS = NUM_RAYS // 2
DELTA_ANGLE = FOV / NUM_RAYS # angle between rays
MAX_DEPTH = 20

# Screen Location
SCREEN_DIST = HALF_WIDTH / math.tan(HALF_FOV)
SCALE = WIDTH // NUM_RAYS # scaling factor

# Texture Properties
TEXTURE_SIZE = 256
HALF_TEXTURE_SIZE = TEXTURE_SIZE // 2
