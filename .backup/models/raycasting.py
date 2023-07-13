"""6utt3rd09 raycasting module.

Raycasting is a technique used in rendering
whereby changes are displayed based on the
"rays" emanating from the Player's field of
view and their interactions with the Game
objects.

"""
import math
import pygame as pg
from models.settings import *


class RayCasting:
    """Defines our Raycasting utility."""
    
    def __init__(self, d09):
        """Initialize RayCasting."""
        self.game = d09

    def ray_cast(self):
        """Do raycasting."""
        # Original Player and Tile positions
        ox, oy = self.game.player.pos
        x_map, y_map = self.game.player.map_pos
        # Define Ray angle and Raycasting loop
        ray_angle = self.game.player.angle - HALF_FOV + 0.0001
        for ray in range(NUM_RAYS):
            sin_a = math.sin(ray_angle)
            cos_a = math.cos(ray_angle)

            # Handle horizontal grid lines
            y_hor, dy = (y_map + 1, 1) if sin_a > 0 else (y_map - 1e-6, -1)
            depth_hor = (y_hor - oy) / sin_a
            x_hor = ox + depth_hor * cos_a
            delta_depth = dy / sin_a
            dx = delta_depth * cos_a

            # Cast rays to horizontals
            for i in range(MAX_DEPTH):
                tile_hor = int(x_hor), int(y_hor)
                # Check if we've encountered a wall
                if tile_hor in self.game.map.world_map:
                    break
                x_hor += dx
                y_hor += dy
                depth_hor += delta_depth 

            # Handle vertical grid lines
            x_vert, dx = (x_map + 1, 1) if cos_a > 0 else (x_map - 1e-6, -1)
            depth_vert = (x_vert - ox) / cos_a
            y_vert = oy + depth_vert * sin_a
            delta_depth = dx / cos_a
            dy = delta_depth * sin_a

            # Cast rays to verticals
            for i in range(MAX_DEPTH):
                tile_vert = int(x_vert), int(y_vert)
                # Check if we've encountered a wall
                if tile_vert in self.game.map.world_map:
                    break
                # Cast a ray otherwise
                x_vert += dx
                y_vert += dy
                depth_vert += delta_depth

            # Determining the depth we need
            if depth_vert > depth_hor:
                depth = depth_vert
            else:
                depth = depth_hor

            # Draw to test raycasting
            pg.draw.line(
                self.game.screen, "red", (50 * ox, 50 * oy),
                (50 * ox + 50 * depth * cos_a, 50 * oy + 50 * depth * sin_a), 2
            )

            ray_angle += DELTA_ANGLE

    def update(self):
        """Refresh RayCasting."""
        self.ray_cast()
