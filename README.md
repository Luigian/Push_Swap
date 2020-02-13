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
 
 
 
 
 
 
 
 
 
 
 
 
 
 

`%[argument][flag][width][precision][length]type`
  
## Functions Hierarchy
<img src="resources/images/pf_funhierarchy.png" width="1000">

## Handled Specifiers and Types

|Specifier|Group|Description|
|---------|-----|-----------|
|n`$`|argument|Decimal digit string followed by a $, specifying the next argument to access.|
|`#`|flag|Known as the 'alternate form', may add '0' for o, '0x' for x and '0X' for X. For f always print the decimal point.|
|`0`|flag|The value is padded on the left with zeros rather than blanks when the 'width' option is specified.|
|`-`|flag|The converted value is to be left adjusted on the field boundary.|
|` ` (space)|flag|A blank should be left before a positive number produced by a signed conversion.|
|`+`|flag|A sign must always be placed before a number produced by a signed conversion.|
|`'`|flag|Decimal and floating point conversion should be grouped and separated by thousands.|
|n|width| Decimal digit string specifying a minimum field width.|
|`.`n|precision|A period '.' followed by a digit string gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the decimal point for f, or the maximum number of characters to be printed from a string for s conversions.|
|`*`|width / precision|A field width or precision, or both, may be indicated by an asterisk or an asterisk followed by one or more decimal digits and a $ instead of a digit string. In this case, an int argument supplies the field width or precision.|
|`hh`|length|Specifies the size of the argument as 'signed char' or 'unsigned char'.|
|`h`|length|Specifies the size of the argument as 'short' or 'unsigned short'.|
|`l`|length|Specifies the size of the argument as 'long' or 'unsigned long'.|
|`ll`|length|Specifies the size of the argument as 'long long' or 'unsigned long long'.|
|`j`|length|Specifies the size of the argument as 'intmax_t' or 'uintmax_t'.|
|`z`|length|Specifies the size of the argument as 'size_t'.|
|`L`|length|Specifies the size of the argument as 'long double'.|

|Type|Description|
|----|-----------|
|`c`|The int argument is converted to an unsigned char.|
|`s`|The argument is expected to be a pointer to an array of character type.|
|`p`|The void * pointer argument is printed in hexadecimal.|
|`d`,`i`|The argument is converted to signed decimal.|
|`o`|The argument is converted to unsigned octal.|
|`u`|The argument is converted to unsigned decimal.|
|`U`|The 'long int' argument is converted to unsigned decimal.|
|`x`|The argument is converted to unsigned hexadecimal in lowercase.|
|`X`|The argument is converted to unsigned hexadecimal in uppercase.|
|`f`|The double argument is rounded and converted to decimal notation in the style `[-]ddd.ddd`.|
|`e`|The double argument is rounded and converted in the style `[-]d.ddde+-dd`.|
|`g`|The double argument is converted in style f or e. Style e is used if the exponent from its conversion is less than -4 or greater than or equal to the precision.|
|`%`|A '%' is written.  No argument is converted. The complete conversion specification is `%%`.|
|`b`|The argument is printed in binary.|
|`k`|The int argument is converted to timestamp.|

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
`make && make clean` | Compiles and creates the library `libftprintf.a`.

`make re && make clean` | Recompiles.

## Usage
`gcc resources/test/test_main.c libftprintf.a && ./a.out` | Prints the test main provided as example. 

## Input & Output
<img src="resources/images/pf_input.png" width="300">
<img src="resources/images/pf_output.png" width="300">

## Credits
[*Luis Sanchez*](https://www.linkedin.com/in/luis-sanchez-13bb3b189/)
2019. Freemont, CA

## About 42 School
[42][42] is a free, non profit, project-based, peer-to-peer learning coding school. It originated in France and now has over 20 campuses all over the world. More information can be found [here][42]

[42]: http://42.us.org "42 USA"
[pdf]:  "Pdf"
