# Pomodoro Timer

This is a simple Pomodoro timer written in C++. It helps you manage your time by breaking work into intervals, traditionally 25 minutes in length, separated by short breaks.

## Dependencies

To use the program, I needed a way to print text to the screen so I used figlet.<br> And for playing audio from the terminal I used mpv. 

### Debian-based

```sh
sudo apt-get install figlet mpv
```

### Arch-based

```sh
sudo pacman -S figlet mpv
```

### Fedora

```sh
sudo dnf install figlet mpv
```

## Usage

```sh
git clone https://github.com/nanda-gopal-sb/comodoro
cd comodoro
gcc src/main.c # you could also use clang
./a.out
```
