"""6utt3rd09 maps and levels.

This is where all the levels and maps will
be defined.

"""
import pygame as pg


_ = False
levelEins = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, _, _, _, _, _, _, _, _, _, _, _, _, _, _, 1],
    [1, _, _, 1, 1, 1, 1, _, _, _, _, _, _, _, _, 1],
    [1, _, 1, 1, _, _, _, _, _, _, 1, 1, _, _, _, 1],
    [1, _, 1, 1, _, _, _, _, _, 1, 1, 1, 1, _, _, 1],
    [1, _, 1, 1, _, _, _, _, _, _, _, _, 1, 1, _, 1],
    [1, _, 1, 1, _, _, _, _, _, _, _, _, 1, 1, _, 1],
    [1, _, _, 1, 1, 1, 1, _, _, _, _, _, 1, 1, _, 1],
    [1, _, _, _, 1, 1, _, _, _, _, _, _, 1, 1, _, 1],
    [1, _, _, _, _, _, _, _, _, 1, 1, 1, 1, _, _, 1],
    [1, _, _, _, _, _, _, _, _, _, _, _, _, _, _, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]


class Map:
    """Defines the Maps and Levels."""

    def __init__(self, d09):
        """Initialize map.

        Args:
            d09 ('obj': 'class'): The Butt3r Class Instance.

        """
        self.game = d09
        self.mini_map = levelEins
        self.world_map = {}
        self.get_map()

    def get_map(self):
        """Fetch the required map."""
        for i, row in enumerate(self.mini_map):
            for j, value in enumerate(row):
                if value:
                    self.world_map[(j, i)] = value

    def draw(self):
        """Display on window pre-rendering."""
        [pg.draw.rect(
            self.game.screen,
            "white", (pos[0] * 50, pos[1] * 50, 50, 50), 2)
            for pos in self.world_map]
