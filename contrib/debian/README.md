
Debian
====================
This directory contains files used to package flopcoind/flopcoin-qt
for Debian-based Linux systems. If you compile flopcoind/flopcoin-qt yourself, there are some useful files here.

## flopcoin: URI support ##


flopcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install flopcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your flopcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitcoin128.png` to `/usr/share/pixmaps`

flopcoin-qt.protocol (KDE)

