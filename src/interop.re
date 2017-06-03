Js.log "this is reason";
let x = [%bs.raw {| 'here is a string from javascript' |}];
Js.log (x ^ " back in reason land"); /* ^ is the operator for string concat */

let y = [%bs.raw {| 'something' |}];
Js.log ("a string" ^ y, 10 + y);
/* danger!! ocaml won't stop you from using y as 2 totally different types */

let x: string = [%bs.raw {| 'well-typed' |}];
Js.log (x ^ " back in reason land");
/* ocaml will error out if you try to use x as anything other than a string */


let jsCalculate: array int => int => int = [%bs.raw {|
 function (numbers, scaleFactor) {
   var result = 0;
   numbers.forEach(number => {
     result += number;
   });
   return result * scaleFactor;
 }
|}];
let calculate numbers scaleFactor =>
  jsCalculate (Array.of_list numbers) scaleFactor;
Js.log (calculate [1,2,3] 10); /* -> 60 */
