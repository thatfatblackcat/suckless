# My Personal DWM Build

## Installation

If you're using `musl` instead of `glibc`, you're also going to need `musl-devel`.
Don't forget to link `tcc` to `cc` or edit `config.mk`.

Here's the command ready for Void Linux users, including the `musl-devel` library.

```
xbps-install -S tcc make patch musl-devel libX11-devel libXft-devel libXinerama-devel
```

## Added Functionality

### Patches

* [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)
* [alwaysfullscreen](https://dwm.suckless.org/patches/alwaysfullscreen/)
* [doublepressquit](https://dwm.suckless.org/patches/doublepressquit/)

### Layoyts

* [fibonacci](https://dwm.suckless.org/patches/fibonacci/)
* [horizgrid](https://dwm.suckless.org/patches/horizgrid/)

### Plugins

* [movestack](https://dwm.suckless.org/patches/movestack/)
* [shiftview](https://dwm.suckless.org/patches/nextprev)
