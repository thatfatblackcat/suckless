static const float mfact = 0.55;
static char dmenumon[2] = "0";

static const int lockfullscreen = 1;
static const int nmaster = 1;
static const int resizehints = 1;
static const int showbar = 1;
static const int topbar = 1;

static const unsigned int borderpx = 1;
static const unsigned int snap = 32;

static const char *fonts[] = { "monospace:size=10", };
static const char dmenu_fn[] = "monospace:size=10";
static const char dmenu_nb[] = "#222222";
static const char dmenu_nf[] = "#bbbbbb";
static const char dmenu_sf[] = "#eeeeee";
static const char dmenu_sb[] = "#005577";

static const char *colors[][3] = {
	[SchemeNorm] = { dmenu_nf, dmenu_nb, dmenu_nb },
	[SchemeSel] = { dmenu_sf, dmenu_sb, dmenu_sb },
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

static const char *nsxivcmd[] = {
	"sxiv", "-ro",
	"artworks",
	"tatenaga",
	"yokonaga", NULL
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

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag, {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask, KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} }, \
	{ MODKEY, KEY, view, {.ui = 1 << TAG} }, \

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Layout layouts[] = {
	{ "[]=", tile }, { "[M]", monocle },
	{ "><>", NULL }, { "###", horizgrid },
	{ "[]@", spiral }, { "[]L", dwindle },
};

static const Rule rules[] = {
	{ "mpv", NULL, NULL, NULL, 1, -1 },
	{ "krita", NULL, NULL, 1 << 8, 0, -1 },
	{ "Firefox", NULL, NULL, 1 << 8, 0, -1 },
};

static Key keys[] = {
	TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3) TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7) TAGKEYS(XK_9, 8)

	{ 0, XF86XK_AudioMicMute, spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_AudioMute, spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },

	{ 0, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -1000") },
	{ 0, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +1000") },

	{ MODKEY, XK_j, focusstack, {.i = +1 } },
	{ MODKEY, XK_k, focusstack, {.i = -1 } },
	{ MODKEY|ShiftMask, XK_j, movestack, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_k, movestack, {.i = -1 } },

	{ MODKEY, XK_h, setmfact, {.f = -0.05} },
	{ MODKEY, XK_l, setmfact, {.f = +0.05} },
	{ MODKEY|ShiftMask, XK_h, incnmaster, {.i = -1 } },
	{ MODKEY|ShiftMask, XK_l, incnmaster, {.i = +1 } },

	{ MODKEY, XK_f, setlayout, {.v = &layouts[2]} },
	{ MODKEY, XK_r, setlayout, {.v = &layouts[4]} },
	{ MODKEY, XK_t, setlayout, {.v = &layouts[0]} },
	{ MODKEY|ShiftMask, XK_f, setlayout, {.v = &layouts[3]} },
	{ MODKEY|ShiftMask, XK_r, setlayout, {.v = &layouts[5]} },
	{ MODKEY|ShiftMask, XK_t, setlayout, {.v = &layouts[1]} },

	{ MODKEY, XK_comma, focusmon, {.i = -1 } },
	{ MODKEY, XK_period, focusmon, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1 } },
	{ MODKEY|ShiftMask, XK_period, tagmon, {.i = +1 } },

	{ MODKEY, XK_q, killclient, {0} },
	{ MODKEY|ShiftMask, XK_q, quit, {0} },

	{ MODKEY, XK_p, spawn, {.v = dmenucmd } },
	{ MODKEY|ShiftMask, XK_p, spawn, {.v = spawncmd } },

	{ MODKEY, XK_s, spawn, {.v = nsxivcmd } },
	{ MODKEY|ShiftMask, XK_s, spawn, {.v = nsxivcmd } },

	{ MODKEY, XK_0, view, {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0, tag, {.ui = ~0 } },

	{ MODKEY, XK_space, togglebar, {0} },
	{ MODKEY|ShiftMask, XK_space, togglefloating, {0} },

	{ MODKEY, XK_Return, zoom, {0} },
	{ MODKEY|ShiftMask, XK_Return, view, {0} },

	{ MODKEY, XK_Tab, shiftview, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_Tab, shiftview, {.i = -1} },
};

static Button buttons[] = {
	{ ClkClientWin, MODKEY, Button1, movemouse, {0} },
	{ ClkClientWin, MODKEY, Button2, togglefloating, {0} },
	{ ClkClientWin, MODKEY, Button3, resizemouse, {0} },

	{ ClkLtSymbol, 0, Button1, setlayout, {0} },
	{ ClkLtSymbol, 0, Button3, spawn, {.v = spawncmd } },

	{ ClkTagBar, 0, Button1, view, {0} },
	{ ClkTagBar, 0, Button3, toggleview, {0} },

	{ ClkTagBar, MODKEY, Button1, tag, {0} },
	{ ClkTagBar, MODKEY, Button3, toggletag, {0} },
};
