# 6uττεrδ09 by iMjN - MVPSpec

## <img src="./assets/images/Mario.jpeg" style="width:6.4702in;height:0.11458in" alt="Mario" /> 

<img src="./assets/images/butterScreen.png" style="width:6.46354in;height:4.30903in" alt="Tantrix" />

***An emulator für mich, und für Sie.***

09.06.2023

-------------------------------------

Brian M’Ikiara

@alx_africa

\#Cohort_10 \#DoThemHardThings \#DaddyAL-X

-------------------------------------

## Link to Demo

[![6utt3rd09 by iMjN](https://www.youtube.com/watch?v=p3GXnwfMs0k)](https://youtu.be/p3GXnwfMs0k)

## Team

<table>
<colgroup>
<col style="width: 25%" />
<col style="width: 27%" />
<col style="width: 17%" />
<col style="width: 29%" />
</colgroup>
<thead>
<tr class="header">
<th><strong>Member</strong></th>
<th><strong>Socials</strong></th>
<th><strong>Role</strong></th>
<th><strong>Reason</strong></th>
</tr>
<tr class="odd">
<th><ol type="1">
<li><blockquote>
<p>Brian M’Ikiara 😡</p>
</blockquote></li>
</ol></th>
<th>(<a href="https://github.com/brian-ikiara/"><u>GitHub</u></a>, <a
href="https://twitter.com/brian_ikiara"><u>Twitter</u></a>)</th>
<th>CTO and Founder of iMjN</th>
<th><em><strong>They’re the owner of the idea.</strong></em></th>
</tr>
<tr class="header">
<th><ol start="2" type="1">
<li><blockquote>
<p>Mr. Nobody 👻</p>
</blockquote></li>
</ol></th>
<th>(<a
href="https://www.youtube.com/watch?v=ryaksaimqU4"><u>GitHub</u></a>, <a
href="https://www.youtube.com/watch?v=ryaksaimqU4"><u>Twitter</u></a>)</th>
<th>Mascot</th>
<th><em><strong>Er ist wirklich cool und intressant.</strong></em></th>
</tr>
</thead>
<tbody>
</tbody>
</table>

## Architecture

***This Project will be in 2 parts***:

### The HARDware 😜: The εµ Platform

> \**TBD by the end of Specialization*\*

This will be emulating a Game console’s hardware and the following
components make up a simple NES console:

#### CPU(*central processing unit*) 🤖

You should know that this is what makes a rock a Computer. 🤣

#### Memory 🧠

This is the **RAM**(*random access memory*) and you also know what that
is. We’ll be dealing with lots of
[**<u>Assembly</u>**](https://www.tutorialspoint.com/assembly_programming/assembly_introduction.htm)
and allocation of memory, which you should know ranges from the
addresses **0x00000000** to **0x0000ffff**(*for a standard computer, and
not a 🗿*). For the NES, it should span across **2KB** i.e. the
addresses **0x0000** to **0x07ff**.[^1]

#### APU(*audio processing unit*) 🔊

This will handle all our **Sound**. This should span across the
addresses **0x4000** to **0x40**

**17**.

#### PPU(*picture processing unit*) 🖼️

This is what handles all the **graphics** in our game, from **texture**
to **surface** rendering, **sprites** and all that 🍦😜.

***Time for a history lesson***:

> *The NES’s original* [**<u>Ricoh 2A03(NTSC)</u>**](https://en.wikipedia.org/wiki/Ricoh_2A03)
> *CPU didn’t have GPU support, (*it shouldn’t be confused with the
> **[<u>Ricoh 2A07(PAL)</u>](https://en.wikipedia.org/wiki/Ricoh_2A03)**
> version, by the way*), so they had to build a separate system
> entirely. With the new integrations in the **PAL** version, it means
> it will be harder to emulate the nitty-gritties(*especially the **bit
> fields** and the lot*). 😱*

#### Cartridge 🧭

This is what houses our **game ROM**(*read-only memory*). All the
libraries and files needed to run our game will be stored in this
component. *It what you used to blow into, as a kid* e.g.
[<u>Sonic</u>](https://www.youtube.com/watch?v=25R7krgt8nM) and
[<u>Super Mario</u>](https://www.youtube.com/watch?v=1qcTwuKozs8).😅

#### CIC(*checking integrated circuit*)

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

<img src="./assets/images/YesPapa.jpg" style="width:2.54167in;height:2.15625in" />

### The SoFtWaRe ❄️: The 6uττεrδ09 Game

> \**TBD by now*\*

So the software defines the game itself. It will be a sh\*\*\*\*y,
**honestly…really bad - like Alpha Prime bad**, knock-off of the
original **Wolfenstein** by [<u>Muse
Software</u>](https://en.wikipedia.org/wiki/Wolfenstein#:~:text=1981%E2%80%931992%3A%20Muse%20Software,-The%20series%20presents&text=Castle%20Wolfenstein%20was%20developed%20by,especially%20in%20the%20stealth%20genre.).
The following defines the overall Architecture:

#### Game Loop(GL)

This is the **MAIN** and most **IMPORTANT** component of our game as
it’s where all the **input** will be handled, the **game state** will be
updated and the **graphics** will be rendered.[^4]

#### Rendering

This is where we’ll be handling the graphics using SDL-2. Our
**rendering context** will be defined here, our **textures**, **walls**,
**enemies** and any add-ons to the game will be handled here.

#### Map Generation

This is where the levels will be defined.[^5] This is where all the
**layout** of surfaces and objects in the game shall be defined.

#### Player Controls

Once we have the environment, it’s time to explore it![^6] We’ll define
**[<u>Player1</u>](https://www.rottentomatoes.com/m/ready_player_one)**
and their **mechanics + interaction** in this section**.**

#### Collision Detection

This is where we’ll be implementing a technique known as
**[<u>Raycasting</u>](https://en.wikipedia.org/wiki/Ray_Charles)** that
will help define the overall **Game environment**.[^7]

#### AI and Enemy Behavior

We’ll implement **AI**(*artificial intelligence*) for enemy characters
and then, define their **behavior**/**mechanics**, such as
**path finding**, **line-of-sight detection**, and **attacking
strategies**.[^8]

#### Weapons and Projectiles

We’ll create a variety of weapons that the player can acquire, each with
different **attributes** such as *damage*, *rate of fire*, and *range*
and then, implement **projectile mechanics** for bullets or other
projectiles fired by the player or enemies.[^9]

#### Audio

We’ll utilize the SDL-2 library to handle **audio playback**. Include
**SFX**(*sound effects*) for player actions, enemy sounds,
**BGM**(*background music*), and other in-game audio.

#### User Interface

We’ll be designing and implementing the **user interface elements**,
including **menus**, **HUD** (*heads-up display*), **scoreboards**, and
other relevant information displayed on the screen.

#### Game Logic and State Management

In this section, we’ll develop the game logic to handle events,
transitions between **game states** (e.g.: *menu*, *gameplay*, *pause*,
*scoring*, *level progression* and *game over conditions*) and implement
**save/load functionality** if desired.

#### Optimization and Performance

We’ll be taking into account the various **performance optimizations**,
such as **ERTs**(*efficient rendering techniques*), **spatial
partitioning** for collision detection, and minimizing
**over/under-calculation**.

#### Testing and Debugging

**TDD**(*test-driven development*) is a key philosophy in
**SDLC**(*Software Development Life Cycle*). The key is to regularly
test and debug our game to ensure it functions as intended. For this
we’ll be implementing **logging** + **debugging tools** to aid in
identifying and fixing issues.[^10]

## APIs and Methods

<img src="./assets/images/Shocked.jpg" style="width:3.125in;height:1.75in" />

## Existing Solutions

### Mupen64 Emulator

> IMO, the best emulator on the market right now.

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<thead>
<tr class="header">
<th><strong>Similarities</strong></th>
<th><strong>Differences</strong></th>
</tr>
<tr class="odd">
<th><ul>
<li><blockquote>
<p>Emulates hardware.</p>
</blockquote></li>
<li><blockquote>
<p>Can run a game ROM.</p>
</blockquote></li>
<li><blockquote>
<p>Pretty sleek.</p>
</blockquote></li>
</ul></th>
<th><ul>
<li><blockquote>
<p>Well…um…it’s just…<strong>BETTER</strong>! 😂</p>
</blockquote></li>
</ul></th>
</tr>
</thead>
<tbody>
</tbody>
</table>

### SNES9x EX+

> This is another favorite of mine. It runs the Super Nintendo Super
> ROMS, smoothly. Pretty neat, no?

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<thead>
<tr class="header">
<th><strong>Similarities</strong></th>
<th><strong>Differences</strong></th>
</tr>
<tr class="odd">
<th><ul>
<li><blockquote>
<p>Built in C.</p>
</blockquote></li>
<li><blockquote>
<p>Simple and robust.</p>
</blockquote></li>
<li><blockquote>
<p>Can run a game ROM.</p>
</blockquote></li>
</ul></th>
<th><ul>
<li><blockquote>
<p>Deployed in Android</p>
</blockquote></li>
<li><blockquote>
<p>And…um…it’s just…<strong>YK 😅</strong></p>
</blockquote></li>
</ul></th>
</tr>
</thead>
<tbody>
</tbody>
</table>

# Parting Shot[^11]

Emulation can be difficult but as Mario would put it:

<img src="./assets/images/Mario.jpeg" style="width:2.15625in;height:2.54167in" />

**LET’S A GO!!!!!**

[^1]:
    > Welcome to the beautiful world of **ASM**(*assembly*). 🎉 The
    > addresses **0x00000000** & **0x0000ffff**, or simply **0x0000** &
    > **0xffff**, denote the lowest and highest possible memory address in
    > a **16-bit byte-addressable** system i.e. 65536 bytes of memory. 🤯
    > **RTFM, will you?**

[^2]: 
    > The ‘**key**’ was stored in the Cartridge that opened the
    > ‘**lock**’ that was stored in the Console.

[^3]: Plus, I’m pretty lazy…**this documentation shouldn’t fool you**!

[^4]:
    > It is important to maintain a constant **frame rate** and the GL
    > should run **continuously**. 🤓

[^5]:
    > There will be 3 in this implementation, but more are coming soon.
    > 😆

[^6]:
    > You’ll have your 🥮 and eat it, in this rare scenario. Can I get
    > Three Cheers over here? 😂

[^7]:
    > This includes, and is not limited to, the **player-enemy-object
    > interactions**. Make sure your game doesn’t get utterly annihilated
    > like **Alpha Prime** by [<u>Black Element
    > Software</u>](https://en.wikipedia.org/wiki/Alpha_Prime). 🤣

[^8]:
    > Enemies should be able to navigate the game world and engage the
    > player in combat. Sounds [**<u>HARD</u>**](https://g.co/kgs/unQ394),
    > no? 😜

[^9]: Finally, my knowledge in Analytical Chemistry will be relevant! 😀

[^10]:
    > This is a component that pervades 🤓, the architecture of the
    > Project and this is why we’ve listed it las the last.

[^11]:
    > At the time of writing this ich habe keine Idee of what I’d be
    > doing for my Project. I hope you’ll find this as fascinating as I
    > did. 😃
