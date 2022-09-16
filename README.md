# FlipPancake
C code that Flip pancakes depending on the size of the diameter
-A flip is specified by giving the position of the pancake on the bottom of the sub-stack to be flipped relative to the entire stack.
-The bottom pancake has position 1, while the top pancake on a stack of n pancakes has position n.
-A stack is specified by giving the diameter of each pancake in the stack in the order in which the pancakes appear.

***Input***
-The input consists of a sequence of stacks of pancakes.
-Each stack will consist of between 1 and 10 pancakes and each pancake will have an integer diameter between 1 and 30.
-The input is terminated by end-of-file.
-Each stack is given as a single line of input with the top pancake on a stack appearing first on a line, the bottom pancake appearing last, and all pancakes separated by a space.

***Output***
-For each stack of pancakes, program should echo the original stack on one line, followed by the resulting stack with parenthesis () and a sequence of flips that results in sorting the stack of pancakes so that the largest pancakes is on the bottom and the smallest on top.
-The sequence of flips for each stack should be terminated by a 0, indicating no more flips necessary.
-Once a stack is sorted, no more flips should be made.
