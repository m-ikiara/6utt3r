"""6utt3rd09 sprite component module.

This is to handle the generation and interactability
of the Sprites rendered to the display.

"""
import os
import pygame as pg
from collections import deque
from models.settings import *


class SpriteObject:
    """Defines the Sprites to be rendered."""

    def __init__(
        self, d09,
        path="resources/sprites/static_sprites/Hana.png",
        pos=(9, 6), scale=0.75, shift=0.23):
        """Initialize SpriteObject.

        Args:
            path (str): Sprite path
            pos ('obj': 'tuple'): Sprite location
            scale (float): Sprite scale
            shift (float): Sprite shift

        """
        self.game = d09
        self.player = d09.player
        self.x, self.y = pos
        self.image = pg.image.load(path).convert_alpha()
        self.IMAGE_WIDTH = self.image.get_width()
        self.IMAGE_HALF_WIDTH = self.image.get_width() // 2
        # Handle Sprite projection
        self.IMAGE_RATIO = self.IMAGE_WIDTH / self.image.get_height()
        self.dx, self.dy = 0, 0
        self.theta = 0
        self.screen_x = 0
        self.dist, self.norm_dist = 1, 1
        self.sprite_half_width = 0
        # Handle floaty Sprites
        self.SPRITE_SCALE = scale
        self.SPRITE_HEIGHT_SHIFT = shift

    def get_sprite_projection(self):
        """Get Sprit projection on screen.

        Since Sprite has different aspect ratio, we'll calculate
        the image ratio and correct the projection size, then scale
        it to the calculated projection size, find screen position
        (to ensure it doesn't disappear to screen edges) and append
        it to the array of the result of raycasting, for it to be
        rendered as part of the wall.

        """
        proj = SCREEN_DIST / self.norm_dist * self.SPRITE_SCALE
        proj_width, proj_height = proj * self.IMAGE_RATIO, proj 
        image = pg.transform.scale(self.image, (proj_width, proj_height))
        self.sprite_half_width = proj_width // 2
        height_shift = proj_height * self.SPRITE_HEIGHT_SHIFT
        pos = self.screen_x - self.sprite_half_width, HALF_HEIGHT - proj_height // 2 + height_shift
        self.game.raycasting.objects_to_render.append((self.norm_dist, image, pos))

    def get_sprite(self):
        """Fetch the Sprite to be rendered."""
        dx = self.x - self.player.x
        dy = self.y - self.player.y
        self.dx, self.dy = dx, dy
        self.theta = math.atan2(dy, dx) # sprite-player distance
        delta = self.theta - self.player.angle # change in observation
        # Handle edge cases
        if (dx > 0 and self.player.angle > math.pi) or (dx < 0 and dy < 0):
            delta += math.tau
        # Get Player shift and position along x-axis
        delta_rays = delta / DELTA_ANGLE
        self.screen_x = (HALF_NUM_RAYS + delta_rays) * SCALE
        # Handle potential Fishbowl effect
        self.dist = math.hypot(dx, dy)
        self.norm_dist = self.dist * math.cos(delta)
        if self.IMAGE_HALF_WIDTH < self.screen_x <\
            (WIDTH + self.IMAGE_HALF_WIDTH) and self.norm_dist > 0.5:
            self.get_sprite_projection()

    def update(self):
        """Refresh SpriteObject."""
        self.get_sprite()


class AnimatedSprites(SpriteObject):
    """Defines the animated sprites to be rendered.

    Args:
        SpriteObject ('obj': 'class'): Superclass

    """

    def __init__(
        self, d09,
        path="resources/sprites/animated_sprites/SoiBoi.gif",
        pos=(8, 5), scale=0.8, shift=0.15, animation_time=120):
        """Initialize AnimatedSprites.

        Args:
            path (str): Animated Sprite path
            pos ('obj': 'tuple'): Animated Sprite position
            scale (float): Animated Sprite scale
            shift (float): Amnimated Sprite shift
            animation_time (int): Animation time

        """
        super().__init__(d09, path, pos, scale, shift)
        self.animation_time = animation_time
        # Get path to animated sprites folder
        self.path = path.rsplit('/', 1)[0]
        self.images = self.get_images(self.path) # handle images
        # Define animation
        self.animation_time_prev = pg.time.get_ticks()
        self.animation_trigger = False

    def update(self):
        """Refresh AnimatedSprites."""
        super().update()
        self.check_animation_time()
        self.animate(self.images)

    def animate(self, images):
        """Bring the images to life.

        Args:
            images ('obj': 'list'): Image list

        """
        if self.animation_trigger:
            images.rotate(-1)
            self.image = images[0]

    def check_animation_time(self):
        """Confirm the animation frame."""
        self.animation_trigger = False
        time_now = pg.time.get_ticks()
        # Trigger when necessary
        if time_now - self.animation_time_prev > self.animation_time:
            self.animation_time_prev = time_now
            self.animation_trigger = True

    def get_images(self, path):
        """Handle the Animated Sprites from their container folder.

        Args:
            path (str): Animated Sprite folder path

        Returns:
            The individual Animated Sprites.

        """
        images = deque()
        for file_name in os.listdir(path):
            # Check whether it's a file in the path
            if os.path.isfile(os.path.join(path, file_name)):
                img = pg.image.load(path + '/' + file_name).convert_alpha()
                images.append(img)
        return images
