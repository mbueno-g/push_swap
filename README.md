# push_swap

:books: [Introduction](#introduction)

:bookmark_tabs: [Push_swap example](#push_swap-example)
 
<!--- :world_map: [Concept map](#concept-map)

:collision: [My sorting algorithm](#my-sorting-algorithm)
 
:footprints: [Step by step](#step-by-step) -->

## Introduction
The aim of the Push_swap proyect is to implement a sorting algorithm. At our disposal, we have a set of non-repeating int values, two stacks(a,b) and limited instructions to manipulate 
both stacks:

<!--
<table>
  <tr>
    <th>Instruction</th>
    <th>Description</th>
    <th>Image</th>
  </tr>
  <tr style="text-aling:center">
    <td style="color:red">sa</td>
    <td>  Swaps the first 2 elements at the top of stack ``a`` </td>
    <td rowspan = "3" ><img height="30" src="https://github.com/mbueno-g/42MadridCursus/blob/main/img/c.jpg?raw=true"> <img height="15" src="https://github.com/mbueno-g/42MadridCursus/blob/main/img/makefiles.png?raw=true"></td>
  </tr>
  <tr>
    <td>sb</td>
    <td>  Swaps the first 2 elements at the top of stack ``b`` </td>
    <td><img height="30" src="https://github.com/mbueno-g/42MadridCursus/blob/main/img/c.jpg?raw=true"></td>
  </tr>
</table>

 ![Concept Map - Frame 1 (2)](https://user-images.githubusercontent.com/71781441/143954254-d0f7fc1b-117f-4e44-ba84-4cb3275e6212.jpg)
-->


| Instruction | Description |
| :---------: | :---------: | 
| ``sa`` | Swaps the first 2 elements at the top of stack ``a`` |
| ``sb`` | Swaps the first 2 elements at the top of stack ``b`` |
| ``ss`` | ``sa`` and ``sb`` at the same time |
| ``pa`` | Take the first element at the top of ``b`` and put it at the top of ``a`` |
| ``pb`` |  Take the first element at the top of ``a`` and put it at the top of ``b`` |
| ``ra`` | Shift up all elements of stack ``a`` by 1 so the first element becomes the last one |
| ``rb`` | Shift up all elements of stack ``b`` by 1 so the first element becomes the last one |
| ``rr`` | ``ra`` and ``rb`` at the same time |
| ``rra`` | Shift down all elements of stack ``a`` by 1 so the last element becomes the first one |
| ``rrb`` | Shift down all elements of stack ``b`` by 1 so the last element becomes the first one |
| ``rrr`` | ``rra`` and ``rrb`` at the same time |



## Push_swap example
Here there's an example to illustrate the effect of these instructions. The numbers to be sorted can be given to the push_swap executable as arguments in two ways: as a set
of numbers (``./push_swap 2 1 3 6 5 8 ``) or as a string of numbers separated by a space (``./push_swap "2 1 3 6 5 8"``).
```
$> ./push_swap 2 1 3 6 5 8
 
 Init a and b   Exec sa     Exec pb pb pb     Exec rr      Exec rrr       Exec sa      Exec pa pa pa
 
 2                1                                                                       1
 1                2                                                                       2
 3                3                                                                       3
 6                6            6   3           5    2        6    3        5     3        5
 5                5            5   2           8    1        5    2        6     2        6
 8                8            8   1           6    3        8    1        8     1        8
---  ---         ---  ---     ---  ---        ---  ---      ---  ---      ---   ---      ---  ---
 a    b           a    b       a    b          a    b        a    b        a     b        a    b
Number of instructions : 10
```
The output of this program is the set of instructions needed to sort in ascending order numbers into stack a:
```
$> ./push_swap 2 1 3 6 5 8
 sa
 pb
 pb
 pb
 rr
 rrr
 sa
 pa
 pa
 pa
```

