# so_long
So Long - SpongeBob Burger Adventure
Description
A 2D game where you help SpongeBob collect Krabby Patties across Bikini Bottom! Built with MiniLibX, this project follows 42's strict coding standards while delivering a fun, interactive gaming experience.

Project Requirements
Language: C (Norm-compliant)

Graphics: MiniLibX library

Input: .ber map files

Memory: No leaks, no crashes

Makefile: With all standard rules

Game Elements
🧽 P - SpongeBob (player start)

🍔 C - Krabby Patties (collectibles)

   E - (exit)

   1 - Walls/obstacles

   0 - Walkable paths

Controls
W/A/S/D or ↑/←/↓/→ - Movement

ESC - Quit game

Window X - Close cleanly

Map Validation
Must be rectangular and wall-enclosed

Exactly one player (P), one exit (E)

At least one collectible (C)

Valid path to complete level

Compilation
bash
make        # Compile project
make clean  # Remove object files
make fclean # Remove objects and binary
make re     # Recompile
Usage
bash
./so_long maps/bikini_bottom.ber
Features
Move counter displayed in shell

Collision detection with walls

Collectible tracking system

Clean error handling with "Error" messages

Smooth window management

Memory leak free

Example Map
text
111111
1P00C1
1010E1
111111
This project demonstrates 2D game development, graphics programming, and robust C programming while maintaining 42's strict quality standards.
