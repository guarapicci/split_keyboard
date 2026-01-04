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

## How to use

Install the virtual keyboard application and enable it under KDE Plasma Settings. Touch text fields on your device's touchscreen to trigger the virtual keyboard. Change language or open settings screen by pressing the language change button (usually on the lower left corner)

## Troubleshooting

KWin by default only shows the keyboard when a text field is interacted with by touch. Set `KWIN_IM_SHOW_ALWAYS=1` when starting KWin (or the login session) in order to force the keyboard to always pop up.

