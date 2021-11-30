# push_swap

:books: [Introduction](#introduction)

:bookmark_tabs: [Push_swap example](#push_swap-example)
 
<!--- :world_map: [Concept map](#concept-map)

:collision: [My sorting algorithm](#my-sorting-algorithm)
 
:footprints: [Step by step](#step-by-step) -->

## Introduction
The aim of the Push_swap proyect is to implement a sorting algorithm. At our disposal, we have a set of non-repeating int values, two stacks(A,B) and limited instructions to manipulate 
both stacks:

<table>
  <tr>
    <th>Instruction</th>
    <th>Description</th>
    <th>Image</th>
  </tr>
  <tr>
    <td align=center>sa</td>
    <td>  Swaps the first 2 elements at the top of stack A </td>
    <td rowspan = "3" ><img height="140" align=center src="https://user-images.githubusercontent.com/71781441/144010895-74ea4e2c-8650-49d4-a1e0-42107bf805eb.jpg"></td>
  </tr>
  <tr>
    <td align=center>sb</td>
    <td>  Swaps the first 2 elements at the top of stack B </td>
  </tr>
  <tr>
    <td align=center>ss</td>
    <td>   sa and sb at the same time </td>
  </tr>
  <tr>
    <td align=center>pa</td>
    <td>   Take the first element at the top of B and put it at the top of A </td>
    <td rowspan = "2" ><img height="140" align=center src="https://user-images.githubusercontent.com/71781441/144012628-a9b6c50a-c042-4106-8d4a-980defecb2c2.jpg"></td>
  </tr>
  <tr>
    <td align=center>pb</td>
    <td> Take the first element at the top of A and put it at the top of B </td>
  </tr>
  <tr>
    <td align=center>ra</td>
    <td>  Shift up all elements of stack A by 1 so the first element becomes the last one </td>
    <td rowspan = "3" ><img height="140" align=center src="https://user-images.githubusercontent.com/71781441/144011771-0b1d2ae2-7168-4988-9b71-2f834e549447.jpg"></td>
  </tr>
  <tr>
    <td align=center>rb</td>
    <td>  Shift up all elements of stack B by 1 so the first element becomes the last one </td>
  </tr>
  <tr>
    <td align=center>rr</td>
    <td>  ra and rb at the same time </td>
  </tr>
 <tr>
    <td align=center>rra</td>
    <td>  Shift down all elements of stack A by 1 so the last element becomes the first one </td>
    <td rowspan = "3" ><img height="140" align=center src="https://user-images.githubusercontent.com/71781441/144013923-65b627fb-36c2-4992-8c6a-eb00998e334f.jpg"></td>
  </tr>
  <tr>
    <td align=center>rrb</td>
    <td>  Shift down all elements of stack B by 1 so the last element becomes the first one </td>
  </tr>
  <tr>
    <td align=center>rrr</td>
    <td> rra and rrb at the same time </td>
  </tr>
</table>

<!---
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
-->


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

