"""6utt3rd09 object renderer module.

This is where all sprites, objects and textures
will be handled and taken care of.

"""
import pygame as pg
from models.settings import *


class ObjectRenderer:
    """Define the object renderer."""

    def __init__(self, d09):
        """Initialize ObjectRenderer."""
        self.game = d09
        self.screen = d09.screen
        self.wall_textures = self.load_wall_textures()

    def draw(self):
        """Display rendered changes on window."""
        self.render_game_objects()

    def render_game_objects(self):
        """Render objects to display.

        We'll iterate over the list of objects to be rendered
        and draw the resulting texture columns onto the surfaces.

        """
        list_objects = self.game.raycasting.objects_to_render
        for depth, image, pos in list_objects:
            self.screen.blit(image, pos)

    @staticmethod
    def get_texture(path, res=(TEXTURE_SIZE, TEXTURE_SIZE)):
        """Fetch the Texture's path and resolution.

        Args:
            path (str): Texture path
            res ('obj': 'tuple'): Texture resolution

        Returns:
            A scaled image
        
        """
        texture = pg.image.load(path).convert_alpha()
        return pg.transform.scale(texture, res)

    def load_wall_textures(self):
        """Initialize wall textures.

        Returns:
            {texture_number: texture}
        """
        return {
            1: self.get_texture('resources/textures/ButterDog.jpeg'),
            2: self.get_texture('resources/textures/DaBaby.jpg'),
            3: self.get_texture('resources/textures/Mario.jpeg'),
            4: self.get_texture('resources/textures/SeeDel.png'),
            5: self.get_texture('resources/textures/SeePeePee.png')
        }
