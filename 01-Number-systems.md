# Number systems
We have glanced at the decimal and binary systems yesterday. There are two more useful representations that use base 8 and base 16 and are called **octal** and **hexadecimal** number systems respectively.

**Important note:** Base is also called *radix*.
### Example: Octal System

Consider the octal number:

$$
(753)_8
$$

Its positional decomposition is:

$$
(753)_8 = 7 \times 8^2 + 5 \times 8^1 + 3 \times 8^0
$$

$$
= 7 \times 64 + 5 \times 8 + 3 \times 1
$$

$$
= 448 + 40 + 3
$$

$$
= 491_{10}
$$

Therefore,

$$
(753)_8 = (491)_{10}
$$

### Example: Hexadecimal System

Consider the hexadecimal number:

$$
(3A5)_{16}
$$

Here, the hexadecimal digit \(A\) represents the decimal value \(10\).

$$
\begin{array}{l}
(3A5)_{16} = 3 \times 16^2 + 10 \times 16^1 + 5 \times 16^0 \\
= 3 \times 256 + 10 \times 16 + 5 \times 1 \\
= 768 + 160 + 5 \\
= 933_{10}
\end{array}
$$

Therefore,

$$
(3A5)_{16} = (933)_{10}
$$

## Binary number system with fractional parts
Similar to the usual decimal system we can also represent fractional parts in binary system. The representation now becomes

$$
B = b_{n-1}b_{n-2}\cdots b_1b_0 . b_{-1}b_{-2}\cdots b_{-m}
$$

this represents

$$
D = \sum_{i=~-m}^{n-1} b_i 2^i
$$

Examples

$$
\begin{array}{l}
101011_2 \longleftrightarrow 1 \times 2^5 + 0 \times 2^4 + 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 = 43 \\
(101011)_2 = (43)_{10} \\
.0101_2 \longleftrightarrow 0 \times 2^{-1} + 1 \times 2^{-2} + 0 \times 2^{-3} + 1 \times 2^{-4} = .3125 \\
(.0101)_2 = (.3125)_{10} \\
101.11_2 \longleftrightarrow 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0 + 1 \times 2^{-1} + 1 \times 2^{-2} = 5.75 \\
(101.11)_2 = (5.75)_{10}
\end{array}
$$

Can you now convert binary numbers to decimal numbers?

## Decimal to binary conversion
Consider the integer and fractional parts separately.

- Take the integer part and repeatedly divide it by 2 until you get a zero.
    - Keep on dividing the quotient by 2.
    - Write down the obtained remainders in a sequence.
    - Stop when your quotient becomes a zero.
    - Write down the sequence of remainders in the **reverse order**.
- Take the fractional part and repeatedly multiply by 2.
    - Keep on multiplying the fractional parts by 2.
    - Writing the integer parts that you get in a sequence.
    - Discard the integer part and repeat the process on fractional part.
- Write integer part then a dot and then the fractional part.

### Examples

Let us represent 200 in binary.

$$
\begin{array}{lll}
quotient & dividend & remainder \\
\hline
2 & 200 & 0\\
2 & 100 & 0\\
2 & 50  & 0\\
2 & 25  & 1\\
2 & 12  & 0\\
2 & 6   & 0\\
2 & 3   & 1\\
2 & 1   & 1\\
2 & 0   & Stop
\end{array}
200_{10}​=11001000_2​
$$

*Notice the reverse order*

Let us consider .634 to see how to handle fractional parts.

```
.634 x 2 = 1.268
.268 x 2 = 0.536
.536 x 2 = 1.072
.072 x 2 = 0.144
.144 x 2 = 0.288
```

$$
(.634)_{10} = (.10100...)_2
$$

To put both of these together, let us convert 12.25 to binary

$$
\begin{array}{ll}
(12)_{10} & = (1100)_2 \\
(.25)_{10}  & = (.01)_2 \\
(12.25)_{10} & = (1100.01)_2
\end{array}
$$

## Hexadecimal number system
This is a compact way of representing binary numbers. We assign a symbol to four bits put together as below:

$$
\begin{array}{ccl}
0000 & \longleftrightarrow & 0 \\
0001 & \longleftrightarrow & 1 \\
0010 & \longleftrightarrow & 2 \\
0011 & \longleftrightarrow & 3 \\
0100 & \longleftrightarrow & 4 \\
0101 & \longleftrightarrow & 5 \\
0110 & \longleftrightarrow & 6 \\
0111 & \longleftrightarrow & 7 \\
1000 & \longleftrightarrow & 8 \\
1001 & \longleftrightarrow & 9 \\
1010 & \longleftrightarrow & A \\
1011 & \longleftrightarrow & B \\
1100 & \longleftrightarrow & C \\
1101 & \longleftrightarrow & D \\
1110 & \longleftrightarrow & E \\
1111 & \longleftrightarrow & F
\end{array}
$$

### Converting from binary to hexadecimal

We treat the integer and fractional parts separately as before and put them together later.
- Process the integer part from right to left, replace each consecutive group of four bits by its hexadecimal equivalent.
    - Add zeroes at the beginning if needed (called leading zeroes).
- Process the fractional part from left to right, replace each consecutive group of four bits by its hexadecimal equivalent.
    - Add zeroes at the end if needed (called trailing zeroes).

Examples

$$
\begin{array}{rcl}
(1011\ 0100\ 0011)_2 & = & (B43)_{16} \\
\end{array}
$$

Adding leading zeroes

$$
\begin{array}{rcrcl}
(10\ 1010\ 0001)_2 & = & (0010\ 1010\ 0001)_2 & = & (2A1)_{16} \\
\end{array}
$$

Adding both leading and trailing zeroes

$$
\begin{array}{rcrcl}
(.1000\ 010)_2 & = & (.1000\ 0100)_2 & = & (.84)_{16} \\
\end{array}
$$

Adding both leading and trailing zeroes

$$
\begin{array}{rcrcl}
(101.0101\ 111)_2 & = & (0101.0101\ 1110)_2 & = & (5.5E)_{16}
\end{array}
$$

### Converting from hexadecimal to binary
Just replace each hexadecimal digit with the four bit binary equivalent.

$$
\begin{array}{rcl}
(3A5)_{16} & = & (0011\ 1010\ 0101)_2 \\
(12.3D)_{16} & = & (0001\ 0010\ .\ 0011\ 1101)_2 \\
(1.8)_{16} & = & (0001\ .\ 1000)_2
\end{array}
$$

#### Question
How do you convert from binary to octal and vice versa? Can you group three bits together like we did for hexadecimal numbers?

## Signed and unsigned integers
Till now we seen only non-negative integers. We will also see different representations of negative integers.

### Unsigned binary numbers
An n-bit binary number

$$
B = b_{n-1} b_{n-2} \cdots b_2 b_1 b_0
$$

How many possible n-bit binary numbers can we have? It is $2\times 2\times 2\times\cdots\times 2$ repeated $n$ times. Which is $2^n$. We can represent numbers from $0$ to $2^n-1$.

For $n=3$ the numbers we can represent are $000$, $001$,$010$, $011$, $100$, $101$, $110$, $111$. 

As we increase the value of the number of bits $n$ we can represent more numbers.

$$
\begin{array}{lcl}
n = 8 & \rightarrow & 0\text{ to } 2^8-1~(255) \\
n = 16 & \rightarrow & 0\text{ to } 2^{16}-1~(65535) \\
n = 32 & \rightarrow & 0\text{ to } 2^{32}-1~(4294967295)
\end{array}
$$

### Signed binary numbers
When we also need to represent negative integers then there are three main ways.

- Sign-magnitude representation.
- One's complement representation.
- Two's complement representation.

#### Sign magnitude representation
Use one bit to represent the sign. This bit is generally the most significant bit (MSB). Use the rest of the bits to represent the magnitude of the number.

$$
\begin{aligned}
\text{positive} \rightarrow 0 \\
\text{negative} \rightarrow 1
\end{aligned}
$$

For an n-bit number

$$
\begin{array}{c}
\text{Use }b_{n-1}\text{ for the sign} \\
\text{Use }b_{n-2}\cdots b_{1}b_0\text{ for the magnitude}
\end{array}
$$

One problem with this is that there is a negative and a positive zero.

$$
\begin{aligned}
+0 \rightarrow 0~00\cdots 00 \\
-0 \rightarrow 1~00\cdots 00 \\
\end{aligned}
$$

What is the range of numbers that can be represented in this notation? It is $-2^{n-1}$ to $2^{n-1}$.

#### One’s complement representation
Basic idea:
- Positive numbers are represented exactly as in sign-magnitude form.
- Negative numbers are represented in 1’s complement form.

How to compute the 1’s complement of a number?
- Flip every bit of the number ($1$ to $0$ and $0$ to $1$). The actual term is taking the complement.
- The MSB will be the sign of the number. For positive numbers $0$ and for negative numbers $1$.

| Positive Number | 3-bit One's Complement | Negative Number | 3-bit One's Complement |
|-----------------|------------------------|-----------------|------------------------|
| +0 | `000` | -0 | `111` |
| +1 | `001` | -1 | `110` |
| +2 | `010` | -2 | `101` |
| +3 | `011` | -3 | `100` |

Notice that the range of the numbers is the same as that for sign-magnitude representation. We also have the same problem of having two different representations for zero.

#### Two's complement representation
Basic idea:
- Positive numbers are represented exactly as in sign-magnitude form.
- Negative numbers are represented in two’s complement form.

How to compute the two’s complement of a number?
- Complement every bit of the number (1 to 0 and 0 to 1), and then add one to the resulting
number.
- MSB will indicate the sign of the number.

Representation of 3-bit numbers in two's complement.

| Positive Number | 3-bit Two's Complement | Negative Number | 3-bit Two's Complement |
|-----------------|------------------------|-----------------|------------------------|
| +0 | `000` | -1 | `111` |
| +1 | `001` | -2 | `110` |
| +2 | `010` | -3 | `101` |
| +3 | `011` | -4 | `100` |

For example, to get the representation of -3.
- First write $+3 = 011$.
- Then Complement $011 \rightarrow 100$.
- Now add a 1 to get $100+1=101$.

Advantages
- Range is from $-2^{n-1}$ to $2^{n-1}-1$
- Only one representation of zero.
- Subtraction and addition can be done using the same operations.

**Note:** Most modern computers use this notation.



