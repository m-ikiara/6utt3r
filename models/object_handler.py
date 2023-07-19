"""6utt3rd09 object handler.

This'll simplify the process of loading
our Sprites and Objects as it will just
require this class only.

~~~~
sIdEbAr:
    #######################################
    #              PERKS                  #
    #  No need to call the AnimatedSprite #
    # and SpriteObject classes separately #
    #        GOOD OL' DRY ASP GIN!        #
    #######################################
~~~~

"""
from models.sprite_object import SpriteObject, AnimatedSprites


class ObjectHandler:
    """Defines the Object Handler utility."""

    def __init__(self, d09):
        """Initialize ObjectHandler."""
        self.game = d09
        self.sprite_list = []
        self.static_sprite_path = "resources/sprites/static_sprites"
        self.anim_sprite_path = "resources/sprites/animated_sprites"
        add_sprite = self.add_sprite
        # Intro to the Map data structure
        add_sprite(SpriteObject(d09))
        add_sprite(AnimatedSprites(d09))
        add_sprite(AnimatedSprites(d09, pos=(7, 5)))
        add_sprite(AnimatedSprites(d09, pos=(6.5, 4)))
        add_sprite(AnimatedSprites(d09, pos=(5, 7)))
        add_sprite(AnimatedSprites(d09, pos=(6, 9)))

    def update(self):
        """Refresh ObjectHandler.

        This'll be done recursively to avoid cumbersome Big O and
        Theta values.

        """
        [sprite.update() for sprite in self.sprite_list]

    def add_sprite(self, sprite):
        """Handle additional Sprites in folder.

        Args:
            sprite ('obj': 'image'): Sprite to be added

        """
        self.sprite_list.append(sprite)
