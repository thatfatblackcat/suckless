# My Personal DWM Build

## Installation

If you're using `musl` instead of `glibc` you're also going to need `musl-devel` for stdio.h and stuff.
Also don't forget to link `tcc` to `cc` in your `bin` directory, or edit `config.mk` appropriately.

Here's the command ready for Void Linux users, including `musl-devel` library.

```
xbps-install -S tcc make patch musl-devel libX11-devel libXft-devel libXinerama-devel
```

## Added Functionality

### Patches

* [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)
	> All floating windows are centered, like the center patch, but without a rule.

* [alwaysfullscreen](https://dwm.suckless.org/patches/alwaysfullscreen/)
	> Do not allow the focus to drift from the active fullscreen client when using focusstack().

### Layoyts

* [fibonacci](https://dwm.suckless.org/patches/fibonacci/)

	> This patch adds two new layouts that arrange all windows in fibonacci tiles: The first window uses half the screen, the second the half of the remainder, etc…

* [horizgrid](https://dwm.suckless.org/patches/horizgrid/)

	> This patch arranges windows in a grid pattern in which every window is roughly the same size, adjusted such that there are no gaps.

### Plugins

* [movestack](https://dwm.suckless.org/patches/movestack/)
	> This plugin allows you to move clients around in the stack and swap them with the master.

* [shiftview](https://dwm.suckless.org/patches/nextprev)
	> Allows you to cycle trough tags (workspaces).
