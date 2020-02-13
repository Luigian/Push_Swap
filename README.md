<img src="resources/images/ps_banner.png" width="1200">

# Push_Swap - 42 School Project 

## Highlights

* This project was about sorting an array of integers using 11 given operations. Each operation is considered as a move, and the idea is to sort the array in the less amount of moves.

* The 11 allowed operations are: sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa and pb.

* To perform these operations i have two stacks, the first one known as "A" will contain the to-sort array, and the second known as "B" will be an empty stack in wich i was able to push elements from "A" as part of the sorting process.

<img src="resources/images/ps_operations.png" width="1000">

## My approach for arrays with less than 6 elements

The idea is to create a trie in wich every possible secuence of operations can be executed. This way i'll be sure that i was finding the shortest solution. But the problem was that i was using a lot of memory to perform all the calculations. Even for sorting arrays of 4 elements it was taking a lot of time. So i needed to optimize this method doing the following:

a) Reducing the number of operations from 11 to 8 by checking ss, rr and rrr in a second phase. In that second phase every time i find  a pair of sa-sb or sb-sa i can replace it for ss; the same for rr (ra-rb or rb-ra) and rrr (rra-rrb or rrb-rra).

b) Preventing branches with non-applicable operations (ex: sb, rb, rrb or pa at the beginning).

c) Interrupting some branches from keep growing if the array in it become more unsorted, or don't show a minimum of progress.

<img src="resources/images/ps_trie.png" width="1000">

The trie is executed level by level and every operation is checked, if at any given point the stack "A" is sorted and the stack "B" is empty, the trie stops, and the according secuence of operations that leaded into this leaf is printed as the solution.
 
 ## The algorithm for arrays with 100 or 500 elements
 
The first step is to copy, from the smaller to the bigger, all the elements of the stack "A" into a new array. We will refer to this array as "guide", it contains a sorted copy of "A".

<img src="resources/images/ps_stacka.png" width="1000"> 
<img src="resources/images/ps_guide.png" width="1000">

This will allow to divide in groups the stack "A" by using the indexes of "guide". In the case of a 100 elements array, there will be 5 groups of 20 elements each.

<img src="resources/images/ps_indexes.png" width="1000">

A visual representation of the position of every element of every group looks like this:

<img src="resources/images/ps_groups.png" width="1000">
 
The second step is to move all the elements of the first group from the stack "A" to the stack "B". This is done by moving every time the element wich is the closest to the top of the stack. In other words, the one that needs the less amount of "shifting up" or "shifting down" (ra or rra).

<img src="resources/images/ps_closest.png" width="1000">

Once the closest is localized and moved to the top of "A", the stack "B" need to be 'prepared' to receive the new element. This will shift up or down the stack "B" (rb or rrb) in order to insert the new element in the correct place. So "B" will always stay sorted from the smaller to the bigger.

<img src="resources/images/ps_moveb.png" width="1000">

After moving all the elements of the first group, then it is the turn for the second group, an so on.
Finally, once the stack "A" is empty, the third step is to move back all the elements from stack "B" to stack "A".

In the case of a stack of 500 elements, there will be 11 groups of 45 elements each.

## Process Logbook

As they say: "The key to a successful ft_printf is a well-structured and good extensible code", so i try to give me the time to understand how the true printf worked to be prepared for the battle and this is the summary of what I did:

* Read the pdf.
* Read about variadic functions on internet.
* Read the man: `man 3 stdarg` `man printf` `man 3 printf`.
* Learn about format conversion specifications for printf.
* Learn more about data types.
* Learn about integers lengths: `char`, `short`, `long`, `long long`, `nan`.
* Learn about floats: single precision, double precision and extended precision. 
* I made the next table to visualize the last two points:
<img src="resources/images/pf_lengths_table.png" width="1000">

* I made the following table to help me see, by testing the real printf, how the different types worked with the different combinations of format specifications.
<img src="resources/images/pf_fmtspecs_table_1.png" width="1000">

* An extension of the previous table with a more concise display was very practical while coding.
<img src="resources/images/pf_fmtspecs_table_2.png" width="700">

After this, i started to write the code in the following order:

* Storing the format specifications (flags, width, precision, length) in variables of a structure.
* The functions to print d, i and u.
* Then the functions to print o, x, X and p.
* Then the functions to print c, s.
* The most difficult one for me, the function to print f.
* Then i worked on big numbers (negatives and positives), zero and null cases.
* After that, i started with bonuses: \*, j, z, U, e, g, $, ', b and k.

## Installation
`make` | Compiles and creates two programs: `push_swap` and `checker`.

## Usage
`./push_swap [integers array]` | Prints the solution.

`./checker [integers array]` | Reads the solution from the standard input, and prints "OK" or "KO".

The `integers array` can be:
- Multiple ints as arguments (3 2 1 0).
- One single char string argument ("3 2 1 0").
- A combination of both (3 "2 1" 0).

## Optional flags
`./push_swap -w [integers array]` | Prints the solution in a file.

`./checker -r [integers array]` | Reads the solution from a file.

`./checker -v [integers array]` | Reads the solution from the standard input and display, at every time, a visual representation of the stacks current status.

## push_swap Input & Output
<img src="resources/images/ps_input_01.png" width="200">
<img src="resources/images/ps_output_01.png" width="200">

## checker Input & Output
<img src="resources/images/ps_input_02.png" width="200">
<img src="resources/images/ps_output_02.png" width="350">

## Credits
[*Luis Sanchez*][linkedin] 2019, [42 Silicon Valley][42].

[linkedin]: https://www.linkedin.com/in/luis-sanchez-13bb3b189/
[42]: http://42.us.org "42 USA"
