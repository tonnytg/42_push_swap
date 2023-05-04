
# Push Swap

This project exist to sort random numbers MIN_INT at MAX_INT and return sorted values in crescent order.

    ./push_swap 3 1 2       // 1 2 3
    

This project has build with some limitation like you only can modify list of numbers when number are in top of list.

I create a new struct `t_pair` and this type has `value`, `index` and `is_active`

Another students use Linked List to solve this problem but in my opinion it is more fast using array of t_pair,<br/>
something like this:

    [0]                   [1]                       [2]                  -> Array of t_pair
    t_pair {                t_pair {                t_pair {             ----+
        value = 2;              value = 1;              value = 3;           |
        index = 1;              index = 0;              index = 2;           +---> body of t_pair
        is_active = 1;          is_active = 1;          is_active = 1;       |
    }                       }                       }                    ----+


As you can see, I put first element 3 in the top, but this only can possible inverting order of push command when read all elements of argv;<br/>
After input all values in array I need to define index. Index used to decide sort order more easly to evity problems with negative numbers for example using counting sort using bits.

Something I lear:
*Quicksort* -> Use pivot to break array in two peaces (Left and Right) and organize all elements less than pivot in Left and all element grater than pivot in Right.
*Raddixsort* -> It is diferent of Quicksort because didn't use element to compare, use a piece of number to decide what to do, for example, value 135, first order using 5, after 3 and after 1, using unity of value.
*Countingsort* -> Create some array to sort values in correct order, for example order some names "Antonio" "Barbara" "Carlos" "Daniela" you can put names each correspective array of Letter.
*Bucketsort* -> It is same Coutingsort but using bucket to store values in respective order.
