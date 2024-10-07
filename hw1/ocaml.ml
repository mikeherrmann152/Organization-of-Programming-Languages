(* OCaml from rosettacode*)

let combinations m n = (* beginning of the definition of the combinations function *)
  let rec c = function (* creates a recursive function c *)
    | (0,_) -> [[]]    (* checks to see if the first number in the first element is a zero *)
    | (_,0) -> []      (* checks to see if the second number in the first element is a zero *)
    | (p,q) -> List.append
               (List.map (List.cons (n-q)) (c (p-1, q-1))) (* creats a mapping for the first elements so there is no repeated elements in the listing *)
               (c (p , q-1))
  in c (m , n)
 
 
let () =
  let rec print_list = function (* funciton to print out all of the combinations *)
    | [] -> print_newline ()
    | hd :: tl -> print_int hd ; print_string " "; print_list tl      
  in List.iter print_list (combinations 3 5)
 
