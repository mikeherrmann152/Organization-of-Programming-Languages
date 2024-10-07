-- ada code from rosettacode

with Ada.Text_IO;  use Ada.Text_IO;


-- declaring the functions we are going to use later in the program
procedure Test_Combinations is
   generic
      type Integers is range <>;
   -- creating a package of functions to be done one right after the other
   package Combinations is
      type Combination is array (Positive range <>) of Integers;
      procedure First (X : in out Combination);
      procedure Next (X : in out Combination); 
      procedure Put (X : Combination);
   end Combinations;
   
 -- beginning of the package
   package body Combinations is
      procedure First (X : in out Combination) is
      begin -- stating the First function
         X (1) := Integers'First; -- setting the first value in all the pairs equal to 1
         for I in 2..X'Last loop  -- begings a loop to loop through all the next values
            X (I) := X (I - 1) + 1; -- sets the values in this loop
         end loop; -- ends the loop
      end First; -- ends the first procudure
      procedure Next (X : in out Combination) is -- beiginning of the Next procedure
      begin
         for I in reverse X'Range loop -- for loop that goes through the loop in the reverse order
            if X (I) < Integers'Val (Integers'Pos (Integers'Last) - X'Last + I) then
               X (I) := X (I) + 1;
               for J in I + 1..X'Last loop
                  X (J) := X (J - 1) + 1;
               end loop; -- ends the loop
               return;
            end if; -- ends the if
         end loop; -- ends the loop
         raise Constraint_Error;
      end Next; -- end of the Next procedure
      procedure Put (X : Combination) is -- beginning of the Put procedure
      begin
         for I in X'Range loop
            Put (Integers'Image (X (I)));
         end loop; -- ends the for loop
      end Put; -- ends the Put procedure
   end Combinations; -- ends the combination package
 
   type Five is range 0..4;
   package Fives is new Combinations (Five); -- sets the combinations the pagacke got and puts into a combination type
   use Fives;
 
   X : Combination (1..3);
begin
   First (X); -- runs the First procedure with X as the parameter
   loop -- beginning of a loop
      Put (X); New_Line; -- runs the Put prcedure with X as the parameter
      Next (X); -- runs the Next procedure with X as the parameter
   end loop; -- ends the loop
exception
   when Constraint_Error => -- in case of an error in the program
      null;
end Test_Combinations; -- ends the program

