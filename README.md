<!--
  - SPDX-FileCopyrightText: None
  - SPDX-License-Identifier: CC0-1.0
-->

# Plasma Keyboard with split layout

This is an unnoficial fork of [Plasma Keyboard](https://invent.kde.org/plasma/plasma-keyboard) that adds split keyboard layouts to some of the languages.
Currently only the EN-US and PT-BR locales have split versions; more of them can be patched in later by modding the QML from the folders under "src/layouts".


## Install from release

Use flatpak to install the bundles from the "release" section of this repository. There is no "native" package for this fork.

## Build from source

```sh
mkdir build && cd build
cmake ..
make && make install
```


## Layouts

The keyboard layouts are located in the [src/layouts](/src/layouts) folder.

They are forked from Qt's [layouts](https://github.com/qt/qtvirtualkeyboard/tree/dev/src/layouts), with modifications that we want for Plasma. Please view the official [Qt documentation](https://doc.qt.io/qt-6/qtvirtualkeyboard-overview.html#adding-new-keyboard-layouts) for a guide on how to create and modify keyboard layouts.

To use Qt's built-in keyboard layouts rather than the ones we supply in `plasma-keyboard`, set `PLASMA_KEYBOARD_USE_QT_LAYOUTS=1` when starting KWin (or the login session).

## Troubleshooting

KWin by default only shows the keyboard when a text field is interacted with by touch. Set `KWIN_IM_SHOW_ALWAYS=1` when starting KWin (or the login session) in order to force the keyboard to always pop up.

