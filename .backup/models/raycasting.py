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
        self.raycasting_result = []
        self.objects_to_render = []
        self.textures = self.game.object_renderer.wall_textures

    def get_objects_to_render(self):
        """Fetch objects to render.

        We'll get parameters calculated as a result of raycasting
        and based on them, for each ray, we'll select a subsurface
        in the form of a rectangle for each texture.

        """
        self.objects_to_render = []
        for ray, values in enumerate(self.raycasting_result):
            depth, proj_height, texture, offset = values
            # Get subsurface and handle N2W case
            if proj_height < HEIGHT:
                wall_column = self.textures[texture].subsurface(
                    offset * (TEXTURE_SIZE - SCALE), 0, SCALE, TEXTURE_SIZE
                )
                # Scale subsurface to projection height
                wall_column = pg.transform.scale(wall_column, (SCALE, proj_height))
                # Calculate the position based on the ray number and...
                wall_pos = (ray * SCALE, HALF_HEIGHT - proj_height // 2)
            else:
                texture_height = TEXTURE_SIZE * HEIGHT / proj_height
                wall_column = self.textures[texture].subsurface(
                    offset * (TEXTURE_SIZE - SCALE), HALF_TEXTURE_SIZE - texture_height // 2,
                    SCALE, texture_height
                )
                wall_column = pg.transform.scale(wall_column, (SCALE, HEIGHT))
                wall_pos = (ray * SCALE, 0)
            # add it to the list of objects to be rendered
            self.objects_to_render.append((depth, wall_column, wall_pos))


    def ray_cast(self):
        """Perform raycasting operations."""
        # Necessary pre-rendering clean-up
        self.raycasting_result = []
        # Original Player and Tile positions
        ox, oy = self.game.player.pos
        x_map, y_map = self.game.player.map_pos
        texture_vert, texture_hor = 1, 1
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
                    texture_hor = self.game.map.world_map[tile_hor]
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
                    texture_vert = self.game.map.world_map[tile_vert]
                    break
                # Cast a ray otherwise
                x_vert += dx
                y_vert += dy
                depth_vert += delta_depth

            # Determining the depth and texture offsets
            if depth_vert < depth_hor:
                depth, texture = depth_vert, texture_vert
                y_vert %= 1
                offset = y_vert if cos_a > 0 else (1 - y_vert)
            else:
                depth, texture = depth_hor, texture_hor
                x_hor %= 1
                offset = (1 - x_hor) if sin_a > 0 else x_hor
            # Eliminate Convex Distortion/Fishbowl effect
            depth *= math.cos(self.game.player.angle - ray_angle)

            # Draw to test raycasting
            #pg.draw.line(
            #    self.game.screen, "red", (50 * ox, 50 * oy),
            #    (50 * ox + 50 * depth * cos_a, 50 * oy + 50 * depth * sin_a), 2
            #)

            # Project to screen
            proj_height = SCREEN_DIST / (depth + 0.0001)

            # Draw walls: Pre-offsets
            #color = [255 / (1 + depth ** 5 * 0.00002)] * 3 # color depth
            #pg.draw.rect(
            #    self.game.screen, color,
            #    (ray * SCALE, HALF_HEIGHT - proj_height // 2,
            #     SCALE, proj_height) 
            #)

            # Determine result of Raycasting
            self.raycasting_result.append((depth, proj_height, texture, offset))

            ray_angle += DELTA_ANGLE

    def update(self):
        """Refresh RayCasting."""
        self.ray_cast()
        self.get_objects_to_render()
