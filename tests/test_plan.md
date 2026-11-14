Test case 1:

  Input: 5 + - + + - x
  
  Ended on 1/5 capacity, not full, as expected
  
  LED did not light at any point, as expected
  
  Logs recorded the states to be 1/5 not full, 0/5 not full, 1/5 not full, 2/5 not full, 1/5 not full,    as expected.
  
  Application ended after x was input, as expected.





Test case 2:

  Input: 0 1 + - + Q

  The capacity of 0 was rejected, as expected
  
  Ended on 1/1 capacity, full, as expected
  
  LED lit up only when the room was full (1/1), as expected
  
  Logs recorded the states to be 1/1 full, 0/1 not gull, 1/1 full,    as expected
  
  Application ended after Q was input, as expected





Test case 3:

  Input: 8 + + + + - - + + + - - + + + + + + - X
  
  Ended on 7/8 capacity, not full, as expected
  
  LED turned on only when the room was full (8/8), as expected
  
  Logs recorded the states as 1/8 not full, 2/8 not full, 3/8 not full, 4/8 not full, 3/8 not full, 2/8 not full,
  
  3/8 not full, 4/8 not full, 5/8 not full, 4/8 not full, 3/8 not full, 4/8 not full, 5/8 not full, 6/8 not full,
  
  7/8 not full, 8/8 full, 8/8 full, 7/8 not full,    as expected
  
  The last entry command failed because the room was already full and a corresponding message was printed and logged, as expected
  
  Application ended after X was input, as expected





Test case 4:

  Input: 3 - + + - + + - + x
  
  Ended on 3/3 capacity, full, as ecpected
  
  LED lit up only at the end when the room was full (3/3), as expected
  
  Logs recorded the states as 0/3 not full, 1/3 not full, 2/3 not full, 1/3 not full, 2/3 not full, 3/3 full,
  
  2/3 not full, 3/3 full,   as expected
  
  First command (exit) failed because the room was already empty, as expected
  
  Application ended after x was input, as expected





Test case 5:

  Input: -4 -3 4 + + + + - - + - - + + - x
  
  Ended on 1/4 capacity, not full, as expected
  
  LED lit up only when the room was full (4/4), as expected
  
  Logs recorded the states as 1/4 not full, 2/4 not full, 3/4 not full, 4/4 full, 3/4 not full, 2/4 not full,
  
  3/4 not full, 2/4 not full, 1/4 not full, 2/4 not full, 3/4 not full, 1/4 not full,    as expected
  
  Application ended after x was input, as expected





Test case 6:

  Input: 2 + + + - + + - + q
  
  Ended on 2/2 capacity, full, as expected
  
  LED lit up only while the room was full, as expected
  
  Logs recorded the states as 1/2 not full, 2/2 not full, 2/2 not full, 1/2 not full, 2/2 not full, 2/2 not full,
  
  1/2 not full, 2/2 not full,   as expected
  
  Commands 3 and 6 (enter) failed because the room was already full, as expeected

  Application ended after q was input, as expected
