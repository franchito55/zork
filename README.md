# ZORK - Juego de aventura de texto

## Author
- Francisco Barrio

## Repository
https://github.com/franchito55/zork

## License
MIT License

## How to start the game
1. Download and dezip the zork.zip file in the Releases section
2. Run zork.exe

## How to play
### The game is based on text commands. As a tip, always try to type simple commands that might seem like "broken" English. The program will have a better time understanding it!
1. You will get some information about your whereabouts
2. Then, you will decide what to do. Use commands like:
   - `go north` or `go bathroom` for example, to go to other locations
   - `explore` to see the information about the room you're currently in. Use this everywhere you can, as it will tell you extra information!
   - `take key` or `get key` to take an item in the current room and add it to your inventory
   - `use key on school` or `use key on south` to use an item on a location or even on another item (this requires the indirect object to be followed by "on"!)
   - `look key` or `look at office` to see some information about things around you
   - `drop item` to drop an item in your inventory. This will leave it at your location
3. Your objective is to find the property scripture of a school you inherited from your father. However, he died in mysterious circumstances and didn't leave many clues...

## How to win
- Travel to different locations using `go`.
- Use `take` to take some objects (you will NEED some to progress!).
- Use `look` to get information about things.
- You might find some locked doors, so think about how to get past them!.
- Your final objective is to find a scripture. It most likely will be hidden somewhere...

# Some plus stuff
## What I had trouble with
I had 2 main problems while developing this project: 
1. Most importantly and what had the biggest effect was the lack of time, since I didn't choose a good time to do the assignment. 
2. The fact that I hadn't programmed in C or C++ for around 4 years, so I kind of had to relearn everything to do this. But that was fun since I love learning, so not really complaining about it

Some smaller and more precise problems I had (and some that were even left in the final release!) were:
1. How to handle user input. I had to build a sort of structure around verbs and objects to handle what the user wanted to do at every point, which required more thought into it than I originally expected. For instance, you will see items have an underscore (_) separating the words. This is because I wanted to challenge myself to include multi-word tokens , but finally I couldn't figure out in time how to handle them properly, so I ended up just leaving them like that.