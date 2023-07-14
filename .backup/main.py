"""6utt3rd09 main runner.

This will be where the entry point and other major
stuff that govern the execution of `6utt3rd09.exe`
will be defined.

"""
import sys
import pygame as pg
from models.settings import *
from models.map import Map
from models.player import Player
from models.raycasting import RayCasting
from models.object_renderer import ObjectRenderer
from models.sprite_object import SpriteObject


class Butt3r:
    """Where 6utt3rd09 is defined."""

    def __init__(self):
        """Initialize 6utt3rd09."""
        pg.init()
        # Hide mouse pointer
        pg.mouse.set_visible(False)
        self.screen = pg.display.set_mode(RES)
        self.clock = pg.time.Clock()
        self.delta_time = 1
        self.new_game()
    
    def new_game(self):
        """Define a new game instance."""
        self.map = Map(self)
        self.player = Player(self)
        self.object_renderer = ObjectRenderer(self)
        self.raycasting = RayCasting(self)
        self.static_sprite = SpriteObject(self)

    def handle_events(self):
        """Manage whatever event there may be."""
        for event in pg.event.get():
            if event.type == pg.QUIT or (event.type == pg.KEYDOWN and event.key == pg.K_ESCAPE):
                pg.quit()
                sys.exit()

    def update(self):
        """Update the gameplay."""
        self.player.update()
        self.raycasting.update()
        self.static_sprite.update()
        pg.display.flip()
        self.delta_time = self.clock.tick(FPS)
        pg.display.set_caption("{:.1f}".format(
            self.clock.get_fps()
        ))

    def draw(self):
        """Display on window pre-rendering."""
        #self.screen.fill('black')
        self.object_renderer.draw()
        #self.map.draw()
        #self.player.draw()

    def run(self):
        """Execute 6utt3rd09.

        This is the main game loop. It's where all
        events will be handled, updated and the
        changes shall be rendered on the game window.

        """
        while True:
            self.handle_events()
            self.update()
            self.draw()


if __name__ == "__main__":
    """Create instance and run `6utt3rd09.exe`."""
    d09 = Butt3r()
    d09.run()
