package main

import (
	"fmt"
)

func main() {

	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i < 5; i++ {
		for j := 0; j <= i; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 1; i <= 5; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", j)
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 1; i <= 5; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", i)
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 5; i >= 1; i-- {
		for j := 1; j <= i; j++ {
			fmt.Printf("*")
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 5; i >= 1; i-- {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", j)
		}
		fmt.Println()
	}
	fmt.Println()
	odds := 1
	for i := 1; i <= 5; i++ {
		//spaces
		for j := 1; j <= 5-i; j++ {
			fmt.Printf(" ")
		}
		//stars
		for j := 1; j <= odds; j++ {
			fmt.Printf("*")
		}
		odds += 2
		fmt.Println()
	}
	fmt.Println()
	odds = 9
	for i := 1; i <= 5; i++ {
		//spaces
		for j := 1; j <= i-1; j++ {
			fmt.Printf(" ")
		}
		//stars
		for j := 1; j <= odds; j++ {
			fmt.Printf("*")
		}
		odds -= 2
		fmt.Println()
	}
	fmt.Println()
	odds = 1
	for i := 1; i <= 10; i++ {
		if i <= 5 {
			//spaces
			for j := 1; j <= 5-i; j++ {
				fmt.Printf(" ")
			}
			//stars
			for j := 1; j <= odds; j++ {
				fmt.Printf("*")
			}
			if i != 5 {
				odds += 2
			}

			fmt.Println()
		} else {
			//spaces
			for j := 1; j <= i-6; j++ {
				fmt.Printf(" ")
			}
			//stars
			for j := 1; j <= odds; j++ {
				fmt.Printf("*")
			}
			odds -= 2
			fmt.Println()
		}
	}

	for i := 1; i <= 9; i++ {
		if i <= 5 {
			for j := 1; j <= i; j++ {
				fmt.Print("*")
			}
			fmt.Println()
		} else {
			for j := 10 - i; j >= 1; j-- {
				fmt.Print("*")
			}
			fmt.Println()
		}
	}
	fmt.Println()

	val := 1
	for i := 1; i <= 5; i++ {
		if i%2 == 0 {
			val = 0
		}
		for j := 1; j <= i; j++ {
			fmt.Printf("%v ", val)
			if val == 1 {
				val = 0
			} else {
				val = 1
			}
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 1; i <= 4; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", j)
		}
		for j := 1; j <= 2*(4-i); j++ {
			fmt.Print(" ")
		}
		for j := i; j >= 1; j-- {
			fmt.Printf("%v", j)
		}

		fmt.Println()
	}
	fmt.Println()
	val = 1
	for i := 1; i <= 5; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v ", val)
			val += 1
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i <= 4; i++ {
		for j := 0; j <= i; j++ {
			fmt.Printf("%c ", byte('A'+j))
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i <= 4; i++ {
		for j := 0; j <= 4-i; j++ {
			fmt.Printf("%c ", byte('A'+j))
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i <= 4; i++ {
		for j := 0; j <= i; j++ {
			fmt.Printf("%c ", byte('A'+i))
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i < 4; i++ {
		for j := 0; j <= 4-i; j++ {
			fmt.Print(" ")
		}
		ch := 'A'
		for j := 0; j <= 2*i; j++ {
			fmt.Printf("%c", ch)
			if j < i {
				ch++
			} else {
				ch--
			}
		}

		for j := 0; j <= 4-i; j++ {
			fmt.Print(" ")
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i <= 4; i++ {
		for j := i; j >= 0; j-- {
			fmt.Printf("%c ", byte('A'+4-j))
		}
		fmt.Println()
	}
	fmt.Println()
	evens := 0
	for i := 0; i <= 9; i++ {
		if i <= 4 {
			for j := 4; j >= i; j-- {
				fmt.Printf("*")
			}

			for j := 0; j < evens; j++ {
				fmt.Printf(" ")
			}
			for j := 4; j >= i; j-- {
				fmt.Printf("*")
			}
			if i != 4 {
				evens += 2
			}

			fmt.Println()
		} else {
			ii := i - 5
			for j := 0; j <= ii; j++ {
				fmt.Printf("*")
			}
			for j := 0; j < evens; j++ {
				fmt.Printf(" ")
			}
			for j := 0; j <= ii; j++ {
				fmt.Printf("*")
			}
			evens -= 2
			fmt.Println()

		}

	}
	fmt.Println()
	evens = 8
	for i := 0; i <= 9; i++ {
		if i <= 4 {
			for j := 0; j <= i; j++ {
				fmt.Printf("*")
			}

			for j := 0; j < evens; j++ {
				fmt.Printf(" ")
			}
			for j := 0; j <= i; j++ {
				fmt.Printf("*")
			}
			if i != 4 {
				evens -= 2
			} else {
				evens += 2
			}

			fmt.Println()
		} else {
			ii := i - 5
			for j := 4; j > ii; j-- {
				fmt.Printf("*")
			}
			for j := 0; j < evens; j++ {
				fmt.Printf(" ")
			}
			for j := 4; j > ii; j-- {
				fmt.Printf("*")
			}
			evens += 2
			fmt.Println()

		}

	}
	fmt.Println()

	for i := 0; i <= 4; i++ {
		for j := 0; j <= 4; j++ {
			if i == 0 || j == 0 || j == 4 || i == 4 {
				fmt.Printf("*")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()

	for i := 0; i < 2*4-1; i++ {
		for j := 0; j < 2*4-1; j++ {
			top := i
			left := j
			right := (2*4 - 2) - j
			down := (2*4 - 2) - i

			mini := (4 - min(min(top, down), min(left, right)))
			fmt.Print(mini)
		}
		fmt.Println()
	}

}

/*

*****
*****
*****
*****
*****

*
**
***
****
*****

1
12
123
1234
12345

1
22
333
4444
55555

*****
****
***
**
*

12345
1234
123
12
1

    *
   ***
  *****
 *******
*********

*********
 *******
  *****
   ***
    *

    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *
*
**
***
****
*****
****
***
**
*

1
0 1
0 1 0
0 1 0 1
0 1 0 1 0

1      1
12    21
123  321
12344321

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

A
A B
A B C
A B C D
A B C D E

A B C D E
A B C D
A B C
A B
A

A
B B
C C C
D D D D
E E E E E

     A
    ABA
   ABCBA
  ABCDCBA

E
D E
C D E
B C D E
A B C D E

**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *


*****
*   *
*   *
*   *
*****

4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/
