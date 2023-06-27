## <img src="media/image8.jpg" style="width:6.4702in;height:0.11458in"
alt="horizontal line" /> 

<img src="media/image11.jpg" style="width:6.46354in;height:4.30903in"
alt="Placeholder image" />

6uττεrδ09 by iMjN - MVPSpec

***An emulator für mich, und für Sie.***

09.06.2023

**─**

Brian M’Ikiara

@alx_africa

#  

# Architecture

***This Project will be in 2 parts***:

## The HARDware 😜: The εµ Platform

> \**TBD by the end of Specialization*\*

This will be emulating a Game console’s hardware and the following
components make up a simple NES console:

### CPU(*central processing unit*) 🤖

You should know that this is what makes a rock a Computer. 🤣

### Memory 🧠

This is the **RAM**(*random access memory*) and you also know what that
is. We’ll be dealing with lots of
[**<u>Assembly</u>**](https://www.tutorialspoint.com/assembly_programming/assembly_introduction.htm)
and allocation of memory, which you should know ranges from the
addresses **0x00000000** to **0x0000ffff**(*for a standard computer, and
not a 🗿*). For the NES, it should span across **2KB** i.e. the
addresses **0x0000** to **0x07ff**.[^1]

### APU(*audio processing unit*) 🔊

This will handle all our **Sound**. This should span across the
addresses **0x4000** to **0x40**

**17**.

### PPU(*picture processing unit*) 🖼️

This is what handles all the **graphics** in our game, from **texture**
to **surface** rendering, **sprites** and all that 🍦😜.

***Time for a history lesson***:

> *The NES’s original* [**<u>Ricoh
> 2A03(NTSC)</u>**](https://en.wikipedia.org/wiki/Ricoh_2A03) *CPU
> didn’t have GPU support, (*it shouldn’t be confused with the
> **[<u>Ricoh 2A07(PAL)</u>](https://en.wikipedia.org/wiki/Ricoh_2A03)**
> version, by the way*), so they had to build a separate system
> entirely. With the new integrations in the **PAL** version, it means
> it will be harder to emulate the nitty-gritties(*especially the **bit
> fields** and the lot*). 😱*

### Cartridge 🧭

This is what houses our **game ROM**(*read-only memory*). All the
libraries and files needed to run our game will be stored in this
component. *It what you used to blow into, as a kid* e.g.
[<u>Sonic</u>](https://www.youtube.com/watch?v=25R7krgt8nM) and
[<u>Super Mario</u>](https://www.youtube.com/watch?v=1qcTwuKozs8).😅

### CIC(*checking integrated circuit*)

This is the **lockout chip** that was a security feature that checked
the authenticity of a **game ROM** using the “**lock and key**”
principle.[^2] Obviously, we’ll not be emulating this component because:

1.  The **game ROM** we’re building isn’t authentic, inherently, and… 😞

2.  It makes the emulator slow. 😆[^3]

With all that info I believe your brain is melting. Trust me, it’s
simple stuff. 😂

***[<u>Here’s an important message from the Man who can, literally, do
anything</u>](https://www.tiktok.com/@johnnysins/video/7150077316356410670).
Click the link, please!!!***

<img src="media/image12.jpg" style="width:2.54167in;height:2.15625in" />

## The SoFtWaRe ❄️: The 6uττεrδ09 Game

> \**TBD by now*\*

So the software defines the game itself. It will be a sh\*\*\*\*y,
**honestly…really bad - like Alpha Prime bad**, knock-off of the
original **Wolfenstein** by [<u>Muse
Software</u>](https://en.wikipedia.org/wiki/Wolfenstein#:~:text=1981%E2%80%931992%3A%20Muse%20Software,-The%20series%20presents&text=Castle%20Wolfenstein%20was%20developed%20by,especially%20in%20the%20stealth%20genre.).
The following defines the overall Architecture:

### Game Loop(GL)

This is the **MAIN** and most **IMPORTANT** component of our game as
it’s where all the **input** will be handled, the **game state** will be
updated and the **graphics** will be rendered.[^4]

### Rendering

This is where we’ll be handling the graphics using SDL-2. Our
**rendering context** will be defined here, our **textures**, **walls**,
**enemies** and any add-ons to the game will be handled here.

### Map Generation

This is where the levels will be defined.[^5] This is where all the
**layout** of surfaces and objects in the game shall be defined.

### Player Controls

Once we have the environment, it’s time to explore it![^6] We’ll define
**[<u>Player1</u>](https://www.rottentomatoes.com/m/ready_player_one)**
and their **mechanics + interaction** in this section**.**

### Collision Detection

This is where we’ll be implementing a technique known as
**[<u>Raycasting</u>](https://en.wikipedia.org/wiki/Ray_Charles)** that
will help define the overall **Game environment**.[^7]

### AI and Enemy Behavior

We’ll implement **AI**(*artificial intelligence*) for enemy characters
and then, define their **behavior**/**mechanics**, such as
**pathfinding**, **line-of-sight detection**, and **attacking
strategies**.[^8]

### Weapons and Projectiles

We’ll create a variety of weapons that the player can acquire, each with
different **attributes** such as *damage*, *rate of fire*, and *range*
and then, implement **projectile mechanics** for bullets or other
projectiles fired by the player or enemies.[^9]

### Audio

We’ll utilize the SDL-2 library to handle **audio playback**. Include
**SFX**(*sound effects*) for player actions, enemy sounds,
**BGM**(*background music*), and other in-game audio.

### User Interface

We’ll be designing and implementing the **user interface elements**,
including **menus**, **HUD** (*heads-up display*), **scoreboards**, and
other relevant information displayed on the screen.

### Game Logic and State Management

In this section, we’ll develop the game logic to handle events,
transitions between **game states** (e.g.: *menu*, *gameplay*, *pause*,
*scoring*, *level progression* and *game over conditions*) and implement
**save/load functionality** if desired.

### Optimization and Performance

We’ll be taking into account the various **performance optimizations**,
such as **ERTs**(*efficient rendering techniques*), **spatial
partitioning** for collision detection, and minimizing
**over/under-calculation**.

### Testing and Debugging

**TDD**(*test-driven development*) is a key philosophy in
**SDLC**(*Software Development Life Cycle*). The key is to regularly
test and debug our game to ensure it functions as intended. For this
we’ll be implementing **logging** + **debugging tools** to aid in
identifying and fixing issues.[^10]

# APIs and Methods

<img src="media/image14.jpg" style="width:3.125in;height:1.75in" />

# Data Modelling

## The Game Setup

<img src="media/image6.png" style="width:6.5in;height:2.16667in" />

## The Player Setup

<img src="media/image3.png" style="width:3.07292in;height:4.78125in" />

<img src="media/image2.png" style="width:5.80208in;height:2.375in" />

## The Characters, Opponents and Skills Setup

<img src="media/image1.png" style="width:6.5in;height:3.08333in" />

<img src="media/image5.jpg" style="width:0.86979in;height:0.86979in" />

I know, I know! It looks hard but we shall persevere! Lessgo! 💥

# User Stories

The following are what should be **met** and/or **avoided** when
launching the Game:

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<thead>
<tr class="header">
<th><strong>😇</strong></th>
<th><strong>👿</strong></th>
</tr>
<tr class="odd">
<th><ul>
<li><blockquote>
<p>“As a player, I want to navigate through intricately designed levels
filled with challenging obstacles and hidden secrets to create an
immersive and engaging gameplay experience.” <em><strong>From
@theGigaChad</strong></em></p>
</blockquote></li>
<li><blockquote>
<p>“As a player, I want a wide variety of powerful weapons at my
disposal, each with unique characteristics and upgrade options, so that
I can strategically choose the best weapon for different combat
scenarios.” <em><strong>From @sHREKy</strong></em></p>
</blockquote></li>
<li><blockquote>
<p>“As a player, I want to experience intense and fast-paced combat
against intelligent enemy AI, where enemies adapt their behavior and
tactics based on the player's actions, providing a satisfying and
challenging gameplay experience.” <em><strong>From
@johnnysins</strong></em></p>
</blockquote></li>
</ul></th>
<th><ul>
<li><blockquote>
<p>“As a player, I don't want to encounter game-breaking bugs or
glitches that disrupt the gameplay, cause crashes, or prevent progress,
as they negatively impact the overall experience and frustrate me.”
<em><strong>From @_nErAk_21_</strong></em></p>
</blockquote></li>
</ul>
<ul>
<li><blockquote>
<p>“As a player, I don't want to face unfair or inconsistent collision
detection, where I can get stuck in walls or experience unexpected
interactions with the game environment, as it breaks immersion and
hinders smooth gameplay.” <em><strong>From @Q-Rain69</strong></em></p>
</blockquote></li>
</ul>
<ul>
<li><blockquote>
<p>“As a player, I don't want to be limited by poor performance
optimization, such as frequent lag or frame rate drops, as it detracts
from the excitement and responsiveness of the game, making it less
enjoyable to play.” <em><strong>From @K4r3n420</strong></em></p>
</blockquote></li>
</ul></th>
</tr>
</thead>
<tbody>
</tbody>
</table>

# Mockups

This is how the Title Screen will look like. More Wireframing needs to
be done, I know but please…[<u>Daddy
Chill?</u>](https://www.youtube.com/watch?v=h0-WO6xRbAo)

<img src="media/image4.png" style="width:6.5in;height:4.875in" />

# Parting Shot[^11]

Emulation can be difficult but as Mario would put it:

<img src="media/image8.jpg" style="width:2.15625in;height:2.54167in" />

**LET’S A GO!!!!!**

[^1]: Welcome to the beautiful world of **ASM**(*assembly*). 🎉 The
    addresses **0x00000000** & **0x0000ffff**, or simply **0x0000** &
    **0xffff**, denote the lowest and highest possible memory address in
    a **16-bit byte-addressable** system i.e. 65536 bytes of memory. 🤯
    **RTFM, will you?**

[^2]: The ‘**key**’ was stored in the Cartridge that opened the
    ‘**lock**’ that was stored in the Console.

[^3]: Plus, I’m pretty lazy…**this documentation shouldn’t fool you**!

[^4]: It is important to maintain a constant **frame rate** and the GL
    should run **continuously**. 🤓

[^5]: There will be 3 in this implementation, but more are coming soon.
    😆

[^6]: You’ll have your 🥮 and eat it, in this rare scenario. Can I get
    Three Cheers over here? 😂

[^7]: This includes, and is not limited to, the **player-enemy-object
    interactions**. Make sure your game doesn’t get utterly annihilated
    like **Alpha Prime** by [<u>Black Element
    Software</u>](https://en.wikipedia.org/wiki/Alpha_Prime). 🤣

[^8]: Enemies should be able to navigate the game world and engage the
    player in combat. Sounds [**<u>HARD</u>**](https://g.co/kgs/unQ394),
    no? 😜

[^9]: Finally, my knowledge in Analytical Chemistry will be relevant! 😀

[^10]: This is a component that pervades 🤓, the architecture of the
    Project and this is why we’ve listed it las the last.

[^11]:
    > At the time of writing this ich habe keine Idee of what I’d be
    > doing for my Project. I hope you’ll find this as fascinating as I
    > did. 😃
