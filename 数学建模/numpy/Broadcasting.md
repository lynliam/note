# Broadcasting

## General Broadcasting Rules

1. they are equal, or
2. one of them is 1.

## `Broadcastable arrays`

![A 1-d array with shape (3) is stretched to match the 2-d array of shape (4, 3) it is being added to, and the result is a 2-d array of shape (4, 3).](Broadcasting.assets/broadcasting_2.png)

![A huge cross over the 2-d array of shape (4, 3) and the 1-d array of shape (4) shows that they can not be broadcast due to mismatch of shapes and thus produce no result.](Broadcasting.assets/broadcasting_3.png)

![A 2-d array of shape (4, 1) and a 1-d array of shape (3) are stretched to match their shapes and produce a resultant array of shape (4, 3).](Broadcasting.assets/broadcasting_4.png)