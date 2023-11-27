<center>
    <p  align="center">
    <h1 id="begin">
        TypeGame
    </h1>
    A console mini-game to practice typing speed and precission
    </p>
</center>

<br>
<details>
    <summary>Table of contents</summary>

1. [Introduction](#introduction)
2. [Idea](#idea)
3. [Instalation and usage](#instalation-and-usage)
4. [Development](#development)

</details>
<br>

# Introduction
I was looking for a not-college-related project to improve my C++ programming skills and have some fun. Typing is something that I really enjoy, so why not making a game about it? 

This document does not pretend to act as a serious report about the project; its goal is to describe the process I follow to develop this game. That is, describe the problems I encouter and how I solve them, and document what I learned.

<p  align="right">
    [(back to top)](#begin)
</p>

# Idea
This projects aims to implement a basic typing game to help improving your speed and precission. 

The program will show a text which user must copy right beneath. If you type the next character correctly it will be green, but it will be red otherwise. 

It is inspired on [monkeytype](https://www.monkeytype.com). Though it will not be so ambitious.

[<div style="text-align: right">(back to top)</div>](#begin)

# Instalation and usage 
Currently there is no usable version of the project.

[<div style="text-align: right">(back to top)</div>](#begin)

# Development
In this section it will be documented the different steps I followed to implement this game, from the functionality specification to the final project. In addition, I will journal the actual developing process.

[<div style="text-align: right">(back to top)</div>](#begin)

## Functionality specification
In this section every feature that will be implemented in the game is presented. 

- Options: the program must start showing different options associated with key combinations such as ctrl + c, ctrl + q, etc. The options will be: 
    - New text: starts a new game
    - Close/stop: stops de the program
- keyboard input: the program must read keyboard input splitted into char.
- show text: texts will be stored as txt files on a directory. The program must be able to read one and show it to the user in the correct format. 
- correct/incorrect feedback: each typed letter must turn red when the user type that one letter incorrectly. It will turn green otherwise. 
- Stadistics: at the end of one game (i.e. typing one text completely), some stadistics will be presented to the user: 
    - time typing (seconds): how long it taked to the user to complete the game.
    - WPM: (n_chars / 5)*60/time_typing.
    - Accuracy: (correctly_sppelled - incorrectly_sppeled)/key_strockes.
- loop: every time the user finishes a text, they must be able to start anotherone using the apropiate key combination. 

[<div style="text-align: right">(back to top)</div>](#begin)

## Class interface
- Game: one game. 
    - Attributes:
        - text: text the user has to copy. Represented as an array of char. 
        - nextChar: next character the user must type
        - buff: stores the user input
        - timestamp_start: when the user starts typing.
        - timestamp_stop: when the user types the last character. 
        - c_correct: number of correct-typed characters
        - c_failed: number of incorrect-typed characters
    - Methods: 
        - Game(path): constructor
        - Start(): initialize game - timestamp_start, takes input
        - Stop(): initialize stops
        - time(): returns the time it takes to complete the test
        - accuracy(): returns the accuracy
        - wpm(): return WPM

[<div style="text-align: right">(back to top)</div>](#begin)

## Journey

### First version
In order to start with something simple that I could program in a couple of afternoons, I decided to start developing a much more simple version:

Lets try to make a program which validates if a text is correctly copy or not and calculates accuracy and wpm. 

So, what are we **not** implementing?
- real time validation
- colors in the characters

Having said that, there is just one question left about the simplified TypeGame:
> *What do we need?*
> - Time measurement
> - Keyboard input
> - count correct an incorrect characters after an input. 
> - a way to indicate when whe have finished to write
> - playable loop

[<div style="text-align: right">(back to top)</div>](#begin)

#### Time measurement
It must be clear that, since I need to measure the time the user takes to make an input, I must take into account *ellapsed time* (i.e. the between the start of the game and the end of it, counting detention time caused by I/O processes). Therefore, I've chosen `<chrono>` to take this measurement because it offers this exact functionality. You can check more about this library in its documentation [here](https://cplusplus.com/reference/chrono/).

The idea is pretty simple: 

1. Create a time stamp just before allowing the user to introduce an input
2. Create another time stamp just after the user indicates they have finished
3. The difference between these two values is the time the user taked to do the test

Using *chrono*, there are 2 functions needed: 
```cpp
#include <chrono>
std::chrono::steady_clock::time_point time_stamp = std::chrono::steady_clock::now(); // creates a time stamp with the current time
std::chrono::duration_cast<std::chrono::milliseconds>(timestampB - timestampA).count() // calculates the difference between time stamps and transform it in the unit the programmer have indicated. 
```
[<div style="text-align: right">(back to top)</div>](#begin)

#### Keyboard input
The unique problem I encounter implementing this is that spaces normaly are used to split the input. Since I need to keep the spaces as inputs, the soliution is to use `std::getline(stream, buffer)` to read the complete line instead of stopping on the first space. 

[<div style="text-align: right">(back to top)</div>](#begin)

#### Count correct an incorrect characters after an input
This function is prety simple, there are 3 possibilities: 
- Input is shorter that the text: compare every character of the input with its counterpart. After that, add to c_failed the absolute difference between input and text sizes.
- Input hast the same size that text: compare every character in input to its counterpart in text. 
- Input has more characters than text: compare every character of the text with its counterpart in the input. Then, add to c_failed the absolute difference between input and text sizes. 

Generalize this function is pretty simple: 

```cpp
for (int i = 0; i < std::min(text.lenght(), input.lenght()); ++i) {
    if (text[i] == input[i]) ++c_correct;
    else ++c_failed;
}
c_failed += std::abs(c_correct - c_failed);
```

Now we have time and number of correctly and incorrectly spelled characters, so we have enough to calculate the stadistics specified above. 

[<div style="text-align: right">(back to top)</div>](#begin)

#### When does the game finish?
Since we are going to use `std::getline()` function, the user must press `enter` when finished. 

[<div style="text-align: right">(back to top)</div>](#begin)
