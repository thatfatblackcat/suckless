# My Personal DWM Build

## Installation

If you're using `musl` instead of `glibc` you're also going to need `musl-devel` for stdio.h and stuff.
Also don't forget to link `tcc` to `cc` in your `bin` directory, or edit `config.mk` appropriately.

Here's the command ready for Void and Alpine Linux users.

```
xbps-install -S tcc make patch musl-devel libX11-devel libXft-devel libXinerama-devel
apk add tcc make patch musl-dev libx11-dev libxft-dev libxinerama-dev
```

## Added Functionality

### Patches

* [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)
	> All floating windows are centered, like the center patch, but without a rule.

* [alwaysfullscreen](https://dwm.suckless.org/patches/alwaysfullscreen/)
	> Do not allow the focus to drift from the active fullscreen client when using focusstack().

### Layoyts

* [fibonacci](https://dwm.suckless.org/patches/fibonacci/)

```
+-----------+-----------+  +-----------+-----------+
|           |           |  |           |           |
|           |     2     |  |           |     2     |
|           |           |  |           |           |
|     1     +--+--+-----+  |     1     +-----+-----+
|           | 5|-.|     |  |           |     |  4  |
|           +--+--+  3  |  |           |  3  +--+--+
|           |  4  |     |  |           |     | 5|-.|
+-----------+-----+-----+  +-----------+-----+-----+
```

* [horizgrid](https://dwm.suckless.org/patches/horizgrid/)

```
  horizgrid     (###)
  +--------+--------+
  |        |        |
  |        |        |
  +-----+--+--+-----+
  |     |     |     |
  |     |     |     |
  +-----+-----+-----+
```

### Plugins

* [movestack](https://dwm.suckless.org/patches/movestack/)
	> This plugin allows you to move clients around in the stack and swap them with the master.

* [shiftview](https://dwm.suckless.org/patches/nextprev)
	> Allows you to cycle trough tags (workspaces).
