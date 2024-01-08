---
# Feel free to add content and custom Front Matter to this file.
# To modify the layout, see https://jekyllrb.com/docs/themes/#overriding-theme-defaults

layout: post
title: '6utt3rd09: The Ray-casting Engine'
---

## 🧈 Getting Started

1. Ensure you have Python 3.10.x and PyGame installed and added onto your `$PATH`.

> You may need to install Cython, libsdl2-dev and libfreetype-dev + build-essential(*Ubuntu/Debian*)/base-devel(*Arch*) first before running the following.

2. Clone the repo using either of the following commands:

```bash
$ git clone https://github.com/brian-ikiara/6utt3rd09.git
```

3. Navigate into the new directory and execute the following:

```bash
$ python3 -m pip install --upgrade -r requirements.txt
$ python3 ./main.py
```

4. Use the mouse and `WASD` key-bindings for movement around the basic map.

5. Enjoy! :tada:

## 🍀 The possibilities are endless!

Head over to `models/map.py` and play around with the code. You can implement Procedural Generation if you'd like...

{% highlight python %}
...

#modify it to your own liking
def draw(self):
    """Display on window pre-rendering."""
    [pg.draw.rect(
        self.game.screen,
        "white", (pos[0] * 50, pos[1] * 50, 50, 50), 2)
        for pos in self.world_map]

...
{% endhighlight %}

...maybe even define your own Ray-tracing Algorithms and replace `models/raycasting.py`. Have a go at it.


## 😁 More company soon...
