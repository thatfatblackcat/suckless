static const int lockfullscreen = 1;
static const int nmaster = 1;
static const int resizehints = 1;
static const int showbar = 1;
static const int topbar = 1;

static const unsigned int borderpx = 1;
static const unsigned int snap = 32;

static const float mfact = 0.55;
static char dmenumon[2] = "0";

static const char dmenu_nb[] = "#222222";
static const char dmenu_nf[] = "#bbbbbb";
static const char dmenu_sf[] = "#eeeeee";
static const char dmenu_sb[] = "#005577";

static const char dmenu_fn[] = "monospace:size=10";
static const char *fonts[] = { "monospace:size=10", };

static const char *colors[][3] = {
	[SchemeNorm] = { dmenu_nf, dmenu_nb, dmenu_nb },
	[SchemeSel] = { dmenu_sf, dmenu_sb, dmenu_sb },
};

static const char *xdpmscmd[] = {
	"xset", "dpms", "force", "off", NULL
};

static const char *spawncmd[] = { "alacritty", NULL };
static const char *dmenucmd[] = {
	"dmenu_run", "-m", dmenumon,
	"-fn", dmenu_fn,
	"-nb", dmenu_nb,
	"-nf", dmenu_nf,
	"-sb", dmenu_sb,
	"-sf", dmenu_sf, NULL
};

static const char *tags[] = {
	"1", "2", "3",
	"4", "5", "6",
	"7", "8", "9",
};

#include <X11/XF86keysym.h>
#include "../layout/fibonacci.c"
#include "../layout/horizgrid.c"
#include "../plugin/movestack.c"
#include "../plugin/shiftview.c"

#define COMMAND(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define TAGKEYS(KEY,TAG) \
	{ Mod1Mask|ShiftMask, KEY, tag, {.ui = 1 << TAG} }, \
	{ Mod1Mask|ControlMask, KEY, toggleview, {.ui = 1 << TAG} }, \
	{ Mod1Mask|ControlMask|ShiftMask, KEY, toggletag, {.ui = 1 << TAG} }, \
	{ Mod1Mask, KEY, view, {.ui = 1 << TAG} }, \

static const Layout layouts[] = {
	{ "[]=", tile }, { "[M]", monocle },
	{ "><>", NULL }, { "###", horizgrid },
	{ "[]@", spiral }, { "[]L", dwindle },
};

static const Rule rules[] = {
	{ "mpv", NULL, NULL, 0, 1, -1 },
	{ "krita", NULL, NULL, 1 << 8, 0, -1 },
	{ "Firefox", NULL, NULL, 1 << 8, 0, -1 },
};

static Key keys[] = {
	TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3) TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7) TAGKEYS(XK_9, 8)

	{ Mod1Mask, XK_comma, focusmon, {.i = -1 } },
	{ Mod1Mask|ShiftMask, XK_comma, tagmon, {.i = -1 } },
	{ Mod1Mask, XK_period, focusmon, {.i = +1 } },
	{ Mod1Mask|ShiftMask, XK_period, tagmon, {.i = +1 } },

	{ Mod1Mask, XK_Tab, shiftview, {.i = +1 } },
	{ Mod1Mask|ShiftMask, XK_Tab, shiftview, {.i = -1} },
	{ Mod1Mask, XK_Return, zoom, {0} },
	{ Mod1Mask|ShiftMask, XK_Return, view, {0} },
	{ Mod1Mask, XK_space, setlayout, {0} },
	{ Mod1Mask|ShiftMask, XK_space, togglefloating, {0} },

	{ Mod1Mask, XK_h, setmfact, {.f = -0.05} },
	{ Mod1Mask|ShiftMask, XK_h, incnmaster, {.i = -1 } },
	{ Mod1Mask, XK_j, focusstack, {.i = +1 } },
	{ Mod1Mask|ShiftMask, XK_j, movestack, {.i = +1 } },
	{ Mod1Mask, XK_k, focusstack, {.i = -1 } },
	{ Mod1Mask|ShiftMask, XK_k, movestack, {.i = -1 } },
	{ Mod1Mask, XK_l, setmfact, {.f = +0.05} },
	{ Mod1Mask|ShiftMask, XK_l, incnmaster, {.i = +1 } },

	{ Mod1Mask, XK_t, setlayout, {.v = &layouts[0]} },
	{ Mod1Mask|ShiftMask, XK_t, setlayout, {.v = &layouts[1]} },
	{ Mod1Mask, XK_f, setlayout, {.v = &layouts[2]} },
	{ Mod1Mask|ShiftMask, XK_f, setlayout, {.v = &layouts[3]} },
	{ Mod1Mask, XK_r, setlayout, {.v = &layouts[4]} },
	{ Mod1Mask|ShiftMask, XK_r, setlayout, {.v = &layouts[5]} },

	{ Mod1Mask, XK_p, spawn, {.v = dmenucmd } },
	{ Mod1Mask|ShiftMask, XK_p, spawn, {.v = spawncmd } },

	{ Mod1Mask, XK_q, killclient, {0} },
	{ Mod1Mask|ShiftMask, XK_q, quit, {0} },

	{ Mod1Mask, XK_0, view, {.ui = ~0 } },
	{ Mod1Mask|ShiftMask, XK_0, tag, {.ui = ~0 } },

	{ Mod1Mask, XK_b, togglebar, {0} },
	{ Mod1Mask|ShiftMask, XK_b, spawn, {.v = xdpmscmd } },

	{ Mod1Mask, XK_s, spawn, COMMAND("sxiv -ro tatenaga/ yokonaga/") },
	{ Mod1Mask|ShiftMask, XK_s, spawn, COMMAND("sudo timeshift-gtk") },

	{ 0, XF86XK_AudioMicMute, spawn, COMMAND("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_AudioMute, spawn, COMMAND("pactl set-sink-mute @DEFAULT_SINK@ toggle") },
	{ 0, XF86XK_AudioRaiseVolume, spawn, COMMAND("pactl set-sink-volume @DEFAULT_SINK@ +1000") },
	{ 0, XF86XK_AudioLowerVolume, spawn, COMMAND("pactl set-sink-volume @DEFAULT_SINK@ -1000") },
};

static Button buttons[] = {
	{ ClkLtSymbol, 0, Button1, setlayout, {0} },
	{ ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]} },

	{ ClkWinTitle, 0, Button2, zoom, {0} },
	{ ClkStatusText, 0, Button2, spawn, {.v = spawncmd } },

	{ ClkClientWin, Mod1Mask, Button1, movemouse, {0} },
	{ ClkClientWin, Mod1Mask, Button2, togglefloating, {0} },
	{ ClkClientWin, Mod1Mask, Button3, resizemouse, {0} },

	{ ClkTagBar, 0, Button1, view, {0} },
	{ ClkTagBar, 0, Button3, toggleview, {0} },
	{ ClkTagBar, Mod1Mask, Button1, tag, {0} },
	{ ClkTagBar, Mod1Mask, Button3, toggletag, {0} },
};
