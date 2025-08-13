# typing-textdraw

[![sampctl](https://img.shields.io/badge/sampctl-typing--textdraw-2f2f2f.svg?style=for-the-badge)](https://github.com/aujiz11/typing-textdraw)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install aujiz11/typing-textdraw
```

Include in your code and begin using the library:

```pawn
#include <typing-textdraw>
```

## Usage

The library provides a simple way to display a typing animation using PlayerTextDraws. To use, call the `ShowTypingTextDraw` function:

```pawn
// Show a typing animation for the given player and PlayerText:id
ShowTypingTextDraw(playerid, PlayerText:id, "Your text here");
```
**Parameters for ShowTypingTextDraw:**
- `playerid`: The player to show the typing animation to.
- `id`: The PlayerTextDraw to update.
- `text[]`: The text to display with typing effect.
- `interval` (optional): Milliseconds between each character (default: TYPING_INTERVAL).

**Example:**
```pawn
new PlayerText:myTextDraw = CreatePlayerTextDraw(playerid, ...); // create your PlayerTextDraw
ShowTypingTextDraw(playerid, myTextDraw, "Welcome to the server!");
```

The typing animation will automatically stop when the text is fully displayed or the player disconnects.

When the typing animation finishes, the following callback is called:

```pawn
public OnTypingTextDrawFinish(playerid, PlayerText:playertextid)
{
    // Your code here
}
```
- `playerid`: The player whose animation finished.
- `playertextid`: The PlayerTextDraw that finished typing.

Use this callback to perform actions after the animation ends (e.g., show another message, hide the textdraw, etc).

### Definitions

You can customize the typing effect by defining these macros before including the library:

```pawn
#define TYPING_MAX_LENGTH  // Maximum length of the text (default: 1028)
#define TYPING_INTERVAL    // Interval in milliseconds between each character (default: 100)
```

Example:
```pawn
#define TYPING_MAX_LENGTH 512
#define TYPING_INTERVAL 50
#include <typing-textdraw>
```

## Demo

![Demo](demo.gif)

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
