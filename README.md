# Ft\_select2 [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b6363ce6cf4a418887bb63736a5eccb8)](https://www.codacy.com/manual/antoinepaulbarthelemy/Ft_select2?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Ant0wan/Ft_select2&amp;utm_campaign=Badge_Grade) [![Build Status](https://travis-ci.org/Ant0wan/Ft_select2.svg?branch=master)](https://travis-ci.org/Ant0wan/Ft_select2)

An implementation of an **in-shell file dialog** using termcaps [a 42 project].

This project aims to learn the very basics of using termcap library in C programming language.
Ft\_select2 is an argument viewer in the terminal that returns the user selection on the standard output.

<img src="https://i.imgur.com/BHfhj0n.gif" alt="demo" width="800" height="500">


## Description

*Ft_select2* is the newer version of [Ft\_select](https://github.com/Ant0wan/Ft_select). It displays a list of arguments in the running terminal. Pressing arrow keys on the keyboard will move the cursor through the list of arguments passed to ft\_select.

Ft\_select2 has 3 different modes:

	1. Selection mode (default mode)

	2. Command mode by pressing <:> from selection mode

	3. Search mode by pressing <\/> from selection mode

Pressing \<ESC\> in Command or Search mode will put the user back to Selection mode.

Authorized functions:

```shell=
isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag
tgetnum, tgetstr, tgoto, tputs, open, close, write, malloc, free, read, exit, signal
```

#### Selection mode

- 'Arrow keys' will move the cursor through the circular list. The cursor underlines the file - appears as an underline font.

- 'space' key will select/un-select one or more choices in the displayed list. A selection positions the cursor on the next element in the list if it exists. A selected file appears overlined.

- 'return' key validates the selection. It displays the selection to the standard output. Other programs can take the output.

- 'delete' and 'backspace' keys removes an element from the list.

- 'ESC' key exists the program.


#### Command mode

The command mode is used to change the list sort.

- 'Arrow keys' left or right will change the sort mode.

- 'ESC' or 'ENTER' key to go back to Selection mode.


#### Search mode

The search mode helps user to find a file among the many that have been selected.

To find an argument, just type its name and press \<ENTER\>.

The program will select the found argument of display an error message.

- 'ESC' to cancel search and go back to Selection mode.

- 'ENTER' to confirm search and go back to Selection mode.




## Requirements

- Termcap library:

```shell=
sudo apt-get -y install libncurses-dev
```



## Usage

- Clone the github repository

```shell=
git clone --recurse-submodules https://github.com/Ant0wan/Ft_select2.git && cd Ft_select2/ && make -j
```

- Build

```shell=
cd Ft_select2 && make -j
```

- Run, format ./ft_select + arguments

```shell=
./ft_select ARG|...
```
For instance:

```shell=
./ft_select Makefile README.md author ft_select ft_select.en.pdf libft src
```



## Demo

[![asciicast](https://asciinema.org/a/i5FeTPOeLOQTTl8q3t1tkEg1Y.svg)](https://asciinema.org/a/i5FeTPOeLOQTTl8q3t1tkEg1Y)
