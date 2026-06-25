*This project has been created as part of the 42 curriculum by aimalasi.*

**Push_swap**

# Description

Push_swap is a sorting alorithm project. The goal is to sort a stack of integers using two stacks - A and B - and a limited set of operations, printing the shortest possible sequence of instructions to achieve sorted stack A.

The program receives a list of integers as arguments, loads them into stack A, and outputs the operations needed to sort them in ascending order. For small inputs (<= 5 elements) a hardcoded optimal strategy is used. For larger inputs, values are first normalized to their rank (0 to n-1) and then sorted using radix sort, processing one bit at a time.

**Available Operations**

| Operation | Description |
|-----------|----------------|
|sa| Swap the top two elements of stack A|
|sb| Swap the top two elements of stack B|
|ss| sa and sb simultaneously |
|pa| Push top of B onto A |
|pb| Push top of A onto B |
|ra| Rotate A upward (top->bottom) |
|rb| Rotate B upward |
|rr| ra and rb simultaneously |
|rra| Reverse rotate A (bottom->top) |
|rrb| Reverse rotate B |
|rrr| rra and rrb simultaneously |

**Project Structure**
| File | Use |
|-----------|------------|
| push_swap.h | # Structs and prototypes |
| push_swap.c | # main |
| operations.c | # push, swap, rotate, reverse_rotate |
| radix.c | # order, normalize, radix_sort |
| small_sort.c| #sort_three, sort_five |
| utils1.c | #sort_two, init_stack, free_stack, error_exit, is_valid_int |
| utils2.c | #has_duplicates, is_sorted, free_split, ft_strncpy |
| utils3.c | #count_words, get_word, split_string, load_stack |
| Makefile |

# Instructions

Arguments can be passed as separate values or as a single quoted string:

./push_swap 5 3 1 4 2

./push_swap "5 3 1 4 2"

To count the number of operations:

./push.swap 5 3 1 4 2 | wc -l

To verify correctness using the checker:

ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker $ARG

**Input Validation**

The program prints Error and exits on:

- Non-integer arguments
- Values outside the int range
- Duplicate values
- Empty or whitespaces-only input

If the input is already sorted, nothing is printed.

# Resources

- [PushSwapVisualiser](https://github.com/o-reo/push_swap_visualizer)
- [EducationalVideoOnPush](https://www.youtube.com/watch?v=OaG81sDEpVk&t=337s)
- [RadixWikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [VideoOnLinkedLists](https://www.youtube.com/watch?v=mkZYMKwKkvI)
- AI tools were used in understanding algorithm concepts, debugging support and understanding radix sort and its binary logic.
