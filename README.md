# Lem_in
The purpose of this project is to find paths from start room to end room and to move ants by these paths with the least amount of steps.

## Getting Started

This project has only been compiled and tested on macOS. A few modifications might be necessary to compile it on any other system.

### Installing

```
git clone https://github.com/fica99/Lem_in.git
cd Lem_in
make
```
to compile. An executable named ./lem-in should be created.

### How to use

Lem-in takes commands from stdin. Tests and sample maps can be found in the tests folder.

```
Usage: ./lem-in < test_map
```

### Map format (input)

A map is made of ***rooms*** and ***tubes***. ***Rooms*** are linked by ***tubes***. All distances are equal to 1.

The first line of a map must be the number of ants that will run through the map.

```
42
```

Any other line must be either a ***room descriptor***, a ***tube descriptor***, a ***command***, or a ***comment***.

#### Room

A ***room descriptor*** is a line with 3 fields separated by a space **' '**. The first field is the **room name**. Any name is legal, as long as it contains no space and doesn't start with **'L'**. The two other fields represents the coordinates of this room in a 2D environment. Those coordinates are completely ignored by the lem-in executable, but will be printed back on the output for more processing.

```
room_name x y
```

#### Tube

A ***tube descriptor*** is a line with 2 fields separated by a dash **'-'**. Each field must be the name of a valid room.

```
room_1-room_2
```

#### Command

Any line that starts with two **'#'** is a  ***command***. lem-in only interprets two commands: **'##start'** and **'##end'**. A map without one of those commands will result in an error. They must be located before a valid ***room descriptor***. Any other command will be ignored and printed back on the output for more processing.

```
##start
room_1 0 0
```

#### Comment

Any line that starts with one **'#'** is a  ***comment***. Any comment will be ignored and printed back on the output.

```
#comment
```

### Result (output)

First, the map is fully printed back.

Then, the result will contain as many lines as there is cycles. Each cycles contains *n* movements, which are formated as shown below:

```
Lant_id-room_name
```

## Visualization

### Instalation requirements

```
python3 -m venv env
. env/bin/activate
pip3 install -r requirements.txt
```

### Usage
```
./lem-in < test_map | python3 visualization.py
```

![Visualization Lem-in](https://i.ibb.co/w4dQYMk/Screen-Shot-2020-10-11-at-2-50-10-PM.png)
