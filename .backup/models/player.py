"""6utt3rd09 player definition.

This will define the player characteristics
and attributes.

"""
import math
import pygame as pg
from models.settings import *


class Player:
    """Defines a Player/Character."""

    def __init__(self, d09):
        """Initialize Player.

        Args:
            d09 ('obj': 'class'): The Butt3r instance

        """
        self.game = d09
        self.x, self.y = PLAYER_POS
        self.angle = PLAYER_ANGLE
    
    def movement(self):
        """Mechanise the Player."""
        sin_a = math.sin(self.angle)
        cos_a = math.cos(self.angle)
        dx, dy = 0, 0
        speed = PLAYER_SPD * self.game.delta_time
        speed_sin = speed * sin_a
        speed_cos = speed * cos_a

        # Define linear velocity
        keys = pg.key.get_pressed()
        if keys[pg.K_w]:
            dx += speed_cos
            dy += speed_sin
        if keys[pg.K_a]:
            dx += speed_sin
            dy += -speed_cos
        if keys[pg.K_s]:
            dx += -speed_cos
            dy += -speed_sin
        if keys[pg.K_d]:
            dx += -speed_sin
            dy += speed_cos

        self.check_wall_collision(dx, dy)

        # Define angular rotation using key presses
        #if keys[pg.K_LEFT]:
        #    self.angle -= PLAYER_ROT * self.game.delta_time
        #if keys[pg.K_RIGHT]:
        #    self.angle += PLAYER_ROT * self.game.delta_time
        self.angle %= math.tau # 360 degrees or 2 * Pi radians

    def check_wall(self, x, y):
        """Detect walls.

        Args:
            x (float): Player's X coordinate
            y (float): Player's Y coordinate

        Returns:
            Confirmation of wall presence.

        """
        return (x, y) not in self.game.map.world_map

    def check_wall_collision(self, dx, dy):
        """Handle wall collision.

        Args:
            dx (float): Change in x
            dy (float): Change in y

        """
        # Check N2W value => Player size shouldn't be affected with
        # values of dx and dy
        scale = PLAYER_SIZE_SCALE / self.game.delta_time
        if self.check_wall(int(self.x + dx * scale), int(self.y)):
            self.x += dx
        if self.check_wall(int(self.x), int(self.y + dy * scale)):
            self.y += dy

    def mouse_control(self):
        """Handle mouse/touchpad input."""
        mx, my = pg.mouse.get_pos()
        # Check whether mouse is within bounds
        if mx < MOUSE_BORDER_LEFT or mx > MOUSE_BORDER_RIGHT:
            pg.mouse.set_pos([HALF_WIDTH, HALF_HEIGHT]) # at center
        self.rel = pg.mouse.get_rel()[0] # at previous frame
        self.rel = max(-MOUSE_MAX_REL, min(MOUSE_MAX_REL, self.rel))
        # Modify Player angle to be that of mouse's relative position
        self.angle += self.rel * MOUSE_SENSITIVITY * self.game.delta_time


    def update(self):
        """Refresh Player."""
        self.movement()
        self.mouse_control()

    def draw(self):
        """Display on window pre-rendering."""
        pg.draw.line(
            self.game.screen, "red",
            (self.x * 50, self.y * 50),
            (self.x * 50 + WIDTH * math.cos(self.angle),
            self.y * 50 + WIDTH * math.sin(self.angle)), 2)
        pg.draw.circle(
            self.game.screen, "blue",
            (self.x * 50, self.y * 50), 7.5)
            
    @property
    def pos(self):
        """Return Player current position.

        Returns:
            The actual Player coordinates.

        """
        return self.x, self.y

    @property
    def map_pos(self):
        """Return Player map position.

        Returns:
            The tile on which Player is at.

        """
        return int(self.x), int(self.y)
