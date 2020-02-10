# LonelyCells
In this game there are cells for each player ( at most 2 players ) and they can move, split, increase their energy of each cell.
The map is a binary file that must be created before running the game.In map file is an int number followed by nxn chars( arranged in row major form).The int number is the length of the map ( equals to width ,since the map is square) and each char shows type of a block in the map.1 is source, 2 is Mitosis ,3 is forbidden and 4 is normal. 
Mistosis which is shown by M in the map. You can split a cell only in Mitosis blocks.
Sources which are shown by E in the map. You can increase a cell's energy only in Sources blocks.Forbidden blocks are shown by - (dash) in the map.Cells can not go to a forbidden block.Normal blocks are shown by 0.You can just go across them.Player 1's cells are shown by X and Player 2's cells are shown by Y.
Each cell can increase its energy to 100.The cells' level must be at least 80 to be able to be splitted.
you can save the game and load it whenever you want.
