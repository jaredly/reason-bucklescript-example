external pi: float = "Math.PI" [@@bs.val];
let tau = pi *. 2.0;
external alert: string => unit = "alert" [@@bs.val];
alert "hello";

type canvas;
type context;
/* we're leaving these types abstract, because we won't
 * be using them directly anywhere */
external getContext: canvas => string => context = "" [@@bs.send];
let myCanvas: canvas = [%bs.raw {| document.getElementById("mycanvas") |}];
let ctx = getContext myCanvas "2d";

external fillRect: context => float => float => float => float => unit = "" [@@bs.send];
fillRect ctx 0.0 0.0 100.0 100.0;
